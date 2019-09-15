sim('PreScan_Vissim_Python_0_cs');


for i = 1 : 100 
    disp(i);
    isFlag = evalin('base', 'isStoped');

    if isFlag(end) ~= 0
       sim('PreScan_Vissim_Python_0_cs');
    end
end




