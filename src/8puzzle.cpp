#include "puzzle.h"
#include <iostream>

int main() {
    Puzzle p("31246587E");
    std::cout << p.FindPiece('4') << '\n';

    return 0;
}