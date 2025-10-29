%plot voltage and flux density
index=1;

startTime=[0 11 22 31 41 52 62 73];

avg_vector_1=[];
avg_vector_2=[];
avg_vector_3=[];

voltage_in_array_1=[];
voltage_in_array_2=[];
voltage_in_array_3=[];

avg_all_vlotage_vector=[];
avg_all_vector=[];

i=1;

while index<4
% load("magnetic_without_sheild_"+string(index)+".mat")
% if index==2
%     data1=double(data{1}.Values.Data);
%      data1=squeeze(data1);
%      t = data{1}.Values.Time;
% else
    data1=double(data.Data);
    data1=squeeze(data1);
    t = data.Time;
% end
n=1;
avg_vector=[];
voltage_in_array=[];
while n<length(startTime)+1
    endTime=startTime(n)+3.00;
    start_index=find(t==startTime(n));
    end_index=find(t==endTime);
    
    selected_data_1=data1(start_index:end_index,1);
    selected_time_1=t(start_index:end_index,1);
    
    avg_selected_1=mean(selected_data_1,"all");
    voltage_in_array(end+1)=((avg_selected_1/4095)*3.3);
    avg_vector(end+1)=(((avg_selected_1/4095)*3.3)-1.65)*1000/60;
    n=n+1;
    if index==1
        avg_vector_1(end+1)=(((avg_selected_1/4095)*3.3)-1.65)*1000/60;
        voltage_in_array_1(end+1)=((avg_selected_1/4095)*3.3);
    end
    if index==2
        avg_vector_2(end+1)=(((avg_selected_1/4095)*3.3)-1.65)*1000/60;
        voltage_in_array_2(end+1)=((avg_selected_1/4095)*3.3);
    end
    if index==3
        avg_vector_3(end+1)=(((avg_selected_1/4095)*3.3)-1.65)*1000/60;
        voltage_in_array_3(end+1)=((avg_selected_1/4095)*3.3);
    end
end
% plot(t,data1);
% hold on;
% plot(avg_vector,voltage_in_array,'LineWidth', 10);
% xlim("auto")
% ylim("auto")
% colorbar off
% subtitle("Magnetic relation with voltage "+ "round "+string(index) )
% ylabel("Voltage ( V )")
% xlabel("Magnetic field density ( mT )")
% hAxes = findobj(gcf,"Type","axes")
% hAxes.FontSize = 26;
%saveas(gcf, "Magnectic Sensor with out Shield "+ "round "+string(index)+".png");
%hold on;
index=index+1;
end
while i<length(startTime)+1
    avg_all_vector(end+1)=(avg_vector_1(i)+avg_vector_2(i)+avg_vector_3(i))/3;
    avg_all_voltage_vector(end+1)=( voltage_in_array_1(i)+ voltage_in_array_2(i)+ voltage_in_array_3(i))/3;
    i=i+1;
end


% plot(voltage_in_array,avg_all_vector,'LineWidth', 10);
% xlim("auto")
% ylim("auto")
% colorbar off
% subtitle("Magnectic Sensor with out Sheild "+ "average ") 
% xlabel("Distance from sensor ( cm )")
% ylabel("Magnetic field density ( mT )")
% hAxes = findobj(gcf,"Type","axes")
% hAxes.FontSize = 26;
% saveas(gcf, "Magnectic Sensor with out Sheild "+ "average "+".png");
hold off;