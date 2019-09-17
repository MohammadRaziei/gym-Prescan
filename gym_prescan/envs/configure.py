ExperimentName = ''
bdroot = ''
prescanFile = ''

def set_experimant(ExpName):
    global ExperimentName, bdroot, prescanFile
    ExperimentName = ExpName
    bdroot = ExperimentName + "_cs"
    prescanFile = ExperimentName + ".pb"
    print(ExperimentName)