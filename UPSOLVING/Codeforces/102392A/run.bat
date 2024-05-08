gen.exe > .in
a.exe < .in > .out1
b.exe < .in > .out2


@echo off
:1
echo good
gen.exe > .in
a.exe < .in > .out1
b.exe < .in > .out2
fc/L .out1 .out2
if %errorlevel% == 0 goto 1
echo NeSovpalo
pause