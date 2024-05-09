# Shortcut for pre-run conditions

import numpy as np
import pyDEW
import os
from thermoengine import model
from copy import deepcopy
import pandas as pd
import linecache
from scipy.interpolate import LinearNDInterpolator
from timeit import default_timer as timer
import warnings


#### CREATE NEW DEW SYSTEM ####

# pyDEW flags up a few things when the system is created - this counteracts it
warnings.simplefilter(action='ignore', category=FutureWarning)
pd.options.mode.chained_assignment = None

# These are the additional functions which we need to work with pyDEW inputs/outputs
import pyDEW_functions as pDF

if not os.path.exists("./data"):
    os.makedirs("./data")

# Adjust here the basis species in the DEW system - deepcopy to avoid mucking up defaults
defaultBasisSpecies = pyDEW.defaultsystem.basis_species_names
basisSpecies = deepcopy(defaultBasisSpecies)

defaultOtherSpecies = pyDEW.defaultsystem.other_species_names
otherSpecies = deepcopy(defaultOtherSpecies)

# Add missing Mg complex to the other species
otherSpecies.append('MG(OH)2(AQ)')

# Switch basis species - replace CO2(AQ) with CO3-2 directly to avoid pyDEW issues
basisSpecies[basisSpecies.index('CO2(AQ)')] = 'CO3-2'

# Create DEW system
dew_system = pyDEW.System(basis_species=basisSpecies, other_species=otherSpecies)

# pyDEW minutia - to match Guillaume's setups
# Suppress H2CO3(AQ)
nxmods = [['H2CO3(AQ)', 0, -1, 0]]


#### FLUID INTERPOLATION FUNCTION ####

# New function here to find a fluid from the database which falls in our 3D space.
def createHybridFluid(proportions, T, P, database='EQ3_pickups_GS.xlsx',
                      sheetNames=['DMM','MORB','Sediments']):
    """
    Function to create a hybrid linearly interpolated fluid from fluid endmember compositions.
    Fluid assumed to be linearly proportional of endmembers.

    Inputs
    ------
    proportions : list of floats
        proportions each fluid endmember contributes to the final fluid
    T : float
        temperature for interpolation, in K
    P : float
        pressure for interpolation, in bars
    database : string
        xlsx database with fluid endmember compositions. Default is 'EQ3_pickups_GS.xlsx'
    sheetNames : list of strings
        names of sheets in xlsx database corresponding to fluid endmembers. Default is
        ['DMM','MORB','Sediments'], corresponding to 'EQ3_pickups_GS.xlsx'

    Outputs
    -------
    exportDict : dictionary
        dictionary describing elemental composition of hybridised fluid
    exportfO2 : float
        float describing hybridised oxygen fugacity
    """

    assert len(proportions) == len(sheetNames), 'check same item proportions and database'

    for i in range(len(proportions)):

        # To store our new fluid
        if i == 0:
            molalitiesDict = {}
        key = sheetNames[i]
        LithData = pd.read_excel(database, sheet_name=sheetNames[i])
        proportion = proportions[i]/np.sum(proportions)

        # Find the species comprising the fluid
        columnHeaders = list(LithData.columns)
        speciesHeaders = columnHeaders[2:]

        # Extract pressures and temperatures
        dataPressures = LithData['P (kbar)'].values
        dataTemperatures = LithData['T (degC)'].values

        # This iterates over all species and linearly interpolates across them based on the
        # molalities pickup sheet
        for j in range(len(speciesHeaders)):
            speciesData = LithData[speciesHeaders[j]]

            # Makes sure that the species aren't all constant, which makes the interpolation wacky
            if speciesData.tolist() == [speciesData.tolist()[0]]*len(speciesData):
                if i == 0:
                    molalitiesDict[speciesHeaders[j]] = speciesData[0] * proportion
                else:
                    molalitiesDict[speciesHeaders[j]] = molalitiesDict[speciesHeaders[j]] + (speciesData[0] * proportion)

            # Otherwise we set up the interpolator for the species given pressure and temperature
            else:
                interp = LinearNDInterpolator(list(zip(dataTemperatures.tolist(), dataPressures.tolist())), speciesData.tolist())

                # Reconvert back to original units here
                interpMolal = interp(T-273.15, P/1000)
                if i == 0:
                    molalitiesDict[speciesHeaders[j]] = float(interpMolal) * proportion
                elif speciesHeaders[j] not in molalitiesDict.keys():
                    molalitiesDict[speciesHeaders[j]] = float(interpMolal) * proportion
                else:
                    molalitiesDict[speciesHeaders[j]] = molalitiesDict[speciesHeaders[j]] + (float(interpMolal) * proportion)

    exportDict = {'NA+': molalitiesDict['NA'],
                  'K+' : molalitiesDict['K'],
                  'CA+2': molalitiesDict['CA'],
                  'MG+2': molalitiesDict['MG'],
                  'AL+3': molalitiesDict['AL'],
                  'H4SIO4(AQ)': molalitiesDict['SI'],
                  'CO3-2' : molalitiesDict['C'],
                  'CL-': molalitiesDict['CL'],
                  'FE+2': molalitiesDict['FE']}
    exportfO2 = molalitiesDict['fO2']
    return exportDict, exportfO2


