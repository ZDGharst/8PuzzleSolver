#include "node.h"

Node::Node(Puzzle* state, Node* parent, char direction) {
    this->state = state;
    this->parent = parent;
    this->direction = direction;
}