set problem=sorting

g++ -DEVAL -static -O2 -std=c++11 -o "%problem%" "grader.cpp" "%problem%.cpp"
