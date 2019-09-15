if ~matlab.engine.isEngineShared
    matlab.engine.shareEngine('MATLAB_PRESCAN_engine')
end
ExperimentName = 'PreScan_Vissim_Python_0';

sys = load_system([ExperimentName '_cs']);

% set_param(bdroot, 'SimulationCommand', 'start');