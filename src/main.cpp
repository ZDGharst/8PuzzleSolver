#include "solver.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile;
    inputFile.open("data/input.txt");

    std::ofstream outputFile;
    outputFile.open("data/output.txt");

    if(!inputFile) {
        return -1;
    }

    int numPuzzles;
    inputFile >> numPuzzles;

    for(int i = 0; i < numPuzzles; i++) {
        std::string puzzleData = "         ";
        for (int j = 0; j < 9; j++) {
            inputFile >> puzzleData[j];
        }

        Puzzle* p = new Puzzle(puzzleData);
        Solver s(p);

        s.SolvePuzzle();

        outputFile << s.PrintSolution(i + 1);
    }

    inputFile.close();
    outputFile.close();

    return 0;
}