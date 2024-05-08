set problem=scales

g++ -DEVAL -static -O2 -std=c++11 -o "%problem%" -Wshadow -Wextra -Wconversion "grader.cpp" "%problem%.cpp"
