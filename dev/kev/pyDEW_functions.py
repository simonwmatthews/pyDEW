# Additional functions for volume percent calculations.
# Last updated: 16/05/2024, KW

import numpy as np
import pyDEW
from thermoengine import model
import pandas as pd
from copy import deepcopy
import linecache


def findReactantMass(reactant, system):
    """
    Find the total mass in g of a list of dictionaries forming a reactant.

    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    system : pyDEW.System object
        pyDEW.System for calculations

    OUTPUTS
    -------
    mass : float
        mass of solid in grams

    """

    # Find all minerals and molecular masses in system
    systemMinerals = [i.props['phase_name'] for i in system.minerals]
    systemMrs = [round(i.props['molwt'][0], 5) for i in system.minerals]
    systemSolidSolutions = list(system.solid_solutions.keys())
    
    masses = []
    for i in range(len(reactant)):
        mineral = reactant[i]
        mineralName = mineral['reactant']
        mineralMoles = mineral['moles']

        # If the mineral is a solid solution mineral, sort each solid solution endmember out
        if mineralName in systemSolidSolutions:

            # Obtain the endmembers of that solid solution
            systemEndmembers = system.solid_solutions[mineralName]
            mineralEndmembers = list(mineral['composition'].keys())
            
            # Iterate over all endmembers in the mineral
            for j in mineralEndmembers:
                # Find index of the endmember in the system minerals, and use data to obtain mass
                endmemberIndex = systemMinerals.index(j)
                endmemberProportion = mineral['composition'][j]
                endmemberMr = systemMrs[endmemberIndex]
                endmemberMass = endmemberMr * mineralMoles * endmemberProportion
                masses.append(endmemberMass)

        else:
            # If the mineral is not a solid solution then we can just perform the last calculation
            endmemberIndex = systemMinerals.index(mineralName)
            endmemberProportion = 1.0
            endmemberMr = systemMrs[endmemberIndex]
            endmemberMass = endmemberMr * mineralMoles * endmemberProportion
            masses.append(endmemberMass)

    return sum(masses)


def findMineralVolume(mineral, system, moles, P, T):
    """
    Calculate volume of a mineral in cubic centimetres.

    INPUTS
    ------
    mineral : string
        string of pyDEW mineral
    system : pyDEW.System object
        pyDEW.System for calculations
    moles : float
        moles of mineral
    P : float
        pressure in bars
    T : float
        temperature in K

    OUTPUTS
    -------
    mineralVolume : float
        mineral volume in cubic centimetres

    """

    systemMinerals = [i.abbrev for i in system.minerals]
    if mineral not in systemMinerals:
        mineralVolume = np.nan
    else:
        mineralObject = system.minerals[systemMinerals.index(mineral)]
        mineralVolume = mineralObject.volume(T, P) * moles * 10.0  # multiply by 10 to get from J/bar to cm3
    return mineralVolume


def findReactantVolume(reactant, system, P, T):
    """
    Find the total sum of volumes of minerals in a reactant in cubic centimetres.
    
    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K
    
    OUTPUTS
    -------
    volume : float
        volume of solid in cubic centimetres
    """

    systemMinerals = [i.abbrev for i in system.minerals]
    mineralVolumes = []
    
    for i in reactant:
        if 'composition' in i.keys():
            SSmoles = i['moles']
            endmembers = list(i['composition'].keys())
            endmemberProportions = list(i['composition'].values())
            for j in range(len(i['composition'].keys())):
                mineralEndmember = endmembers[j]
                mineralEndmemberMoles = endmemberProportions[j] * SSmoles
                mineralVolumes.append(findMineralVolume(mineralEndmember, system, mineralEndmemberMoles, P, T))
        else:
            mineral = i['reactant']
            mineralMoles = i['moles']
            mineralVolumes.append(findMineralVolume(mineral, system, mineralMoles, P, T))
    return np.sum(mineralVolumes)


