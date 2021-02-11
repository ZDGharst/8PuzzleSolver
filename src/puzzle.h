#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
    std::string state;
    int g, h;
    
    Puzzle(std::string s, int g = 0);

    int TotalManhattanDistance();
    int SingleManhattanDistance(int p);
    int FindPiece(int p);
}

#endif // PUZZLE_H