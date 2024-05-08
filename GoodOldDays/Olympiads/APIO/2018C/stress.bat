@echo off

g++ a.cpp -o a.exe -std=c++11
g++ b.cpp -o b.exe -std=c++11
g++ gen.cpp -o gen.exe -std=c++11

set i=0

:loop
  gen.exe %i% > in
  a.exe < in > out
  b.exe < in > out-stupid

  fc out out-stupid
  if errorlevel 1 goto fail

  echo OK
  set /a i=%i%+1
  goto loop

:fail
  echo Found failing test!
