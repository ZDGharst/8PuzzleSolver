#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

class Puzzle {
public:
    std::string state;
    int g, h;
    
    Puzzle(std::string state, int g = 0);

    int TotalManhattanDistance();
    int SingleManhattanDistance(int position);
    int FindPiecePosition(char piece);
};

#endif // PUZZLE_H