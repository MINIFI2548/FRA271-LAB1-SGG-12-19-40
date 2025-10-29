%โหลด Data ที่จะ plot มาก่อนด้วย 
file_name = 'Position Data1';
titleName = file_name; 
xlabelTxt = "Time";     % ชื่อแกน X
ylabelTxt = "Counts";    % ชื่อแกน Y

count = get(data, 'WrapAround X4:1');

varNames = {'Time', 'Position'};
times = count.Values.Time; 
count = squeeze(count.Values.Data);

tbl = table(times, count, 'VariableNames', varNames);

graph = plot(tbl, "Time", 'Position');
grid on
legend('Position(counts)')
xlabel(xlabelTxt);          % แสดงชื่อแกน X
ylabel(ylabelTxt);          % แสดงชื่อแกน Y
title(titleName);           % แสดงชื่อกราฟ

% กำหนดหน่วยของ Figure เป็นพิกเซลก่อน
set(gcf, 'Units', 'pixels');

% กำหนดตำแหน่งและขนาด [left, bottom, width, height]
% เราสนใจแค่ width และ height (480, 480)
set(gcf, 'Position', [100, 100, 480, 480]); % [ตำแหน่งซ้าย, ตำแหน่งล่าง, กว้าง, สูง]

saveas(gcf, append(file_name, '.png'));

% -----------------------------------------------------------

%โหลด Data ที่จะ plot มาก่อนด้วย 
file_name = 'Omega Data1';
titleName = file_name; 
xlabelTxt = "Time";     % ชื่อแกน X
ylabelTxt = "Omega(rads/s)";    % ชื่อแกน Y

count = get(data, 'X4 V Rad:1');

varNames = {'Time', 'Position'};
times = count.Values.Time; 
count = squeeze(count.Values.Data);

tbl = table(times, count, 'VariableNames', varNames);

graph = plot(tbl, "Time", 'Position');
grid on
legend('Omega(rads/s)')
xlabel(xlabelTxt);          % แสดงชื่อแกน X
ylabel(ylabelTxt);          % แสดงชื่อแกน Y
title(titleName);           % แสดงชื่อกราฟ

% กำหนดหน่วยของ Figure เป็นพิกเซลก่อน
set(gcf, 'Units', 'pixels');

% กำหนดตำแหน่งและขนาด [left, bottom, width, height]
% เราสนใจแค่ width และ height (480, 480)
set(gcf, 'Position', [100, 100, 480, 480]); % [ตำแหน่งซ้าย, ตำแหน่งล่าง, กว้าง, สูง]

saveas(gcf, append(file_name, '.png'));