def findReactantDensity(reactant, system, P, T):
    """
    Find the total density of a reactant in g/cm3.
    
    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K
    
    OUTPUTS
    -------
    density : float
        density of solid in g/cm3
    """

    reactantMass = findReactantMass(reactant, system)
    reactantVolume = findReactantVolume(reactant, system, P, T)
    return reactantMass / reactantVolume


def reactantToFR(reactant, FR, system):
    """
    Recalculate reactant for a defined fluid-rock ratio (relative to 1 kg fluid).
    
    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    FR : float
        fluid-rock ratio
    system : pyDEW.System object
        pyDEW.System for calculations

    OUTPUTS
    -------
    correctedReactants : list of dictionaries
        pyDEW.Reaction mineral input

    """

    uncorrectedReactantMass = findReactantMass(reactant, system)
    correctedReactants = deepcopy(reactant)
    ratio = 1000.0 / uncorrectedReactantMass
    
    # This converts the corrected reactants to 1 kg, and then to the correct FR
    for i in correctedReactants:
        i['moles'] = i['moles'] * ratio / FR
    return correctedReactants


def reactantToMass(reactant, newMass, system):
    """
    Recalculate reactant for a defined mass.

    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    mass : float
        new mass of the solid in grams
    system : pyDEW.System object
        pyDEW.System for calculations

    OUTPUTS
    -------
    correctedReactants : list of dictionaries
        pyDEW.Reaction mineral input

    """
    uncorrectedReactantMass = findReactantMass(reactant, system)
    correctedReactants = deepcopy(reactant)
    ratio = newMass / uncorrectedReactantMass

    # This converts the corrected reactants to 1 kg, and then to the correct FR
    for i in correctedReactants:
        i['moles'] = i['moles'] * ratio
    return correctedReactants


def findSolidComposition(outputFile, system, P, T):
    """
    Reaction to find the running mineral composition of the total solid.
    Solid is returned as a pd.DataFrame without sorting into solid solutions.
    
    INPUTS
    ------
    outputFile : string
        path to output file generated by EQ6
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K

    OUTPUTS
    -------
    exportDF : pandas.DataFrame
        DataFrame of solid composition with columns 'phase/endmember', 'moles', 'grams', 'volume, cc', 'log zi'

    """
    
    # Define lookups as 'bookmarks' for where to extract data
    lookup1 = 'log of reaction progress'
    lookup2 = 'grand summary'
    lookup3 = 'mineral saturation state summary'
    
    # Empty lists for storage
    logzi = []
    startLineNumber = []
    endLineNumber = []
    
    # Open file, extract info, read file
    file = open(outputFile, 'r')
    for num, line in enumerate(file):
        
        # Lookup 1 is where we find our running reaction progress
        if lookup1 in line:
            logzi.append(float(line.split()[-1]))
        
        # Lookup 2 is start of the g.s. table, add 4 here to get to data (headers skipped)
        if lookup2 in line:
            startLineNumber.append(num + 4)
        
        # Lookup 3 is start of the table following the g.s. table, subtract 12 to get to end to g.s. table
        if lookup3 in line:
            endLineNumber.append(num - 12)
    file.close()

    # Line number to get our headers is selected from the final g.s. table
    beginHeaders = startLineNumber[-1]-1
    headers = linecache.getline(outputFile, beginHeaders).strip().split('  ')
    headers = [i.strip() for i in headers if i != '']

    for i in range(len(logzi)):
        
        # Extract all datalines in the g.s. tables
        start = startLineNumber[i]
        end = endLineNumber[i]
        dataLines = []
        for j in range(start, end):
            dataLine = linecache.getline(outputFile, j).strip().split(' ')
            dataLine = [k.strip() for k in dataLine if k != '']
            if dataLine == []:
                continue
            else:
                dataLines.append(dataLine)
                
        # Convert to floats, except for the mineral names in index 0
        for j in dataLines:
            for k in range(1, len(j)):
                j[k] = float(j[k])
        
        # Export to pd.DataFrame
        if i == 0:
            exportDF = pd.DataFrame(dataLines)
            exportDF.columns = headers
            exportDF['log zi'] = len(exportDF)*[logzi[i]]
        else:
            tempDF = pd.DataFrame(dataLines)
            tempDF.columns = headers
            tempDF['log zi'] = len(tempDF)*[logzi[i]]
            exportDF = pd.concat([exportDF, tempDF])
            
    # Calculate the true mineral volume from moles and pressure/temperature of system
    exportDF['volume, cc'] = [findMineralVolume(exportDF['phase/end-member'].iloc[i], system,
                                                exportDF['moles'].iloc[i], P, T) for i in range(len(exportDF))]

    return exportDF


