#include "solver.h"

Solver::Solver(Puzzle& start) {
    Node nodeStart(start, NULL);
    unvisited.push(nodeStart);
}

bool Solver::HasSolution() {
    std::string data = unvisited.top().state->state;
    int inversions = 0;

    for(int i = 0; i < 9; i++)
        for(int j = i + 1; j < 9; j++)
            if(data[i] > data[j] && data[i] != 'E' && data[j] != 'E')
                inversions++;

    if(inversions % 2 == 0)
        return true;
    return false;
}