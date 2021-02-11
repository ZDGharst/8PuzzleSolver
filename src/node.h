#ifndef NODE_H
#define NODE_H

class Node {
    Puzzle state;
    Node parent;
    
    Node(Puzzle s, Node p);
    void CreateChildren();
}

#endif // NODE_H