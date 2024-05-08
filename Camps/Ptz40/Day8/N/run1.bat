@ echo off
:1
gen.exe > .in
a.exe < .in > .out1
b.exe < .in > .out2
fc /L .out1 .out2
if %errorlevel% == 0 goto 1
echo HELLO
pause


