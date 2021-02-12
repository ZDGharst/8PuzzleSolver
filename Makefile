.DEFAULT_GOAL := run_8puzzle_program

run_8puzzle_program:
	g++ -o 8puzzle.o src/8puzzle.cpp src/solver.cpp src/puzzle.cpp src/node.cpp
	./8puzzle.o
	rm 8puzzle.o
