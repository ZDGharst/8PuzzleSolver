.DEFAULT_GOAL := run_8puzzle_program

run_8puzzle_program:
	@echo "Compiling, linking, and assembling into object files..."
	g++ -o bin/8puzzle.o src/8puzzle.cpp src/solver.cpp src/puzzle.cpp src/node.cpp
	
	./bin/8puzzle.o