def findLastSolid(outputFile, system, P, T, notNaNRow=True):
    """
    Returns the composition of the last solid in the same format as required for EQ6 reactants.
    
    INPUTS
    ------
    outputFile : string
        path to pyDEW.Reaction output file
    system : pyDEW.System
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K
    
    OUTPUTS
    -------
    reactants : list of dictionaries
        pyDEW.Reaction mineral input

    """
    
    solidCompositions = findSolidComposition(outputFile, system, P, T)
    maxLogzi = np.max(solidCompositions['log zi'])
    lastSolidDF = solidCompositions[solidCompositions['log zi'] == maxLogzi]

#     # If notNaNRow, then take the first row which is not NaN
#     if notNaNRow:
#         if lastSolidDF.isnull().all():
#             solidCompositions = solidCompositions[pd.notnull(solidCompositions['log zi'])]
#             if len(solidCompositions) == 0:
#                 return 'Output is empty'
#             maxLogzi = np.max(solidCompositions['log zi'])
#             lastSolidDF = solidCompositions[solidCompositions['log zi'] == maxLogzi]

    # Find composition of last solid
    lastSolidMinerals = lastSolidDF['phase/end-member'].tolist()
    
    # Search the output for each solid solution and format into dictionary
    searchedMinerals = []
    reactants = []
    for i in range(len(lastSolidMinerals)):
        mineral = lastSolidMinerals[i]
        
        # If the mineral has already been scanned, continue, else append to list of considered minerals
        if mineral in searchedMinerals:
            continue
        searchedMinerals.append(mineral)
        
        # If the mineral has solid solutions, calculate for endmembers, else calculate for mineral itself
        if mineral in list(system.solid_solutions.keys()):
            phases = []  # List to keep track of phases comprising solid solutions
            moles = []  # List to keep information about solid solution molar composition
            volumes = []  # List to keep track of volumes
            
            # Find mineral solid solution phases, iterate over them
            mineralSS = system.solid_solutions[mineral]
            for j in range(len(mineralSS)):
                dfRow = lastSolidDF[lastSolidDF['phase/end-member'] == mineralSS[j]]
                phases.append(mineralSS[j])
                moles.append(dfRow['moles'].iloc[0])
                volumes.append(dfRow['volume, cc'].iloc[0])
            searchedMinerals.extend(phases)

            # If the number of moles is zero, then the mineral in question is no longer in the system
            totalMoles = np.sum(moles)
            if totalMoles == 0.0:
                continue

            # Find molar ratio of each solid solution for composition
            molarRatios = [j/totalMoles for j in moles]

            # Formatting into dictionary
            minDict = {'reactant' : mineral}
            minDict['moles'] = totalMoles
            minDict['composition'] = {phases[i]: molarRatios[i] for i in range(len(phases))}
            minDict['volume'] = {phases[i]: volumes[i] for i in range(len(phases))}

        else:
            dfRow = lastSolidDF[lastSolidDF['phase/end-member'] == mineral]

            # If the mineral is not present, then skip the mineral
            if dfRow['moles'].iloc[0] == 0.0:
                continue
            
            # Formatting into dictionary
            minDict = {'reactant': mineral}
            minDict['moles'] = dfRow['moles'].iloc[0]
            minDict['volume'] = dfRow['volume, cc'].iloc[0]

        # Append dictionaries to list, matching required format
        reactants.append(minDict)
    # # Get rid of any NaNs and zeros
    # popList = []
    # for i in range(len(reactants)):
    #     if np.isnan(reactants[i]['moles']):
    #         popList.append(i)
    #     elif reactants[i]['moles'] == 0.0:
    #         popList.append(i)
    # reactants = [i for j, i in enumerate(reactants) if j not in popList]
    return reactants


