#include "solver.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int main() {
    std::ifstream inputFile;
    inputFile.open("data/input.txt");

    if(!inputFile) {
        return -1;
    }

    int numPuzzles;
    inputFile >> numPuzzles;

    std::chrono::duration<double, std::milli> totalTime;    
    for(int i = 0; i < numPuzzles; i++) {
        std::string puzzleData = "         ";
        std::cout << "Puzzle #" << i + 1 << ":\n";
        for (int j = 0; j < 9; j++) {
            inputFile >> puzzleData[j];
            std::cout << puzzleData[j] << ' ';
            if ((j + 1) % 3 == 0) { std::cout << '\n'; }
        }
        Puzzle* p = new Puzzle(puzzleData);
        Solver s(p);

        auto start = std::chrono::steady_clock::now();

        if(s.HasSolution()) {
            s.SolvePuzzle();
        }
        else std::cout << "No Solution\n";

        auto diff = std::chrono::steady_clock::now() - start;
        std::cout << "Elapsed time: " << std::chrono::duration <double, std::milli> (diff).count() << " ms\n\n";
        totalTime += diff;
    }

    std::cout << "Total time for all puzzles: " << (totalTime).count() << "ms\n\n";

    inputFile.close();
    return 0;
}