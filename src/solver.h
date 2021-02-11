#ifndef SOLVER_H
#define SOLVER_H

#include <set>
#include <queue>
#include <string>

#include "puzzle.h"
#include "node.h"

class Solver {
public:
    std::set<std::string> visited;
    std::priority_queue<Node> unvisited;

    Solver(Puzzle& start);

    bool HasSolution();
    void ExpandNode();
    void SolvePuzzle();
};

#endif // SOLVER_H