def findFluidMassChange(tabFile, index=-1):
    """
    Function to find change in H2O mass before/after reaction.
    
    INPUTS
    ------
    tabfile : string
        path to pyDEW.Reaction tab file
    index : integer
        index of fluid mass to compare to initial fluid mass. Default is -1 (final item)
    
    OUTPUTS
    -------
    H2OChange : float
        ratio of mass H2O after reaction to mass H2O before reaction

    """

    # Find start of table
    lookup = 'log fo2'
    file = open(tabFile, 'r')
    for num, line in enumerate(file):
        if lookup in line:
            # track where the start of our headers are, data starts 3 lines after the headers
            beginHeaders = num + 1
            beginData = num + 3
            break
    file.close()

    # Read headers from the file, trim away excess whitespace
    headers = linecache.getline(tabFile, beginHeaders).strip().split('  ')
    headers = [i.strip() for i in headers if i != '']

    # Determine number of lines in the data by finding where after the headers we find a big break
    count = 0
    while linecache.getline(tabFile, beginData+count).strip() != '':
        count += 1

    # Read data
    dataLines = []
    for i in range(beginData, beginData+count):
        # Get line, split by whitespace to identify values
        dataLine = linecache.getline(tabFile, i).strip().split(' ')

        # Remove whitespaces, then convert strings to float
        dataLine = [j.strip() for j in dataLine if j != '']
        
        # This check is to make sure that there aren't two decimals sticking to each other
        check = [j.count('.') for j in dataLine]
        if 2 in check:
            checkIndex = check.index(2)
            errorValue = dataLine[checkIndex]
            value1 = errorValue[:8]
            value2 = errorValue[8:]
            dataLine.insert(checkIndex+1, value1)
            dataLine.insert(checkIndex+2, value2)
            dataLine.pop(checkIndex)
        dataLine = [float(j) for j in dataLine]
        dataLines.append(dataLine)

    # Convert data to dataframe, find ratio of H2O at start and at end
    pHData = pd.DataFrame(data=dataLines, columns=headers)
    H2Okg = pHData['kg h2o']
    H2OChange = H2Okg.iloc[index]/H2Okg.iloc[0]
    return H2OChange


def reactantToDF(reactant, system):
    """
    Convert reactant list of dictionaries to pd.DataFrame.
    
    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    system : pyDEW.System object
        pyDEW.System for calculations

    OUTPUTS
    -------
    exportDF : pandas.DataFrame
        single row pandas DataFrame of mineral moles

    """

    systemMinerals = [i.props['phase_name'] for i in system.minerals]
    systemSolidSolutions = list(system.solid_solutions.keys())
    
    names = []
    moles = []
    for i in range(len(reactant)):
        mineral = reactant[i]
        mineralName = mineral['reactant']
        mineralMoles = mineral['moles']

        # If the mineral is a solid solution mineral, sort each solid solution endmember out
        if mineralName in systemSolidSolutions:

            # Obtain the endmembers of that solid solution
            systemEndmembers = system.solid_solutions[mineralName]
            mineralEndmembers = list(mineral['composition'].keys())
            
            # Iterate over all endmembers in the mineral
            for j in mineralEndmembers:
                # Find index of the endmember in the system minerals, and use data to obtain mass
                # Exceptions made for CPX and KSP, as they share endmembers with other solid solution series
                # We add a small prefix here which can be removed at a later stage
                if mineralName == 'CLINOPYROXENE(SS)':
                    names.append(j+'(CPX)')
                elif mineralName == 'KFELDSPAR(SS)':
                    names.append(j+'(KSP)')
                else:
                    names.append(j)
                endmemberProportion = mineral['composition'][j]
                endmemberMoles = mineralMoles * endmemberProportion
                moles.append(endmemberMoles)

        else:
            # If the mineral is not a solid solution then we can just perform the last calculation
            names.append(mineralName)
            moles.append(mineral['moles'])
    
    exportDF = pd.DataFrame([moles])
    exportDF.columns = names
    return exportDF


