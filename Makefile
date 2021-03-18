run_8puzzle_program:
	g++ -o bin/8puzzle.o -I include/ src/*.cpp
	./bin/8puzzle.o
	
profiler: diagnostics strace

diagnostics: run_8puzzle_program
	/usr/bin/time -v -p -o profile/system.log ./bin/8puzzle.o
	
strace: run_8puzzle_program
	strace -o profile/strace.log ./bin/8puzzle.o
