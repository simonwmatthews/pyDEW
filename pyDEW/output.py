import pandas as pd
from pyDEW import core

class eq3output:
    def __init__(self, filepath='output', suppress_warnings=False):
        f = open(filepath,'r',encoding='mac-roman')

        # Variable to store important parameters from the input printout
        self.calc_props = dict()
        self.jflags = []
        self.solid_solution_input = dict()
        self.basis_species = []
        self.elemental_comp = pd.DataFrame(columns=['element','ppm','molality'])
        self.basis_species_comp = pd.DataFrame(columns=['species','ppm','molality'])
        self.electrochemistry = pd.DataFrame(columns=['scale','pH','Eh','pe'])
        self.aqueous_species = pd.DataFrame(columns=['species','molality','log_g','activity'])
        self.solid_solutions = dict()
        self.electrical_balance = dict()
        self.redox = pd.DataFrame(columns=['couple','Eh','pe','log_fO2','ah'])
        self.mineral_saturation = pd.DataFrame(columns=['mineral','log_q_k','aff','state'])
        self.gases = pd.DataFrame(columns=['gas','fugacity'])

        found_ss = False
        first_ss = True

        # List of variables to extract from input printout
        calc_props_flags = ['tempc','rho','fep','uebal','uacion']

        # Variable to track position in the file
        # 0 - preamble
        # 1 - input printout
        # 2 - calculation printout
        # 3 - strict basis species
        # 4 - Elemental composition of the aqueous phase
        # 5 - Elemental composition as strict basis species
        # 6 - Equivalent composition of the aqueous phase (cte balances)
        # 7 - Electrical balance totals
        # 8 - activity ratios of ions
        # 9 - distribution of aqueous species
        # 10 - major aqueous species contribution to mass balances
        # 11 - summary of aqueous redox reactions
        # 12 - summary of aqueous non-equilibrium non-redox reactions
        # 13 - summary of stoichiometric mineral saturation states
        # 14 - summary of gases
        # 15 - end of output
        # 16 - solid solution information in the input file printout (out of sequence)
        # 17 - summary of input solid solutions
        # 18 - summary of hypothetical solid solutions
        p = 0

        for l in f:
            s = l.split()
            if len(s)>0:

                ### CHECK FOR SECTION CHANGE ###########################################
                if p == 0 and s[0] == 'endit':
                    p = 1
                    continue
                if p > 0: # This should mean keywords can appear in the preamble.
                    if s == ' solid solutions'.split():
                        p = 16
                        continue
                    if s == ' --- the input file has been successfuly read ---'.split():
                        p = 2
                        continue
                    if s == '--- strict basis species ---'.split():
                        p = 3
                        continue
                    if s == ['-----','Elemental','composition','of','the','aqueous','phase','-----']:
                        p = 4
                        continue
                    elif s == ['-----','elemental','composition','as','strict','basis','species','-----']:
                        p = 5
                        continue
                    elif s == ['---','equivalent','composition','of','the','aqueous','phase','(cte','balances)','---']:
                        p = 6
                        continue
                    elif s == ['-----','electrical','balance','totals','-----']:
                        p = 7
                        continue
                    elif s == ['-----','activity','ratios','of','ions','-----']:
                        p = 8
                        continue
                    elif s == ['-----','distribution','of','aqueous','species','-----']:
                        p = 9
                        continue
                    elif s == ['-----','major','aqueous','species','contributing','to','mass','balances','-----']:
                        p = 10
                        continue
                    elif s == ['-----','summary','of','aqueous','redox','reactions','-----']:
                        p = 11
                        continue
                    elif s == '----- summary of aqueous non-equilibrium non-redox reactions -----'.split():
                        p = 12
                        continue
                    elif s == '----- summary of stoichiometric mineral saturation states -----'.split():
                        p = 13
                        continue
                    elif s == '----- summary of input solid solutions -----'.split():
                        p = 17
                        continue
                    elif s == '----- summary of hypothetical solid solutions -----'.split():
                        p = 18
                        continue
                    elif s == '----- summary of gases -----'.split():
                        p = 14
                        continue
                    elif s == '----- end of output -----'.split():
                        p = 15
                        continue

                ### PREAMBLE ###########################################################
                if p == 0:
                    if s == ['endit.']:
                        p += 1
                        continue
                    continue

                ### INPUT FILE PRINTOUT ################################################
                if p == 1:

                    for flag in calc_props_flags:
                        if flag+'=' in s:
                            flag_pos = s.index(flag+'=')
                            if len(s) > flag_pos+1 and flag in ['uebal','uacion']:
                                self.calc_props[flag] = s[flag_pos+1]
                            elif len(s) > flag_pos+1:
                                self.calc_props[flag] = core.convert_float(s[flag_pos+1])

                    # Check for a jflag block:
                    if s[0] == 'data':
                        jblock = [s[-1]]
                    if s[0] == 'jflag=':
                        jblock += [s[1],core.convert_float(s[-1])]
                        self.jflags.append(jblock)
                    if s[0] == 'uphas1=':
                        self.jflags[-1].append(s[1])
                        if len(s) > 3 and '\x00' not in s[3]:
                            self.jflags[-1].append(s[3])

                    # Check whether nxmod is set and warn that the script won't read this
                    # if s[0] == 'nxmod=' and s[1] == '1' and suppress_warnings == False:
                    #     print('WARNING: DATA0 modified with nxmod. This will not be read by the script.')
                    continue

                ### READ SOLID SOLUTION COMPOSITION ############################
                if p == 16:
                    if s[0] != 'endit.' and len(s) == 1:
                        ss_name = s[0]
                        ss_info = pd.Series()
                        stored = False
                    elif s[0] != 'component' and len(s) > 1:
                        ss_info[s[0]]=core.convert_float(s[1])
                    if s[0] == 'endit.' and stored == False:
                        self.solid_solution_input.update({ss_name:ss_info})
                        stored = True


                ### STRICT BASIS SPECIES ###########################################
                if p == 3:
                    if '---' in l:
                        p = 2
                    else:
                        self.basis_species.append(s[0])


                ### ELEMENTAL COMPOSITION ##############################################
                if p == 4:
                    if s[0] != 'element':
                        row = {'element':s[0],
                               'ppm':s[2],
                               'molality':s[3]}
                        self.elemental_comp = self.elemental_comp.append(row,ignore_index=True)

                ### BASIS SPECIES ##################################################
                if p == 5:
                    if s[0] != 'species':
                        for species in self.basis_species:
                            if s[0] in species:
                                row = {'species':species,
                                       'ppm':core.convert_float(s[2]),
                                       'molality':core.convert_float(s[3])}
                            else:
                                row = {'species':s[0],
                                       'ppm':core.convert_float(s[2]),
                                       'molality':core.convert_float(s[3])}
                        self.basis_species_comp = self.basis_species_comp.append(row,ignore_index=True)

                ### EQUIVALENT COMPOSITION #########################################
                if p == 6:
                    if s[:3] == 'internal ph scale'.split() or s[:3] == 'rational ph scale'.split():
                        row = {'scale':' '.join(s[:2]),
                               'pH':core.convert_float(s[3]),
                               'Eh':core.convert_float(s[4]),
                               'pe':core.convert_float(s[5])}
                        self.electrochemistry = self.electrochemistry.append(row,ignore_index=True)
                    elif s[:4] == 'modified nbs ph scale'.split():
                        row = {'scale': ' '.join(s[:3]),
                               'pH': core.convert_float(s[4]),
                               'Eh': core.convert_float(s[5]),
                               'pe': core.convert_float(s[6])}
                        self.electrochemistry = self.electrochemistry.append(row,ignore_index=True)

                ### ELECTRICAL BALANCE #############################################
                if p == 7:
                    if len(s)>2 and s[-2] == '=':
                        self.electrical_balance[' '.join(s[:-2])] = core.convert_float(s[-1])

                ### DISTRIBUTION OF AQUEOUS SPECIES ################################
                if p == 9:
                    if s[0] != 'species':
                        row = {'species': s[0],
                               'molality': core.convert_float(s[1]),
                               'log_g': core.convert_float(s[3]),
                               'activity': core.convert_float(s[4])}
                        self.aqueous_species = self.aqueous_species.append(row,ignore_index=True)

                ### SUMMARY OF AQUEOUS REDOX REACTIONS #############################
                if p == 11:
                    if s[0] != 'couple':
                        row = {'couple':' '.join(s[:-4]),
                               'Eh':core.convert_float(s[-4]),
                               'pe':core.convert_float(s[-3]),
                               'log_fO2':core.convert_float(s[-2]),
                               'ah':core.convert_float(s[-1])}
                        self.redox = self.redox.append(row,ignore_index=True)

                ### MINERAL SATURATION STATES ######################################
                if p == 13:
                    if 'mineral' not in s and 'approx.' not in s and 'saturated' not in s\
                    and 'supersaturated' not in s and 'supersatd.' not in s and len(s)>1:
                        row = {'mineral': s[0],
                               'log_q_k': core.convert_float(s[1]),
                               'aff': core.convert_float(s[2])}
                        if len(s) > 3 and (s[3] == 'satd' or s[3] == 'ssatd'):
                            row.update({'state': s[3]})
                        self.mineral_saturation = self.mineral_saturation.append(row,ignore_index=True)

                        if len(s) > 4:
                            if s[3] == 'satd' or s[3] == 'ssatd':
                                row = {'mineral': s[4],
                                       'log_q_k': core.convert_float(s[5]),
                                       'aff': core.convert_float(s[6])}
                                if len(s) > 7:
                                       row.update({'state':s[7]})
                            else:
                                row = {'mineral': s[3],
                                       'log_q_k': core.convert_float(s[4]),
                                       'aff': core.convert_float(s[5])}
                                if len(s) > 6:
                                       row.update({'state':s[6]})
                            self.mineral_saturation = self.mineral_saturation.append(row,ignore_index=True)

                ### SUMMARY OF GASES ###############################################
                if p == 14:
                    if s[0] != 'gas':
                        row = {'gas':s[0],
                               'fugacity':core.convert_float(s[1])}
                        self.gases = self.gases.append(row,ignore_index=True)

                ### SOLID SOLUTIONS ############################################
                if p == 18:
                    if ((len(s)> 1 and (s[1] == 'saturated' or s[1] == 'supersatd.')) == False):
                        if s[0] != 'mineral' and s[0] != 'ideal' and s[0] != 'xbar':
                            if l[0] == '_' and first_ss == False:
                                self.solid_solutions.update({ss_mineral : [ss_info,ss_endmembers]})
                                found_ss = False
                            elif l[0] != '_' and found_ss == False:
                                first_ss = False
                                ss_mineral = s[0]
                                ss_info = {'log_q_k':core.convert_float(s[1]),
                                           'aff':core.convert_float(s[2]),
                                           'state':' '.join(s[3:])}
                                found_ss = True
                                ss_endmembers = pd.DataFrame(columns=['endmember','xbar','lamda','activity'])
                            elif len(s) == 7:
                                row = {'endmember': s[0],
                                       'xbar': core.convert_float(s[1]),
                                       'lamda': core.convert_float(s[2]),
                                       'activity': core.convert_float(s[3])}
                                ss_endmembers = ss_endmembers.append(row,ignore_index=True)