def reactantToVolDF(reactant, system, P, T):
    """
    Convert reactant list of dictionaries to pd.DataFrame of mineral vol%, adapted from reactantToDF.

    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K

    OUTPUTS
    -------
    exportDF : pandas.DataFrame
        single row pandas DataFrame of mineral vol%

    """

    systemMinerals = [i.props['phase_name'] for i in system.minerals]
    systemSolidSolutions = list(system.solid_solutions.keys())

    names = []
    volPer = []
    for i in range(len(reactant)):
        mineral = reactant[i]
        mineralName = mineral['reactant']
        mineralMoles = mineral['moles']

        # If the mineral is a solid solution mineral, sort each solid solution endmember out
        if mineralName in systemSolidSolutions:

            # Obtain the endmembers of that solid solution
            systemEndmembers = system.solid_solutions[mineralName]
            mineralEndmembers = list(mineral['composition'].keys())

            # Iterate over all endmembers in the mineral
            for j in mineralEndmembers:
                # Find index of the endmember in the system minerals, and use data to obtain mass
                # Exceptions made for CPX and KSP, as they share endmembers with other solid solution series
                # We add a small prefix here which can be removed at a later stage
                if mineralName == 'CLINOPYROXENE(SS)':
                    names.append(j+'(CPX)')
                elif mineralName == 'KFELDSPAR(SS)':
                    names.append(j+'(KSP)')
                else:
                    names.append(j)
                endmemberProportion = mineral['composition'][j]
                endmemberMoles = mineralMoles * endmemberProportion
                volPer.append(findMineralVolume(j, system, endmemberMoles, P, T))

        else:
            # If the mineral is not a solid solution then we can just perform the last calculation
            names.append(mineralName)
            volPer.append(findMineralVolume(mineralName, system, mineral['moles'], P, T))

    # Normalise and convert to percentage volumes
    totalVolume = findReactantVolume(reactant, system, P, T)
    volPer = [100*i/totalVolume for i in volPer]

    # Alter column header titles
    names = [i + '_volPER' for i in names]

    exportDF = pd.DataFrame([volPer])
    exportDF.columns = names
    return exportDF


