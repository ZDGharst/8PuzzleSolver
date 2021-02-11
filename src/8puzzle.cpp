#include "solver.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile;
    inputFile.open("input.txt");

    if(!inputFile) {
        return -1;
    }

    int numPuzzles;
    inputFile >> numPuzzles;
    
    for(int i = 0; i < 3; i++) {
        std::string puzzleData = "         ";
        std::cout << "Puzzle #" << i + 1 << ":\n";
        for (int j = 0; j < 9; j++) {
            inputFile >> puzzleData[j];
            std::cout << puzzleData[j] << ' ';
            if ((j + 1) % 3 == 0) { std::cout << '\n'; }
        }
        Puzzle* p = new Puzzle(puzzleData);
        Solver s(p);

        if(s.HasSolution()) {
            s.SolvePuzzle();
        }
        else std::cout << "No solution\n\n";
    }

    inputFile.close();
    return 0;
}