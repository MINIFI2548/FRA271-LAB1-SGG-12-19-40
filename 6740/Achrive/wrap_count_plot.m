%โหลด Data ที่จะ plot มาก่อนด้วย 
titleName = "WrapAround Count"; 
xlabelTxt = "Time";     % ชื่อแกน X
ylabelTxt = "Count";    % ชื่อแกน Y

x1 = get(data, "WrapAround X1:1");
x2 = get(data, 'WrapAround X2:1');
x4 = get(data, 'WrapAround X4:1');

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

% เปิด data cursor mode
% dcm = datacursormode(gcf);
% datacursormode on;

% ตั้งข้อความที่จะแสดงเมื่อคลิก
% dcm.UpdateFcn = @(obj, event) { ...
%     ['Series: ', event.Target.DisplayName], ...
%     ['Time: ', num2str(event.Position(1))], ...
%     ['Count: ', num2str(event.Position(2))]};\