def DFtoReactant(series, system):
    """
    Convert pandas.Series object into a formatted reactant list of dictionaries.
    
    INPUTS
    ------
    series : pandas.Series object
        pandas Series as formatted in the previous function
    system : pyDEW.System object
        pyDEW.System for calculations

    OUTPUTS
    -------
    reactantsList : list of dictionaries
        pyDEW.Reaction mineral input

    """

    systemMinerals = [i.props['phase_name'] for i in system.minerals]
    systemSolidSolutions = list(system.solid_solutions.keys())
    seriesKeys = series.keys().tolist()
    keyMinerals = []
    for i in seriesKeys:
        # If the mineral is a solid solution value, find the mineral family
        # HOWEVER - there are two cpx and feldspar solid solutions!
        # I have added a tag in reactantToDF to mark what solid solution belongs to what - this part
        # here essentially undos that so pyDEW can find the correct endmember to use
        if '(CPX)' in i:
            keyMineral = 'CLINOPYROXENE(SS)'
        elif '(KSP)' in i:
            keyMineral = 'KFELDSPAR(SS)'
        elif i not in systemMinerals:
            # This should allow us to scoop up all minerals regardless of the nature of the output DataFrame
            continue
        else:
            if any(i in j for j in system.solid_solutions.values()):
                keyMineral = [key for key, value in system.solid_solutions.items() if i in value][0]
            else:
                keyMineral = i
        if keyMineral not in keyMinerals:
            keyMinerals.append(keyMineral)
            
    # Now start from key minerals and work way towards endmembers
    reactantsList = []
    for i in keyMinerals:
        if i in systemSolidSolutions:
            endmembers = system.solid_solutions[i]
            
            # Make sure the code recognises our suffixes when translating into a pyDEW reactant
            if i == 'CLINOPYROXENE(SS)':
                endmembers = [j + '(CPX)' for j in endmembers]
            elif i == 'KFELDSPAR(SS)':
                endmembers = [j + '(KSP)' for j in endmembers]
            endmembers = [j for j in endmembers if j in seriesKeys]
            totalMoles = sum([series[j] for j in endmembers])

            # Cases where the number of total moles is zero or NaN
            if totalMoles == 0.0:
                continue
            if np.isnan(totalMoles):
                continue
            endmemberProportions = [series[j]/totalMoles for j in endmembers]
            # Undo any suffix additions before reformatting into a pyDEW reactant
            if i == 'CLINOPYROXENE(SS)':
                endmembers = [j[:-5] for j in endmembers]
            elif i == 'KFELDSPAR(SS)':
                endmembers = [j[:-6] for j in endmembers]

            minDict = {'reactant': i,
                       'moles': totalMoles,
                       'composition': {endmembers[j] : endmemberProportions[j] for j in range(len(endmembers))}}
        else:
            if series[i] == 0.0:
                continue
            if np.isnan(series[i]):
                continue
            minDict = {'reactant': i,
                       'moles': series[i]}
        reactantsList.append(minDict)

    # This single-liner removes all the duplicates in the list (which can happen)
    reactantsList = [i for n, i in enumerate(reactantsList) if i not in reactantsList[n + 1:]]
    
    # Get rid of any NaNs and zeros
    popList = []
    for i in range(len(reactantsList)):
        if np.isnan(reactantsList[i]['moles']):
            popList.append(i)
        elif reactantsList[i]['moles'] == 0.0:
            popList.append(i)
    reactantsList = [i for j, i in enumerate(reactantsList) if j not in popList]
    return reactantsList


def volReactantToReactant(volumeReactant, system, P, T, mass=1000.0):
    """
    Convert reactant volume dictionary into reactant moles dictionary.
    A reactant volume dictionary takes the same form as a pyDEW reactant input dictionary,
    but has 'moles' replaced by 'molar', the molar proportion (vol%) of the mineral in the reactant.

    INPUTS
    ------
    volumeReactant : list of dictionaries
        dictionary of reactant modal proportions
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K
    mass : float
        mass of reactants to return in grams. Default is 1000.0

    OUTPUTS
    -------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input

    """

    systemMinerals = [i.props['phase_name'] for i in system.minerals]
    systemSolidSolutions = list(system.solid_solutions.keys())

    # Quick check to make sure that modal sums up to 100, and normalises if it doesn't
    volumeReactantModalSum = sum([i['modal'] for i in volumeReactant])
    if volumeReactantModalSum != 100.0:
        for i in volumeReactant:
            i['modal'] = i['modal'] * 100 / volumeReactantModalSum

    reactant = []
    for i in range(len(volumeReactant)):
        mineral = volumeReactant[i]
        mineralName = mineral['reactant']
        mineralVolProp = mineral['modal']/100.0

        # If the mineral is a solid solution mineral, sort each solid solution endmember out
        if mineralName in systemSolidSolutions:

            # Obtain the endmembers of that solid solution
            systemEndmembers = system.solid_solutions[mineralName]
            mineralEndmembers = list(mineral['composition'].keys())
            mineralVolume = 0.0

            # Iterate over all endmembers in the mineral
            for j in mineralEndmembers:

                # Find the volume contributing to that molar fraction
                proportionalVolume = findMineralVolume(j, system, mineral['composition'][j], P, T)
                mineralVolume = mineralVolume + proportionalVolume
            # mineralVolume is the volume of 1 mole of reactant (including solid solutions)
            # mineralMoles is therefore the moles of 1 unit of mineral volume
            mineralMoles = mineralVolProp / mineralVolume
            molDictEntry = {'reactant': mineral['reactant'],
                            'moles': mineralMoles,
                            'composition': mineral['composition']}
            reactant.append(molDictEntry)

        else:
            # If the mineral is not a solid solution then we can just perform the last calculation
            mineralVolume = findMineralVolume(mineralName, system, 1.0, P, T)
            mineralMoles = mineralVolProp / mineralVolume
            molDictEntry = {'reactant': mineral['reactant'],
                            'moles': mineralMoles}
            reactant.append(molDictEntry)

    # Normalise and convert to percentage volumes
    totalMass = findReactantMass(reactant, system)
    totalMoles = sum([i['moles'] for i in reactant])
    for i in reactant:
        i['moles'] = i['moles'] * mass / totalMass
    return reactant


