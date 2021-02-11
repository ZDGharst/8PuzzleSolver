#include "puzzle.h"

Puzzle::Puzzle(std::string s, int g) {
    state = s;
    this->g = g;
    h = TotalManhattanDistance();
}

/* increase or decrease by 1 (move right/left) until the difference between them is
/  divisible by three then increase or decrease by 3 (move down/up)
/
/  3 1 2
/  4 6 5
/  8 7 E
/
/  3 is at pos 0 but should be at pos 2
/  n is at pos i but should be at pos (n - 1)
*/
int Puzzle::TotalManhattanDistance() {
    int piece, position;
    int sum = 0;

    for(int i = 0; i < 9; i++) {
        if(state[i] == 'E') {
            continue;
        }

        piece = state[i] - 48; // convert from ASCII char to integer equivalent
        position = i + 1;

        while(piece != position) {
            if((piece - position) % 3 == 0) { // move down
                if(position > piece) position -= 3;
                else position += 3;
                sum++;
            }
            else { // move right
                if(position > piece) position--;
                else position++;
                sum++;
            }

            if(position > 100) break;
        }
    }

    return sum;
    }

int Puzzle::SingleManhattanDistance(int p) {
    for(int i = 1; i < 9; i++) {

    }
    return 0;
}

int Puzzle::FindPiece(char p) {
    for(int i = 0; i < 9; i++) {
        if(state[i] == p) {
            return i;
        }
    }

    return -1;
}