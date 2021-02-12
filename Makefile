run_8puzzle_program:
	@echo "Compiling, linking, and assembling into object files..."
	g++ -o bin/8puzzle.o -I include/ src/8puzzle.cpp src/solver.cpp src/puzzle.cpp src/node.cpp
	
	./bin/8puzzle.o
