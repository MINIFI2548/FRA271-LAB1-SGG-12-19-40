%โหลด Data ที่จะ plot มาก่อนด้วย 
titleName = "Counter Clockwise"; 
xlabelTxt = "Time";     % ชื่อแกน X
ylabelTxt = "Counts";    % ชื่อแกน Y

file_name = 'Wrap CCW';

raw = get(data, 'TIM4_Encoder_X4:1');
wrap = get(data, 'WrapAround X4:1');

varNames = {'Time', 'Raw-Counts', 'Wrap-Around'};
times = raw.Values.Time; 
raw = squeeze(raw.Values.Data);
wrap = squeeze(wrap.Values.Data);

tbl = table(times, raw, wrap, 'VariableNames', varNames);

graph = plot(tbl, "Time", {'Raw-Counts', 'Wrap-Around'});
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