#### DECOMPRESSION RELAY ####

def decompressionRelay(startingColumn, startingMolalities, startingfO2, system, startingFRRatio=1.0, terminalFRRatio=0.1,
                       timesteps=10, exportPath='data', outputToRead='working/output', tabToRead='working/tab',
                       FRRatioOption0=None, FRRatioOption1=None):
    """
    Decompression relay as a function of time. This models a column of rock getting flushed with a fluid periodically.
    Definitions:
    - initial : before the reaction at each stage
    - final : after the reaction at each stage
    - 1 kg : relative to 1 kg of fluid (which is the quantity used by EQ3/6 in pyDEW)

    INPUTS
    ------
    startingColumn : pandas.DataFrame
        pandas DataFrame with each column a different mineral concentration (moles), with two additional columns
        'Pressure (bars)' and 'Temperature (K)'
    startingMolalities : dictionary
        dictionary of elemental molalities in log molal describing the composition of the flushing fluid
    system : pyDEW.System object
        pyDEW.System for calculations
    startingFRRatio : float
        starting fluid-rock ratio (F/R) at the base of the column
    terminalFRRatio : float
        fluid-rock ratio (F/R) to terminate reactions
    timesteps : integer
        number of times to flush our solid with the fluid
    exportPath : string
        path to export xlsx file
    outputToRead : string
        path to pyDEW.Reaction output file
    tabToRead : string
        path to pyDEW.Reaction tab file
    FRRatioOption0 : None, 'fluid', 'fixedStart'
        first batch of options for fluid-rock ratio
    FRRatioOption1 : float
        fluid-rock ratio (dependent on FRRatioOption0)

    OUTPUTS
    -------
    xlsx file
        Excel file with solid, element, and fluid speciation data

    """

    start = timer()
    t = 0

    # The headers for our output file may contain solid-solution minerals and their endmembers
    # We need to set the headers up now so we can allow for the mineral endmembers and some other options
    acceptableHeaders = [i.props['phase_name'] for i in system.minerals]
    acceptableHeaders.extend(['DIOPSIDE(CPX)', 'JADEITE(CPX)', 'HEDENBERGITE(CPX)', 'KFELDSPAR(KFSP)', 'ALBITE(KFSP)'])
    acceptableHeaders.extend([i + '_volPER' for i in acceptableHeaders])
    acceptableHeaders.extend(['Pressure (bars)', 'Temperature (K)', 'Time', 'max log zi', 'Error flag'])

    totalCalculations = 0
    totalPasses = 0
    totalErrors = 0

    ##### TIME LOOP #####
    print('Time loop started')
    while t < timesteps:
        if t == 0:
            workingColumn = startingColumn
        else:
            workingColumn = lastColumn

        # These lists are for keeping track of the physical properties of the system
        # F/R before and after each reaction
        initialFRRatioList = []
        finalFRRatioList = []

        # Mass of the solid/fluid before/after the reaction
        initialSolidMassList = []
        initialFluidMassList = []
        finalFluidMassList = []
        finalSolidMassList = []

        # Mass of the solid/fluid before/after the reaction, relative to 1 kg initial fluid
        initialSolidMass1kgList = []
        finalFluidMass1kgList = []
        finalSolidMass1kgList = []

        # Volume and density of the solid before/after the reaction
        initialSolidVolumeList = []
        initialSolidVolume1kgList = []
        initialSolidDensityList = []
        finalSolidVolumeList = []
        finalSolidVolume1kgList = []
        finalSolidDensityList = []

        # fO2
        oxygenFugacityList = []

        # To keep track of errors. At n = 0, this is False
        errorFlag = False
        FRFlag = False
        calculations = 0
        passes = 0
        errors = 0

        ##### DECOMPRESSION RELAY #####
        for n in range(len(startingColumn)):

            #### ESTABLISH REACTANT CONDITIONS ####
            workingParameters = workingColumn.iloc[n]
            workingReactants = pDF.DFtoReactant(workingParameters, system)
            workingT = workingParameters['Temperature (K)']
            workingP = workingParameters['Pressure (bars)']

            #### MODIFY FLUID-ROCK RATIO OPTIONS ####
            # Fluid-rock ratio (F/R or FR) is the mass of fluid divided by the mass of reactants
            # The initial solid mass is scaled to 1 kg fluid given a starting F/R - the scaling factor is 'solidModulate'
            # e.g., if 1 kg of rock interacts with 0.5 kg of fluid, then the scaling is 2x and the calculation is 2 kg of rock with
            # 1 kg of fluid. Afterwards, we may end up with 2.1 kg of resultant rock and 0.9 kg fluid. We correct this
            # by applying the same factor to end up with 1.05 kg of resultant rock and 0.45 kg fluid.

            # startingFRRatio : F/R at n=0 (or at [t=0, n=0] when FRRatioOption0 == 'fixedStart')
            # initialFRRatio : F/R before reaction
            # solidModulate : the ratio of fluid mass to 1 kg, used to determine 'true' mass of solid

            initialReactantMass = pDF.findReactantMass(workingReactants, system)
            initialReactantVolume = pDF.findReactantVolume(workingReactants, system, workingP, workingT)
            initialReactantDensity = pDF.findReactantDensity(workingReactants, system, workingP, workingT)

            # 'None' : we want to keep the F/R the same at every step
            if FRRatioOption0 == None:
                initialFRRatio = startingFRRatio
                initialFluidMass = initialReactantMass * initialFRRatio
            else:
                if n == 0:
                    # 'fluid' : we want to change the F/R during the chain of reactions, but keep the F/R at n=0 the same throughout
                    if FRRatioOption0 == 'fluid':
                        initialFRRatio = startingFRRatio
                        initialFluidMass = initialReactantMass * initialFRRatio
                    # 'fixedStart' : we want to change the F/R during the chain of reactions but keep the mass of fluid at n=0 the same
                    # This fluid mass is determined from the starting F/R
                    elif FRRatioOption0 == 'fixedStart':
                        if t == 0:
                            initialFluidMass = initialReactantMass * startingFRRatio
                            fixedInitialFluidMass = initialReactantMass * startingFRRatio
                            initialFRRatio = startingFRRatio
                        else:
                            initialFluidMass = fixedInitialFluidMass
                            initialFRRatio = fixedInitialFluidMass / initialReactantMass
                # If n > 0, then initial fluid mass decreases by a ratio determined by the mass change recorded via each reaction
                else:
                    if errorFlag == False:
                        initialFluidMass = initialFluidMass * pDF.findFluidMassChange(tabToRead, index=maxLogZiOutputIndex)
                    initialFRRatio = initialFluidMass / initialReactantMass
            workingReactants1kg = pDF.reactantToFR(workingReactants, initialFRRatio, system)
            initialReactant1kgMass = pDF.findReactantMass(workingReactants1kg, system)
            initialReactant1kgVolume = pDF.findReactantVolume(workingReactants1kg, system, workingP, workingT)
            solidModulate = initialFluidMass / 1000.0

            # Check for reaction completion
            initialReactant1kgMoles = np.sum([j['moles'] for j in workingReactants1kg])

            # These lists are to store the initial physical properties of the system
            initialFRRatioList.append(initialFRRatio)
            initialSolidMassList.append(initialReactantMass)
            initialSolidVolumeList.append(initialReactantVolume)
            initialSolidDensityList.append(initialReactantDensity)
            initialFluidMassList.append(initialFluidMass)
            initialSolidMass1kgList.append(initialReactant1kgMass)
            initialSolidVolume1kgList.append(initialReactant1kgVolume)

            #### ESTABLISH FLUID CONDITIONS ####
            # If first, then use the slab fluid. Else use the fluid from the previous calculation
            if n == 0:
                workingFluid = pyDEW.Fluid(system, workingT, workingP, molalities=startingMolalities, fO2=startingfO2,
                                           uebal='H+', uacion='CL-', nxmods=nxmods, aH2O_mode='molfraction')
            else:
                # If no mineral product was found previously, use the previous lastElements/workingfO2 (i.e., errorFlag==True)
                # Else, update with the values from the calculation prior to the last one (i.e., errorlag==False)
                if errorFlag == False:
                    lastElements = dewReaction.elements.iloc[tryLogZi]
                    workingfO2 = dewReaction.fO2[tryLogZi]

                molalities = {'NA+': lastElements['Na'],
                              'CA+2': lastElements['Ca'],
                              'MG+2': lastElements['Mg'],
                              'AL+3': lastElements['Al'],
                              'H4SIO4(AQ)': lastElements['Si'],
                              'CO3-2' : lastElements['C'],
                              'CL-': lastElements['Cl'],
                              'FE+2': lastElements['Fe']}
                for i in molalities:
                    if molalities[i] < -20:
                        molalities[i] = 0

                # pyDEW returns log molalities, whereas the inputs are in molalities
                molalities.update((i, 10**j) for i, j in molalities.items())
                workingFluid = pyDEW.Fluid(system, workingT, workingP, molalities=molalities, fO2=workingfO2,
                                           uebal='H+', uacion='CL-', nxmods=nxmods, aH2O_mode='molfraction')
            passFlag=False

            try:
                if initialFRRatio < terminalFRRatio:
                    print('Fluid-rock ratio below threshold at [n=' + str(n) +', t=' + str(t) + '], raising Error')
                    errorMessage = 'F/R threshold (' + str(terminalFRRatio) + ') achieved, using fluid/solid results from previous n/t'
                    passFlag=True
                    passes += 1
                    raise pyDEW.core.RunError('F/R too low')
                

                dewReaction = pyDEW.Reaction(workingFluid, workingT, workingP, workingReactants1kg,
                                             zimax=initialReactant1kgMoles, calculation_mode='titration')
                ### DEBUG ###
                if t == 2:
                    print(workingFluid.fO2)
                    print(dewReaction.fO2)
                    return

                # If the reaction goes ahead without issue, then perform the reaction with the given conditions
                if isinstance(dewReaction.minerals, pd.DataFrame) == False:
                    print('Mineral output at [n=' + str(n) +', t=' + str(t) + '] is not a pd.DataFrame, raising Error')
                    errorMessage = 'Error encountered, using fluid/solid results from previous n/t'
                    raise pyDEW.core.RunError('Output is not a pd.DataFrame')

                #### CREATE NEW DATAFRAMES FOR OUTPUT ####
                # Get the solids formed during this reaction (from 1 kg fluid)
                # This doesn't work if there is no solid product, which is why this is all nestled in a big try clause
                lastReactionDF = pDF.findSolidComposition(outputToRead, system, workingP, workingT)

                ########## ANNOYING SHIT HERE #########
                # If the last row of the fluid is all nans, then something has gone horribly wrong
                # We will find the first row which does not have all nans and use that as our final stage
                logZiList = dewReaction.elements.index.tolist()
                tryLogZi = -1  # This is the index of the final logZi in the logZiList - the index differs between pyDEW and the output files
                foundLastZi = False
                while foundLastZi == False:
                    logZiFluid = dewReaction.elements.iloc[tryLogZi]
                    # If the row is full of NaN, try the previous row
                    if logZiFluid.isnull().all():
                        print('Final fluid all NaNs; using a previous reaction progress')
                        tryLogZi -= 1
                    else:
                        foundLastZi = True

                # This is the maximum logZi if all NaN rows are removed
                maxLogZi = logZiList[tryLogZi]
                # Really annoyingly the values for log zi are different in the output and in pyDEW - this finds the new indices and nearest maxLogZi
                # We cannot use the exact logZi because of rounding differences
                logZiListOutput = list(lastReactionDF['log zi'].unique())
                maxLogZiOutput = min(logZiListOutput, key=lambda x:abs(x-maxLogZi))

                # This is the index for the maximum logZi in the output file
                maxLogZiOutputIndex = logZiListOutput.index(maxLogZiOutput)
                
                
                #### POST-REACTION PROCESSING ####

                # Get the dataframe representing the last solid (from 1 kg fluid)
                lastSolid1kg = lastReactionDF[lastReactionDF['log zi'] == maxLogZiOutput]
                lastSolid1kgHeaders = lastSolid1kg['phase/end-member'].tolist()
                lastSolid1kgValues = lastSolid1kg['moles'].tolist()

                # Because CPX has two different solid solutions, need to clarify the differences or pandas throws a fit
                if 'CLINOPYROXENE(SS)' in lastSolid1kgHeaders:
                    index = lastSolid1kgHeaders.index('CLINOPYROXENE(SS)')
                    lastSolid1kgHeaders[index+1] = 'DIOPSIDE(CPX)'
                    lastSolid1kgHeaders[index+2] = 'JADEITE(CPX)'
                    lastSolid1kgHeaders[index+3] = 'HEDENBERGITE(CPX)'

                # Same thing for k-spar
                if 'KFELDSPAR(SS)' in lastSolid1kgHeaders:
                    index = lastSolid1kgHeaders.index('KFELDSPAR(SS)')
                    lastSolid1kgHeaders[index+1] = 'KFELDSPAR(KFSP)'
                    lastSolid1kgHeaders[index+2] = 'ALBITE(KFSP)'

                #### FORMAT SOLID RELATIVE TO 1 KG FLUID ####
                # Create new dataframe and reactant object for our final reactant (from 1 kg fluid)
                lastSolid1kgDF = pd.DataFrame([lastSolid1kgValues])
                lastSolid1kgDF.columns = lastSolid1kgHeaders
                lastSolid1kgDF = lastSolid1kgDF[lastSolid1kgDF.columns.intersection(acceptableHeaders)]  # Remove mineral names with solid solution

                # There is an issue where dataframes are concated together all columns duplicate except one which is near-zero. This should fix this
                if len(lastSolid1kgDF.columns) != len(set(lastSolid1kgDF.columns)):
                    lastSolid1kgDF = lastSolid1kgDF.iloc[:, ~lastSolid1kgDF.columns.duplicated()]

                # Convert our pandas output into a reactant list of dictionaries
                lastSolid1kgReactant = pDF.DFtoReactant(lastSolid1kgDF.iloc[0], system)

                # Determine the physical properties of the reactant at the current PT relative to 1 kg fluid
                lastSolid1kgMass = pDF.findReactantMass(lastSolid1kgReactant, system)
                lastSolid1kgVolume = pDF.findReactantVolume(lastSolid1kgReactant, system, workingP, workingT)
                
                # Calculate volume percentages (new as of 01/05/2024)
                lastSolidVolPerDF = pDF.reactantToVolDF(lastSolid1kgReactant, system, workingP, workingT)

                # So far everything has been done relative to 1 kg of fluid. Here we need to recalculate the fluid and solid masses.
                # Get the final mass of fluid and solid, and other physical properties
                lastFluid1kgMass = 1000.0 * pDF.findFluidMassChange(tabToRead, index=maxLogZiOutputIndex)
                finalFRRatio = lastFluid1kgMass / lastSolid1kgMass
                finalFluidMass1kgList.append(lastFluid1kgMass)
                finalSolidMass1kgList.append(lastSolid1kgMass)
                finalSolidVolume1kgList.append(lastSolid1kgVolume)
                finalFRRatioList.append(finalFRRatio)
                oxygenFugacityList.append(dewReaction.fO2[tryLogZi])

                #### FORMAT SOLID RELATIVE TO INITIAL FLUID MASS (ADJUSTED) ####
                # Multiply the product solid values by the modulate value to get the true solid mass (i.e., for whatever amount of fluid there is
                # before correction to 1 kg for F/R). Then do the same as above for each corrected solid
                adjustedLastSolidReactant = []
                for j in lastSolid1kgReactant:
                    j['moles'] = j['moles'] * solidModulate
                    adjustedLastSolidReactant.append(j)
                adjustedLastSolidDF = pDF.reactantToDF(adjustedLastSolidReactant, system)
                adjustedLastSolidDF.reset_index().T.drop_duplicates().T
                adjustedLastFluidMass = lastFluid1kgMass * solidModulate

                # Determine the 'true' physical properties of the solid
                adjustedLastSolidMass = pDF.findReactantMass(adjustedLastSolidReactant, system)
                adjustedLastSolidVolume = pDF.findReactantVolume(adjustedLastSolidReactant, system, workingP, workingT)
                adjustedLastSolidDensity = pDF.findReactantDensity(adjustedLastSolidReactant, system, workingP, workingT)
                finalFluidMassList.append(adjustedLastFluidMass)
                finalSolidMassList.append(adjustedLastSolidMass)
                finalSolidVolumeList.append(adjustedLastSolidVolume)
                finalSolidDensityList.append(adjustedLastSolidDensity)

                #### FORMAT FLUID ####
                # Set up the information for the fluid of the last reaction
                lastReactionElementsHeaders = dewReaction.elements.columns
                lastReactionElements = dewReaction.elements.iloc[tryLogZi].tolist()
                lastReactionSpeciesHeaders = dewReaction.species_concs.columns
                lastReactionSpecies = dewReaction.species_concs.iloc[tryLogZi].tolist()

                # # Save the data for the next iteration in case it fails
                # backupSolid1kgDF = deepcopy(lastSolid1kgDF)
                # backupAdjustedSolidDF = deepcopy(adjustedLastSolidDF)
                # backupElements = deepcopy(lastReactionElements)
                # backupFluid = deepcopy(lastReactionSpecies)

                # Undo the errorFlag if it has been triggered
                errorFlag = False
                errorMessage = ''
                calculations += 1

            # If an error is identified, we propogate the composition of the previous fluid, and take the composition of the solid from
            # the previous time step
            except (KeyError, NameError, pyDEW.core.RunError):
                if passFlag:
                    passFlag = False
                else:
                    errors += 1
                if errorFlag == False:
                    print('Calculation at [n=' + str(n) +', t=' + str(t) + '] has failed: using fluid/solid results from previous n/t')
                maxLogZi = -999.0

                # Get the starting solid and use that as the output
                lastSolid1kgDF = pDF.reactantToDF(workingReactants1kg, system)
                adjustedLastSolidReactant = []
                for j in workingReactants1kg:
                    j['moles'] = j['moles'] * solidModulate
                    adjustedLastSolidReactant.append(j)
                adjustedLastSolidDF = pDF.reactantToDF(adjustedLastSolidReactant, system)
                
                # Calculate volume percentages (new as of 01/05/2024)
                lastSolidVolPerDF = pDF.reactantToVolDF(workingReactants1kg, system, workingP, workingT)

                # Get the fluid elements and reformat
                lastReactionElementsHeaders = workingFluid.elemental_comp.index.tolist()
                lastReactionElementsHeaders = [i.capitalize() for i in lastReactionElementsHeaders]
                lastReactionElementMolal = workingFluid.elemental_comp['molality'].tolist()
                lastReactionElements = [np.log10(i) for i in lastReactionElementMolal]

                # Get the fluid species and reformat
                lastReactionSpeciesHeaders = workingFluid.aqueous_species['species'].tolist()
                lastReactionSpeciesMolal = workingFluid.aqueous_species['molality'].tolist()
                lastReactionSpecies = [np.log10(i) for i in lastReactionSpeciesMolal]

                # Append physical properties to the lists
                # Relative to 1 kg fluid during the reaction
                lastSolid1kgMass = pDF.findReactantMass(workingReactants1kg, system)
                lastSolid1kgVolume = pDF.findReactantVolume(workingReactants1kg, system, workingP, workingT)
                lastFluid1kgMass = 1000.0  # If no reaction has happened then this will remain constant
                finalFluidMass1kgList.append(lastFluid1kgMass)
                finalSolidMass1kgList.append(lastSolid1kgMass)
                finalSolidVolume1kgList.append(lastSolid1kgVolume)

                # Keep final F/R the same as initial F/R
                finalFRRatioList.append(initialFRRatio)

                # Relative to initial fluid
                adjustedLastSolidMass = pDF.findReactantMass(adjustedLastSolidReactant, system)
                adjustedLastSolidVolume = pDF.findReactantVolume(adjustedLastSolidReactant, system, workingP, workingT)
                adjustedLastSolidDensity = adjustedLastSolidMass / adjustedLastSolidVolume
                adjustedLastFluidMass = lastFluid1kgMass * solidModulate
                finalFluidMassList.append(adjustedLastFluidMass)
                finalSolidMassList.append(adjustedLastSolidMass)
                finalSolidVolumeList.append(adjustedLastSolidVolume)
                finalSolidDensityList.append(adjustedLastSolidDensity)
                oxygenFugacityList.append(-999.0)

                # Flip the flag up so the code recognises that an error has occurred and can react accordingly above
                errorFlag = True
                
            
            
            # Create DataFrames for solid, fluid elements, fluid species
            if n == 0:
                # This is the solid at the given stage/time relative to 1 kg fluid during the calculation
                timeSolid1kgDF = deepcopy(lastSolid1kgDF)
                timeSolid1kgDF['Pressure (bars)'] = [workingP]
                timeSolid1kgDF['Temperature (K)'] = [workingT]
                timeSolid1kgDF['Time'] = [t + 1]
                timeSolid1kgDF['max log zi'] = [maxLogZi]
                timeSolid1kgDF['Error message'] = [errorMessage]

                # This is the solid at the given stage/time relative to the initial mass of fluid
                timeSolidDF = deepcopy(adjustedLastSolidDF)
                timeSolidDF['Pressure (bars)'] = [workingP]
                timeSolidDF['Temperature (K)'] = [workingT]
                timeSolidDF['Time'] = [t + 1]
                timeSolidDF['max log zi'] = [maxLogZi]
                timeSolidDF['Error message'] = [errorMessage]
                timeSolidDF = pd.concat([timeSolidDF, lastSolidVolPerDF], axis=1)

                # These two dataframes are relative to 1 kg fluid (molalities)
                timeElementsDF = pd.DataFrame([lastReactionElements])
                timeElementsDF.columns = lastReactionElementsHeaders
                timeElementsDF['Pressure (bars)'] = [workingP]
                timeElementsDF['Temperature (K)'] = [workingT]
                timeElementsDF['Time'] = [t + 1]
                timeElementsDF['max log zi'] = [maxLogZi]
                timeElementsDF['Error message'] = [errorMessage]

                timeFluidDF = pd.DataFrame([lastReactionSpecies])
                timeFluidDF.columns = lastReactionSpeciesHeaders
                timeFluidDF['Pressure (bars)'] = [workingP]
                timeFluidDF['Temperature (K)'] = [workingT]
                timeFluidDF['Time'] = [t + 1]
                timeFluidDF['max log zi'] = [maxLogZi]
                timeFluidDF['Error message'] = [errorMessage]

            # Else append the new data to the previous step
            else:
                tempSolid1kgDF = deepcopy(lastSolid1kgDF)
                tempSolid1kgDF['Pressure (bars)'] = [workingP]
                tempSolid1kgDF['Temperature (K)'] = [workingT]
                tempSolid1kgDF['Time'] = [t + 1]
                tempSolid1kgDF['max log zi'] = [maxLogZi]
                tempSolid1kgDF['Error message'] = [errorMessage]
                timeSolid1kgDF = pd.concat([timeSolid1kgDF, tempSolid1kgDF])

                tempSolidDF = deepcopy(adjustedLastSolidDF)
                tempSolidDF['Pressure (bars)'] = [workingP]
                tempSolidDF['Temperature (K)'] = [workingT]
                tempSolidDF['Time'] = [t + 1]
                tempSolidDF['max log zi'] = [maxLogZi]
                tempSolidDF['Error message'] = [errorMessage]
                tempSolidDF = pd.concat([tempSolidDF, lastSolidVolPerDF], axis=1)
                timeSolidDF = pd.concat([timeSolidDF, tempSolidDF])

                tempElementsDF = pd.DataFrame([lastReactionElements])
                tempElementsDF.columns = lastReactionElementsHeaders
                tempElementsDF['Pressure (bars)'] = [workingP]
                tempElementsDF['Temperature (K)'] = [workingT]
                tempElementsDF['Time'] = [t + 1]
                tempElementsDF['max log zi'] = [maxLogZi]
                tempElementsDF['Error message'] = [errorMessage]
                timeElementsDF = pd.concat([timeElementsDF, tempElementsDF])

                tempFluidDF = pd.DataFrame([lastReactionSpecies])
                tempFluidDF.columns = lastReactionSpeciesHeaders
                tempFluidDF['Pressure (bars)'] = [workingP]
                tempFluidDF['Temperature (K)'] = [workingT]
                tempFluidDF['Time'] = [t + 1]
                tempFluidDF['max log zi'] = [maxLogZi]
                tempFluidDF['Error message'] = [errorMessage]
                timeFluidDF = pd.concat([timeFluidDF, tempFluidDF])
            
