set NAME=artclass

g++ -std=c++11 -DEVAL -static -O2 -o "%NAME%" grader.c graderlib.c "%NAME%.cpp" -ljpeg
