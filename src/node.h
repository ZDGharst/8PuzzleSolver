#ifndef NODE_H
#define NODE_H

#include "puzzle.h"

class Node {
public:
    Puzzle* state;
    Node* parent;
    char direction;
    
    Node(Puzzle* s, Node* p, char direction);
};

#endif // NODE_H