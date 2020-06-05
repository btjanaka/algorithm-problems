all: n-queens n-queens-optimized

CPP_FLAGS = -O3 -std=c++11

n-queens: n-queens.cpp
	g++ $(CPP_FLAGS) n-queens.cpp -o n-queens
n-queens-optimized: n-queens-optimized.cpp
	g++ $(CPP_FLAGS) -pthread n-queens-optimized.cpp -o n-queens-optimized
