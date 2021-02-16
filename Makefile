run_8puzzle_program:
	g++ -o bin/8puzzle.o -I include/ src/*.cpp
	./bin/8puzzle.o
