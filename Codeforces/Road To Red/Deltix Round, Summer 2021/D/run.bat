gen.exe > .in
a.exe < .in

:1
echo good
gen.exe > .in
a.exe < .in > .out1
goto 1
