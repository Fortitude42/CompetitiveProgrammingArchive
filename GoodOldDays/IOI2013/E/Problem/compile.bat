set NAME=robots

g++ -std=c++11 -DEVAL -static -O2 -o "%NAME%" "grader.c" "%NAME%.cpp"
