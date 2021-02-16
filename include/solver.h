#ifndef SOLVER_H
#define SOLVER_H

#include <set>
#include <queue>
#include <string>

#include "puzzle.h"
#include "node.h"

class SolverCompare {
public:
    bool operator()(Node *left, Node *right) {
        return (left->state->g + left->state->h) > (right->state->g + right->state->h);
    }
};

class Solver {
public:
    std::set<std::string> generated;
    std::priority_queue<Node*, std::vector<Node*>, SolverCompare> unvisited;
    int statesTested;

    Solver(Puzzle* start);

    bool HasSolution();
    void ExpandNode();
    void SolvePuzzle();
};

#endif // SOLVER_H