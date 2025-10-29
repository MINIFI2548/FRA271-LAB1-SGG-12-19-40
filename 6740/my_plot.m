%โหลด Data ที่จะ plot มาก่อนด้วย 
titleName = "Homing Test"; 
xlabelTxt = "Time";     % ชื่อแกน X
ylabelTxt = "Counts/Signle";    % ชื่อแกน Y

file_name = 'Homing test';

count = get(data, 'WrapAround X1:1');
homing = get(data, 'Gain:1');

varNames = {'Time', 'Counts', 'Home'};
times = count.Values.Time; 
count = squeeze(count.Values.Data);
homing = squeeze(homing.Values.Data);

tbl = table(times, count, homing, 'VariableNames', varNames);

graph = plot(tbl, "Time", {'Counts', 'Home'});
grid on
legend
xlabel(xlabelTxt);          % แสดงชื่อแกน X
ylabel(ylabelTxt);          % แสดงชื่อแกน Y
title(titleName);           % แสดงชื่อกราฟ

% กำหนดหน่วยของ Figure เป็นพิกเซลก่อน
set(gcf, 'Units', 'pixels');

% กำหนดตำแหน่งและขนาด [left, bottom, width, height]
% เราสนใจแค่ width และ height (480, 480)
set(gcf, 'Position', [100, 100, 480, 480]); % [ตำแหน่งซ้าย, ตำแหน่งล่าง, กว้าง, สูง]

saveas(gcf, append(file_name, '.png'));

