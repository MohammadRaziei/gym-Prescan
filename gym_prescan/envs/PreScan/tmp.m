IDs=10:-1:1;
range=10.453:-1:1;
vel=10.453:-1:1;
head=10.453:-1:1;
All_data=IDs';

Numer_data=10

pt = 10;

Num_colid=sum(IDs>0);

% All_data_useful=All_data(:,1:Num_colid);
% disp(All_data_useful)


 % range.'
 %         vel.'
 %         head.'];
 
 
All_data_useful_str=mat2str(All_data);
%disp(All_data_useful_str)


pt = 10;

len_id=(pt+8)
len_one_block=len_id
len= Numer_data*(len_one_block)


Number_data=10

t = num2str(round(get_param(bdroot,'SimulationTime'),pt),['%0' num2str(pt) '.2f ']);
% t = num2str(2.2,['%0.' num2str(pt) 'f ']);

To_add=['{"Time":' t ', '];
 
len=190*4-1+2+18;
send_data = uint8(32*ones(len,1));
for i=1:Number_data
    Id_name=num2str(i,['%0' num2str(3) '.f ']);
    Id_Colide=num2str(IDs(i),['%0' num2str(pt) '.f ']);
    Ra_Colide=num2str(range(i),['%0' num2str(pt) '.2f ']);
    Ve_Colide=num2str(vel(i),['%0' num2str(pt) '.2f ']);
    he_Colide=num2str(head(i),['%0' num2str(pt) '.2f ']);

    To_add=[To_add '"I' Id_name '":"' Id_Colide '", ' ...
                   '"R' Id_name '":"' Ra_Colide '", ' ...
                   '"V' Id_name '":"' Ve_Colide '", ' ...
                   '"H' Id_name '":"' he_Colide '"'];
   if i<Number_data
       To_add=[To_add ', ']
   end
end
To_add=[To_add '}'];
send_data = uint8(To_add);
send_data = uint8(send_data);

%b'{"Time":0.00000000,"Position":{"x": 0.000000000000000e+00,"y": 0.000000000000000e+00,"z": 0.000000000000000e+00},"Velocity":{"x": 0.000000000000000e+00,"y": 0.000000000000000e+00,"z": 0.000000000000000e+00},"Acceleration":{"x": 0.000000000000000e+00,"y": 0.000000000000000e+00,"z": 0.000000000000000e+00}}'
%b'{"Time":0000000.00, "I001":0000000000, "R001":0000000.00, "V001":0000000.00, "H001":0000000.00, "I002":0000000000, "R002":0000000.00, "V002":0000000.00, "H002":0000000.00, "I003":0000000000, "R003":0000000.00, "V003":0000000.00, "H003":0000000.00, "I004":0000000000, "R004":0000000.00, "V004":0000000.00, "H004":0000000.00, "I005":0000000000, "R005":0000000.00, "V005":0000000.00, "H005":0000000.00, "I006":0000000000, "R006":0000000.00, "V006":0000000.00, "H006":0000000.00, "I007":0000000000, "R007":0000000.00, "V007":0000000.00, "H007":0000000.00, "I008":0000000000, "R008":0000000.00, "V008":0000000.00, "H008":0000000.00, "I009":0000000000, "R009":0000000.00, "V009":0000000.00, "H009":0000000.00, "I010":0000000000, "R010":0000000.00, "V010":0000000.00, "H010":0000000.00}'
