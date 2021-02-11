#include "node.h"

Node::Node(Puzzle* state, Node* parent) {
    this->state = state;
    this->parent = parent;
}

bool Node::operator<(const Node& node2) const {
    return state->g + state->h < node2.state->g + node2.state->h;
}