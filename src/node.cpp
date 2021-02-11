#include "node.h"

Node::Node(Puzzle* state, Node* parent) {
    this->state = state;
    this->parent = parent;
}