#              #### DEBUG ####
#             if t == 2 and n == 0:
#                 print(n)
#                 print(startingfO2)
#                 print(dewReaction.fO2)
#                 print(dewReaction.fO2[tryLogZi])
#                 print(tryLogZi)
            
#                 with pd.ExcelWriter('debug.xlsx') as writer:
#                     timeSolidDF.to_excel(writer, sheet_name='solid_minerals')
#                     timeElementsDF.to_excel(writer, sheet_name='elements')
#                     timeFluidDF.to_excel(writer, sheet_name='fluid')
#                 return

        #### REMOVE BAD HEADERS ####
        # The solid-solution series may be recorded, in which case we remove the mineral in question and use the endmembers
        timeSolid1kgDF = timeSolid1kgDF[timeSolid1kgDF.columns.intersection(acceptableHeaders)]
        timeSolidDF = timeSolidDF[timeSolidDF.columns.intersection(acceptableHeaders)]

        # Append lists with physical properties
        timeSolid1kgDF['Initial mass of solid'] = initialSolidMassList
        timeSolid1kgDF['Initial mass of fluid'] = initialFluidMassList
        timeSolid1kgDF['F/R before reaction'] = initialFRRatioList
        timeSolid1kgDF['F/R after reaction'] = finalFRRatioList
        timeSolid1kgDF['Initial mass of solid (r. 1 kg)'] = initialSolidMass1kgList
        timeSolid1kgDF['Final mass of solid (r. 1 kg)'] = finalSolidMass1kgList
        timeSolid1kgDF['Final mass of fluid (r. 1 kg)'] = finalFluidMass1kgList
        timeSolid1kgDF['Final mass of solid'] = finalSolidMassList
        timeSolid1kgDF['Final mass of fluid'] = finalFluidMassList
        timeSolid1kgDF['Initial volume of solid'] = initialSolidVolumeList
        timeSolid1kgDF['Initial volume of solid (r. 1 kg)'] = initialSolidVolume1kgList
        timeSolid1kgDF['Final volume of solid (r. 1 kg)'] = finalSolidVolume1kgList
        timeSolid1kgDF['Final volume of solid'] = finalSolidVolumeList
        timeSolid1kgDF['Initial density of solid'] = initialSolidDensityList
        timeSolid1kgDF['Final density of solid'] = finalSolidDensityList

        timeSolidDF['Initial mass of solid'] = initialSolidMassList
        timeSolidDF['Initial mass of fluid'] = initialFluidMassList
        timeSolidDF['F/R before reaction'] = initialFRRatioList
        timeSolidDF['F/R after reaction'] = finalFRRatioList
        timeSolidDF['Initial mass of solid (r. 1 kg)'] = initialSolidMass1kgList
        timeSolidDF['Final mass of solid (r. 1 kg)'] = finalSolidMass1kgList
        timeSolidDF['Final mass of fluid (r. 1 kg)'] = finalFluidMass1kgList
        timeSolidDF['Final mass of solid'] = finalSolidMassList
        timeSolidDF['Final mass of fluid'] = finalFluidMassList
        timeSolidDF['Initial volume of solid'] = initialSolidVolumeList
        timeSolidDF['Initial volume of solid (r. 1 kg)'] = initialSolidVolume1kgList
        timeSolidDF['Final volume of solid (r. 1 kg)'] = finalSolidVolume1kgList
        timeSolidDF['Final volume of solid'] = finalSolidVolumeList
        timeSolidDF['Initial density of solid'] = initialSolidDensityList
        timeSolidDF['Final density of solid'] = finalSolidDensityList
        timeSolidDF['fO2'] = oxygenFugacityList

        #### COMBINE TIMESTEP DATAFRAME WITH TOTAL DATAFRAME ####
        if t == 0:
            totalSolid1kgDF = timeSolid1kgDF
            totalSolidDF = timeSolidDF
            totalElementsDF = timeElementsDF
            totalFluidDF = timeFluidDF
        else:
            totalSolid1kgDF = pd.concat([totalSolid1kgDF, timeSolid1kgDF])
            totalSolidDF = pd.concat([totalSolidDF, timeSolidDF])
            totalElementsDF = pd.concat([totalElementsDF, timeElementsDF])
            totalFluidDF = pd.concat([totalFluidDF, timeFluidDF])
        lastColumn = deepcopy(timeSolidDF)  # Propagate forward the 'true' results
        print('Timestep t=' + str(t) + ' is complete, with ' + str(n*(t+1)) + ' total iterations performed')
        print('Calculations : ' + str(calculations))
        print('Passes (F/R) : ' + str(passes))
        print('Passes (error) : ' + str(errors))
        totalCalculations = totalCalculations + calculations
        totalPasses = totalPasses + passes
        totalErrors = totalErrors + errors
        #### DEBUG ####
        if t == 1:
            with pd.ExcelWriter('debugPREV.xlsx') as writer:
                totalSolidDF.to_excel(writer, sheet_name='solid_minerals')
                totalElementsDF.to_excel(writer, sheet_name='elements')
                totalFluidDF.to_excel(writer, sheet_name='fluid')
        t+=1

    #### EXPORT ####
    # Export to xlsx
    with pd.ExcelWriter(exportPath+'.xlsx') as writer:
        totalSolidDF.to_excel(writer, sheet_name='solid_minerals')
        totalSolid1kgDF.to_excel(writer, sheet_name='solid_mins_1kgfluid')
        totalElementsDF.to_excel(writer, sheet_name='fluid_elements')
        totalFluidDF.to_excel(writer, sheet_name='fluid_species')
    print('data exported to: ' + exportPath+'.xlsx')
    end = timer()
    print('Total iterations : ' + str(timesteps*len(startingColumn)))
    print('Total calculations : ' + str(totalCalculations))
    print('Total passes (F/R) : ' + str(totalPasses))
    print('Total passes (error) : ' + str(totalErrors))
    print('Total runtime : ' + str(round(end-start, 1)) + ' seconds')
    print('Total runtime : ' + str(round((end-start)/60, 1)) + ' minutes')
    return



print('preamble loaded')
