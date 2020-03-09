:loop
python gen.py >in.txt
python std.py <in.txt >ans.txt
main.exe <in.txt >out.txt
fc out.txt ans.txt
if not errorlevel 1 goto loop
pause
