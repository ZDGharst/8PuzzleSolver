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

    void ExpandNode();
    void SolvePuzzle();
    bool HasSolution();
};