def reactantToVolReactant(reactant, system, P, T):
    """
    Convert reactant moles dictionary into reactant volume dictionary.
    A reactant volume dictionary takes the same form as a pyDEW reactant input dictionary,
    but has 'moles' replaced by 'molar', the molar proportion (vol%) of the mineral in the reactant.

    INPUTS
    ------
    reactant : list of dictionaries
        pyDEW.Reaction mineral input
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K

    OUTPUTS
    -------
    volumeReactant : list of dictionaries
        pyDEW.Reaction mineral input formatted for volumes

    """

    systemMinerals = [i.props['phase_name'] for i in system.minerals]
    systemSolidSolutions = list(system.solid_solutions.keys())
    
    totalVolume = findReactantVolume(reactant, system, P, T)

    volumeReactant = []
    for i in range(len(reactant)):
        mineral = reactant[i]
        mineralName = mineral['reactant']
        mineralMoles = mineral['moles']

        # If the mineral is a solid solution mineral, sort each solid solution endmember out
        if mineralName in systemSolidSolutions:
            mineralVolume = []

            # Obtain the endmembers of that solid solution
            systemEndmembers = system.solid_solutions[mineralName]
            mineralEndmembers = list(mineral['composition'].keys())

            # Iterate over all endmembers in the mineral
            for j in mineralEndmembers:
                endmemberProportion = mineral['composition'][j]
                endmemberMoles = mineralMoles * endmemberProportion
                mineralVolume.append(findMineralVolume(j, system, endmemberMoles, P, T))
            
            # Append to volume reactant
            volDictEntry = {'reactant': mineral['reactant'],
                            'modal': 100 * np.sum(mineralVolume) / totalVolume,
                            'composition': mineral['composition']}
            volumeReactant.append(volDictEntry)

        else:
            # If the mineral is not a solid solution then we can just perform the last calculation
            mineralVolume = findMineralVolume(mineralName, system, mineralMoles, P, T)
            volDictEntry = {'reactant': mineral['reactant'],
                            'modal': 100 * mineralVolume / totalVolume}
            volumeReactant.append(volDictEntry)
    return volumeReactant


