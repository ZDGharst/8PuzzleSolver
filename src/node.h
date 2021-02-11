#ifndef NODE_H
#define NODE_H

#include "puzzle.h"

class Node {
public:
    Puzzle* state;
    Node* parent;
    char direction;
    
    Node(Puzzle* s, Node* p, char direction);

    bool operator<(const Node& node2) const;
};

#endif // NODE_H