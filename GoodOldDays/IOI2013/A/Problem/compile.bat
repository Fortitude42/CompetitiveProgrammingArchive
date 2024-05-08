set problem=dreaming

g++ -std=c++11 -DEVAL -static -O2 -o "%problem%" "grader.c" "%problem%.cpp" -O2 -lm
