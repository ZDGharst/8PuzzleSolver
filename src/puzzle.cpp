#include "puzzle.h"

Puzzle::Puzzle(std::string s, int g) {
    state = s;
    this->g = g;
    h = TotalManhattanDistance();
}

int Puzzle::TotalManhattanDistance() {
    int sum = 0;

    for(int i = 0; i < 9; i++)
        sum += SingleManhattanDistance(i);

    return sum;
}

int Puzzle::SingleManhattanDistance(int position) {
    if(state[position] == 'E') return 0;

    /* Convert from ASCII character to integer equivalent and increment position
     * by 1 to correct for 0-indexed arrays. */
    int pieceValue = state[position] - 48;
    int rowDifference = abs((pieceValue - 1) / 3 - position / 3);
    int columnDifference = abs((pieceValue - 1) % 3 - position % 3);

    return rowDifference + columnDifference;
}

int Puzzle::FindPiecePosition(char p) {
    for(int i = 0; i < 9; i++)
        if(state[i] == p)
            return i;

    return -1;
}