def volReactantToVolDF(volReactant, system, P, T):
    """
    Convert volume percentage reactant list of dictionaries to pd.DataFrame of mineral vol%.

    INPUTS
    ------
    volReactant : list of dictionaries
        pyDEW reactant expressed as modal proportions
    system : pyDEW.System object
        pyDEW.System for calculations
    P : float
        pressure in bars
    T : float
        temperature in K

    OUTPUTS
    -------
    exportDF : pandas.DataFrame
        single row pandas DataFrame of mineral vol%

    """

    systemMinerals = [i.props['phase_name'] for i in system.minerals]
    systemSolidSolutions = list(system.solid_solutions.keys())

    names = []
    volPer = []
    for i in range(len(volReactant)):
        mineral = volReactant[i]
        mineralName = mineral['reactant']
        mineralVolProp = mineral['modal']

        # If the mineral is a solid solution mineral, sort each solid solution endmember out
        if mineralName in systemSolidSolutions:

            # Obtain the endmembers of that solid solution
            systemEndmembers = system.solid_solutions[mineralName]
            mineralEndmembers = list(mineral['composition'].keys())
            endmemberRelVol = []

            # Iterate over all endmembers in the mineral
            for j in mineralEndmembers:
                # Find index of the endmember in the system minerals, and use data to obtain volume
                # Exceptions made for CPX and KSP, as they share endmembers with other solid solution series
                # We add a small prefix here which can be removed at a later stage
                if mineralName == 'CLINOPYROXENE(SS)':
                    names.append(j+'(CPX)')
                elif mineralName == 'KFELDSPAR(SS)':
                    names.append(j+'(KSP)')
                else:
                    names.append(j)
                endmemberProportion = mineral['composition'][j]  # Find volume of each molar endmember
                endmemberRelVol.append(findMineralVolume(j, system, endmemberProportion, P, T))
            endmemberVolume = [mineralVolProp * k / np.sum(endmemberRelVol) for k in endmemberRelVol]
            volPer.extend(endmemberVolume)

        else:
            # If the mineral is not a solid solution then we can just perform the last calculation
            names.append(mineralName)
            volPer.append(mineralVolProp)

    # Normalise and convert to percentage volumes
    if np.sum(volPer) != 100.0:
        volPer = [100.0*i/sum(volPer) for i in volPer]
        
    # Alter column header titles
    names = [i + '_volPER' for i in names]

    exportDF = pd.DataFrame([volPer])
    exportDF.columns = names
    return exportDF


def readfO2(tabFile):
    """
    Function to generate list of fO2 during reaction.
    
    INPUTS
    ------
    tabfile : string
        path to pyDEW.Reaction tab file

    
    OUTPUTS
    -------
    fO2 : list
        list of reaction fO2

    """

    # Find start of table
    lookup = 'log fo2'
    file = open(tabFile, 'r')
    for num, line in enumerate(file):
        if lookup in line:
            # track where the start of our headers are, data starts 3 lines after the headers
            beginHeaders = num + 1
            beginData = num + 3
            break
    file.close()

    # Read headers from the file, trim away excess whitespace
    headers = linecache.getline(tabFile, beginHeaders).strip().split('  ')
    headers = [i.strip() for i in headers if i != '']

    # Determine number of lines in the data by finding where after the headers we find a big break
    count = 0
    while linecache.getline(tabFile, beginData+count).strip() != '':
        count += 1

    # Read data
    dataLines = []
    for i in range(beginData, beginData+count):
        # Get line, split by whitespace to identify values
        dataLine = linecache.getline(tabFile, i).strip().split(' ')

        # Remove whitespaces, then convert strings to float
        dataLine = [j.strip() for j in dataLine if j != '']
        
        # This check is to make sure that there aren't two decimals sticking to each other
        check = [j.count('.') for j in dataLine]
        if 2 in check:
            checkIndex = check.index(2)
            errorValue = dataLine[checkIndex]
            value1 = errorValue[:8]
            value2 = errorValue[8:]
            dataLine.insert(checkIndex+1, value1)
            dataLine.insert(checkIndex+2, value2)
            dataLine.pop(checkIndex)
        dataLine = [float(j) for j in dataLine]
        dataLines.append(dataLine)

    # Convert data to dataframe, find ratio of H2O at start and at end
    pHData = pd.DataFrame(data=dataLines, columns=headers)
    fO2 = pHData['log fo2'].to_list()
    return fO2
