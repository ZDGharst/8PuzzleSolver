#ifndef SOLVER_H
#define SOLVER_H

#include <set>
#include <queue>
#include <string>
#include <stack>
#include <chrono>

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
    std::queue<Node*> visited;
    std::priority_queue<Node*, std::vector<Node*>, SolverCompare> unvisited;
    std::stack<char> moveOrder;
    int statesTested;
    std::string startString;
    std::chrono::time_point<std::chrono::steady_clock> startTime = std::chrono::steady_clock::now();

    Solver(Puzzle* start);
    ~Solver();
    
    bool HasSolution();
    void ExpandNode();
    void SolvePuzzle();
    std::string PrintSolution(int puzzleNum = -1);
};

#endif // SOLVER_H