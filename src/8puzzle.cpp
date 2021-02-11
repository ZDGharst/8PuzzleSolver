#include "puzzle.h"
#include <iostream>

int main() {
    Puzzle p("31246587E");
    std::cout << p.TotalManhattanDistance() << '\n';

    return 0;
}