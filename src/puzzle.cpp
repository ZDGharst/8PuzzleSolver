#include "puzzle.h"

Puzzle::Puzzle(std::string s, int g) {
    state = s;
    this->g = g;
    h = TotalManhattanDistance();
}

int Puzzle::TotalManhattanDistance() {
    int sum = 0;

    for(int i = 0; i < 9; i++) {
        sum += SingleManhattanDistance(i);
    }

    return sum;
    }

int Puzzle::SingleManhattanDistance(int position) {
    if(state[position] == 'E') {
        return 0;
    }

    int sum = 0;

    /* Convert from ASCII character to integer equivalent and increment position
     * by 1 to correct for 0-indexed arrays. */
    int piece = state[position] - 48;
    position++;

    while(piece != position) {
        /* Move up or down */
        if((piece - position) % 3 == 0) {
            if(position > piece) position -= 3;
            else position += 3;
            sum++;
        }

        /* Move left or right */
        else {
            if(position > piece) position--;
            else position++;
            sum++;
        }
    }

    return sum;
}

int Puzzle::FindPiecePosition(char p) {
    for(int i = 0; i < 9; i++) {
        if(state[i] == p) {
            return i;
        }
    }

    return -1;
}