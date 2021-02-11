#ifndef NODE_H
#define NODE_H

#include "puzzle.h"

class Node {
public:
    Puzzle* state;
    Node* parent;
    
    Node(Puzzle* s, Node* p);

    bool operator<(const Node& node2) const;
};

#endif // NODE_H