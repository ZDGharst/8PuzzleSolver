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

/* Calculate the manhattan distance of a single position in the puzzle data array (from 0 to 8) */
int Puzzle::SingleManhattanDistance(int p) {
    if(state[p] == 'E') {
        return 0;
    }

    int sum = 0;
    int piece = state[p] - 48; // Convert from ASCII char to integer equivalent
    int position = p + 1;

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

/* Find where a piece is in the puzzle data array by its value */
int Puzzle::FindPiece(char p) {
    for(int i = 0; i < 9; i++) {
        if(state[i] == p) {
            return i;
        }
    }

    return -1;
}