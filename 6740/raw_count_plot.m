%โหลด Data ที่จะ plot มาก่อนด้วย 
titleName = "Raw Count"; 
xlabelTxt = "Time";     % ชื่อแกน X
ylabelTxt = "Counts";    % ชื่อแกน Y

file_name = 'AMT_RAW_COUNT_1';

x1 = get(data, "TIM1_Encoder_X1:1");
x2 = get(data, 'TIM3_Encoder_X2:1');
x4 = get(data, 'TIM4_Encoder_X4:1');

varNames = {'Time', 'X1', 'X2', 'X4'};
times = x1.Values.Time; 
x1 = squeeze(x1.Values.Data);
x2 = squeeze(x2.Values.Data);
x4 = squeeze(x4.Values.Data);

tbl = table(times, x1, x2, x4, 'VariableNames', varNames);

graph = plot(tbl, "Time", {'X1', 'X2', 'X4'});
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

% เปิด data cursor mode
% dcm = datacursormode(gcf);
% datacursormode on;

% ตั้งข้อความที่จะแสดงเมื่อคลิก
% dcm.UpdateFcn = @(obj, event) { ...
%     ['Series: ', event.Target.DisplayName], ...
%     ['Time: ', num2str(event.Position(1))], ...
%     ['Count: ', num2str(event.Position(2))]};\

