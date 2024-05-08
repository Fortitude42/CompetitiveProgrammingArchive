gen.exe > .in
a.exe < .in
b.exe < .in

@ echo off
:1
echo good
a.exe > .in
b.exe < .in > .out2
fc /L .out1 .out2 
if %errorlevel% == 0 goto 1
echo NeSovpalo
pause

a.exe > .in
b.exe < .in