#ifndef SOLVER_H
#define SOLVER_H

#include <set>
#include <queue>
#include <string>

#include "puzzle.h"
#include "node.h"

class MyCompare {
public:
  template<typename T>
  bool operator()(T *a, T *b) {
    return (a->state->g + a->state->h) > (b->state->g + b->state->h);
  }
};

class Solver {
public:
    std::set<std::string> visited;
    std::priority_queue<Node*, std::vector<Node*>, MyCompare> unvisited;

    Solver(Puzzle* start);

    bool HasSolution();
    void ExpandNode();
    void SolvePuzzle();
};

#endif // SOLVER_H