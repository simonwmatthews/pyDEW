# Functions to subdivide relay function.
# Last updated: 16/05/2024, KW

import numpy as np
import pyDEW
import pyDEW.eq6_output
from thermoengine import model
import pandas as pd
from copy import deepcopy
import linecache
from scipy.interpolate import LinearNDInterpolator

# Additional pyDEW functions are wrapped up in this file
import pyDEW_functions as pDF


def createHybridFluid(proportions, P, T, database='EQ3_pickups_GS.xlsx',
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


def failedReactionOutput(reactant, fluid, fluidMass, system, P, T):
    """
    Function to return a compatible output if the reaction has returned an error.
    
    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    fluid : pyDEW.Fluid object
        pyDEW.Fluid object
    fluidMass : float
        mass of fluid in grams
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K
    elementsDict : dictionary
        dictionary of pyDEW fluid elemental log molalities
    speciesDict : dictionary
        dictionary of pyDEW fluid elemental log species

    OUTPUTS
    -------
    outputDict : dictionary of dictionaries
        dictionary including information on the following:
            - 'Physical properties' : physical properties of the reactants/products
            - 'Solid product' : solid product formatted as pyDEW.Reaction input dictionaries
            - 'Fluid elements' : elemental molalities of the fluid (log molal)
            - 'Fluid species' : molalities of species in the fluid (log molal)
            
    """
    initialReactantMass = pDF.findReactantMass(reactant, system)
    initialFRR = fluidMass / initialReactantMass
    physicalProperties = {
        'Temperature (K)' : T,
        'Pressure (bar)' : P,
        'initial solid mass' : initialReactantMass,
        'initial solid volume' : pDF.findReactantVolume(reactant, system, P, T),
        'initial solid density' : pDF.findReactantDensity(reactant, system, P, T),
        'final solid mass' : initialReactantMass,
        'final solid volume' : pDF.findReactantVolume(reactant, system, P, T),
        'final solid density' : pDF.findReactantDensity(reactant, system, P, T),
        'initial fluid mass' : fluidMass,
        'final fluid mass' : fluidMass,
        'initial FRR' : initialFRR,
        'final FRR' : initialFRR,
        'initial fluid fO2' : fluid.fO2,
        'final fluid fO2' : fluid.fO2,
        'max log zi (pyDEW)' : -999.0,
        'max log zi (DEW)' : -999.0,
        'error' : 'yes'
        }
    
    # Format the fluid elements and species - these are not log so we log them
    fluidElements = fluid.elemental_comp['molality'].to_dict()
    fluidElements.update((i, np.log10(j)) for i, j in fluidElements.items())
    fluidSpecies = pd.Series(fluid.aqueous_species['molality'].values, index=fluid.aqueous_species['species']).to_dict()
    fluidSpecies.update((i, np.log10(j)) for i, j in fluidSpecies.items())
    
    outputDict = {}
    outputDict['Properties'] = physicalProperties
    outputDict['Solid'] = reactant
    outputDict['Elements'] = fluidElements
    outputDict['Species'] = fluidSpecies
    return outputDict


def formatFluid(molalities):
    """
    Format to reformat pyDEW.Reaction outputs as new fluid inputs.
    
    INPUTS
    ------
    molalities : dictionary
        pyDEW.Reaction output dictionary

    OUTPUTS
    -------
    formattedMolalities : dictionary
        pyDEW.Fluid input dictionary

    """

    formattedMolalities = {
            'NA+':  molalities['Na'],
            'CA+2': molalities['Ca'],
            'MG+2': molalities['Mg'],
            'AL+3': molalities['Al'],
            'H4SIO4(AQ)': molalities['Si'],
            'CO3-2' : molalities['C'],
            'CL-': molalities['Cl'],
            'FE+2': molalities['Fe']}
    return formattedMolalities


def reactionByMass(reactant, fluid, fluidMass, system, P, T, outputFile='working/output', tabFile='working/tab', **kwargs):
    """
    Function to perform a pyDEW calculation by mass (as opposed to relative to 1 kg of reactant fluid)
    
    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    fluid : pyDEW.Fluid object
        pyDEW.Fluid object
    fluidMass : float
        mass of fluid in grams
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K
    outputFile : string
        path to pyDEW.Reaction output file
    tabFile : string
        path to pyDEW.Reaction tab file
    **kwargs : optional keyword arguments
        keyword arguments for pyDEW.Reaction

    OUTPUTS
    -------
    outputDict : dictionary of dictionaries
        dictionary including information on the following:
            - 'Physical properties' : physical properties of the reactants/products
            - 'Solid product' : solid product formatted as pyDEW.Reaction input dictionaries
            - 'Fluid elements' : elemental molalities of the fluid (log molal)
            - 'Fluid species' : molalities of species in the fluid (log molal)
            
    """
    
    #### PREAMBLE ####
    # Obtain mass of reactant and fluid-rock ratio, recalculate reactant relative to 1 kg of reactant fluid
    initialReactantMass = pDF.findReactantMass(reactant, system)
    initialFRR = fluidMass / initialReactantMass
    workingReactant1kg = pDF.reactantToFR(reactant, initialFRR, system)
    
    # 'solidModulate' is the ratio between initial fluid and 1 kg, which we will need to correct for at the end of the reaction
    solidModulate  = fluidMass / 1000.0

    # Perform our calculation
    initialReactant1kgMoles = np.sum([j['moles'] for j in workingReactant1kg])
    dewReaction = pyDEW.Reaction(fluid, T, P, workingReactant1kg, zimax=initialReactant1kgMoles, calculation_mode='titration')

        
    # Sometimes an empty dataframe is returned - this flags it up
    if isinstance(dewReaction.minerals, pd.DataFrame) == False:
        raise pyDEW.core.RunError('Mineral output is not a pd.DataFrame')
        
    lastReactionDF = pDF.findSolidComposition(outputFile, system, P, T)

    #### PROCESSING ####
    # Get maximum valid log zi and corresponding index
    # Because of rounding/removal of duplicates this is different in the output file
    lastValidLogZi = dewReaction.elements.last_valid_index()
    lastValidLogZiIndex = dewReaction.elements.index.get_loc(lastValidLogZi)
    outputLogZiList = list(lastReactionDF['log zi'].unique())
    lastValidOutputLogZi = min(outputLogZiList, key=lambda x:abs(x-lastValidLogZi))  # Find maximum logZi in the output
    lastValidOutputLogZiIndex = outputLogZiList.index(lastValidOutputLogZi)  # Find corresponding index

    # Get the dataframe representing the last solid (from 1 kg fluid)
    lastSolid1kg = lastReactionDF[lastReactionDF['log zi'] == lastValidOutputLogZi]
    lastSolid1kgHeaders = lastSolid1kg['phase/end-member'].tolist()
    lastSolid1kgValues = lastSolid1kg['moles'].tolist()

    # Because CPX and KSP has two different solid solutions, need to clarify the differences or pandas throws a fit
    if 'CLINOPYROXENE(SS)' in lastSolid1kgHeaders:
        index = lastSolid1kgHeaders.index('CLINOPYROXENE(SS)')
        lastSolid1kgHeaders[index+1] = 'DIOPSIDE(CPX)'
        lastSolid1kgHeaders[index+2] = 'JADEITE(CPX)'
        lastSolid1kgHeaders[index+3] = 'HEDENBERGITE(CPX)'
    if 'KFELDSPAR(SS)' in lastSolid1kgHeaders:
        index = lastSolid1kgHeaders.index('KFELDSPAR(SS)')
        lastSolid1kgHeaders[index+1] = 'KFELDSPAR(KSP)'
        lastSolid1kgHeaders[index+2] = 'ALBITE(KSP)'

    #### FORMAT SOLID RELATIVE TO 1 KG FLUID ####
    # Create new dataframe and reactant object for our final reactant (from 1 kg fluid)
    lastSolid1kgDF = pd.DataFrame([lastSolid1kgValues])
    lastSolid1kgDF.columns = lastSolid1kgHeaders

    # Set the headers up so we find mineral endmembers but not minerals
    acceptableHeaders = [i.props['phase_name'] for i in system.minerals]
    acceptableHeaders.extend(['DIOPSIDE(CPX)', 'JADEITE(CPX)', 'HEDENBERGITE(CPX)', 'KFELDSPAR(KSP)', 'ALBITE(KSP)'])
    lastSolid1kgDF = lastSolid1kgDF[lastSolid1kgDF.columns.intersection(acceptableHeaders)]  # Remove mineral names with solid solution
    if len(lastSolid1kgDF.columns) != len(set(lastSolid1kgDF.columns)):  # Remove any duplicate columns
        lastSolid1kgDF = lastSolid1kgDF.iloc[:, ~lastSolid1kgDF.columns.duplicated()]

    # Convert our pandas output into a reactant list of dictionaries, find physical properties, volume percentages
    lastSolid1kgProduct = pDF.DFtoReactant(lastSolid1kgDF.iloc[0], system)
    lastSolid1kgMass = pDF.findReactantMass(lastSolid1kgProduct, system)
    lastSolid1kgVolume = pDF.findReactantVolume(lastSolid1kgProduct, system, P, T)

    # So far everything has been done relative to 1 kg of fluid. Here we need to recalculate the fluid and solid masses.
    # Get the final mass of fluid and solid, and other physical properties
    lastFluid1kgMass = 1000.0 * pDF.findFluidMassChange(tabFile, index=lastValidOutputLogZiIndex)
    finalFRR = lastFluid1kgMass / lastSolid1kgMass

    #### FORMAT SOLID RELATIVE TO INITIAL FLUID MASS (ADJUSTED) ####
    # Multiply the product solid values by the modulate value to get the true solid mass (i.e., for whatever amount of fluid there is
    # before correction to 1 kg for F/R). Then do the same as above for each corrected solid
    adjustedLastSolidProduct = []
    for j in lastSolid1kgProduct:
        j['moles'] = j['moles'] * solidModulate
        adjustedLastSolidProduct.append(j)
    adjustedLastSolidDF = pDF.reactantToDF(adjustedLastSolidProduct, system)
    adjustedLastSolidDF.reset_index().T.drop_duplicates().T
    adjustedLastFluidMass = lastFluid1kgMass * solidModulate

    # Determine the 'true' physical properties of the solid
    adjustedLastSolidMass = pDF.findReactantMass(adjustedLastSolidProduct, system)
    adjustedLastSolidVolume = pDF.findReactantVolume(adjustedLastSolidProduct, system, P, T)
    adjustedLastSolidDensity = pDF.findReactantDensity(adjustedLastSolidProduct, system, P, T)



    # # DEBUGGING
    eq6out = pyDEW.eq6_output.eq6output(fluid, 'working/tab', 'working/output')
    print('pyDEW index')
    print(lastValidLogZiIndex)
    print('pyDEW lz')
    print(lastValidLogZi)
    print('Output index')
    print(lastValidOutputLogZiIndex)
    print('Output lz')
    print(lastValidOutputLogZi)
    print('pyDEW len fO2')
    print(len(dewReaction.fO2))
    print('kev len fO2')
    print(len(pDF.readfO2('working/tab')))
    print('kev fO2')
    print(pDF.readfO2('working/tab'))
    print('pyDEW fO2')
    print(dewReaction.fO2)
    print('eq6_output fO2')
    print(eq6out.fO2)
    print('pyDEW len elements')
    print(len(dewReaction.elements))
    print('pyDEW elements')
    print(dewReaction.elements)
    print('output lz')
    print(outputLogZiList)

    # Dictionary to store the physical properties of the system
    physicalProperties = {
        'Temperature (K)' : T,
        'Pressure (bar)' : P,
        'initial solid mass' : initialReactantMass,
        'initial solid volume' : pDF.findReactantVolume(reactant, system, P, T),
        'initial solid density' : pDF.findReactantDensity(reactant, system, P, T),
        'final solid mass' : adjustedLastSolidMass,
        'final solid volume' : adjustedLastSolidVolume,
        'final solid density' : adjustedLastSolidDensity,
        'initial fluid mass' : fluidMass,
        'final fluid mass' : adjustedLastFluidMass,
        'initial FRR' : initialFRR,
        'final FRR' : finalFRR,
        'initial fluid fO2' : fluid.fO2,
        'final fluid fO2' : pDF.readfO2('working/tab')[lastValidOutputLogZiIndex], # dewReaction.fO2[lastValidOutputLogZiIndex],
        'max log zi (pyDEW)' : lastValidLogZi,
        'max log zi (DEW)' : lastValidOutputLogZi,
        'error' : 'no'
        }

    # Need to return dictionaries (of dictionaries?) - one for corrected solid, one for fluid element molal and species molal
    # Start with the corrected solid
    outputDict = {}
    outputDict['Properties'] = physicalProperties
    outputDict['Solid'] = adjustedLastSolidProduct
    outputDict['Elements'] = dewReaction.elements.iloc[lastValidLogZiIndex].to_dict()
    outputDict['Species'] = dewReaction.species_concs.iloc[lastValidLogZiIndex].to_dict()
    outputDict['Volumes'] = pDF.reactantToVolDF(adjustedLastSolidProduct, system, P, T).iloc[0].to_dict()
    return outputDict


def combineOutputs(outputs, system):
    """
    Function to combine the outputs generated in the previous function into pandas DataFrames.
    
    INPUTS
    ------
    outputs : list of dictionary of dictionaries
        list of outputs generated by the 'reactionByMass' function
    system : pyDEW.System object
        pyDEW.System for calculations

    OUTPUTS
    -------
    list of four pandas DataFrames for each output

    """

    physicalList = []
    solidList = []
    elementsList = []
    speciesList = []
    volumesList = []
    
    for i in range(len(outputs)):
        physicalList.append(pd.Series(outputs[i]['Properties']))
        solidList.append(pDF.reactantToDF(outputs[i]['Solid'], system).iloc[0])
        elementsList.append(pd.Series(outputs[i]['Elements']))
        speciesList.append(pd.Series(outputs[i]['Species']))
        volumesList.append(pd.Series(outputs[i]['Volumes']))
    physicalDF = pd.concat(physicalList, axis=1).T
    solidDF = pd.concat(solidList, axis=1).T
    elementsDF = pd.concat(elementsList, axis=1).T
    speciesDF = pd.concat(speciesList, axis=1).T
    volumesDF = pd.concat(volumesList, axis=1).T
    
    return [physicalDF, solidDF, elementsDF, speciesDF, volumesDF]


def combineTimes(combinedOutputs, exportPath='export'):
    """
    Function to combine the combined outputs generated in the previous function.
    
    INPUTS
    ------
    combinedOutputs : list of pandas.DataFrames
        list of pandas.DataFrames comprised of combined pyDEW reaction outputs
    exportPath : string
        path to export Excel file. Default is 'export'
    
    OUTPUTS
    -------
    Excel file comprising four sheets
    """
    
    # Make sure that there is a time column
    for i in range(len(combinedOutputs)):
        time = i + 1
        timeColumn = [time] * len(combinedOutputs[i][0])
        for j in combinedOutputs[i]:
            j['Time'] = timeColumn
    physicalOutputs = [i[0] for i in combinedOutputs]
    solidOutputs = [i[1] for i in combinedOutputs]
    elementsOutputs = [i[2] for i in combinedOutputs]
    speciesOutputs = [i[3] for i in combinedOutputs]
    volumesOutputs = [i[4] for i in combinedOutputs]
    
    physicalExportDF = pd.concat(physicalOutputs)
    solidExportDF = pd.concat(solidOutputs)
    elementsExportDF = pd.concat(elementsOutputs)
    speciesExportDF = pd.concat(speciesOutputs)
    volumesExportDF = pd.concat(volumesOutputs)
    
    # Fiddling to move the time column to the end if new minerals pop in
    columns = [col for col in solidExportDF.columns if col != 'Time'] + ['Time']
    solidExportDF = solidExportDF[columns]
    columns = [col for col in volumesExportDF.columns if col != 'Time'] + ['Time']
    volumesExportDF = volumesExportDF[columns]
    
    with pd.ExcelWriter(exportPath+'.xlsx') as writer:
        physicalExportDF.to_excel(writer, sheet_name='properties')
        solidExportDF.to_excel(writer, sheet_name='solid_minerals')
        elementsExportDF.to_excel(writer, sheet_name='fluid_elements')
        speciesExportDF.to_excel(writer, sheet_name='fluid_species')
        volumesExportDF.to_excel(writer, sheet_name='mineral_volumes')
    return
