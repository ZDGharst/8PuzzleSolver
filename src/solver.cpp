#include "solver.h"
#include <stack>
#include <iostream>

Solver::Solver(Puzzle* start) {
    Node* nodeStart = new Node(start, NULL, 'S');
    unvisited.push(nodeStart);
}

/* A puzzle has a solution if the number of times a larger piece has been moved compared to a smaller piece is even (or if divisible by the size of puzzle-1). */
bool Solver::HasSolution() {
    std::string data = unvisited.top()->state->state;
    int inversions = 0;

    for(int i = 0; i < 8; i++)
        for(int j = i + 1; j < 9; j++)
        /* It's okay if data[j] is E because E is always greater than the numbers */
            if(data[i] != 'E' && data[i] > data[j])
                inversions++;

    return (inversions % 2 == 0);
}

/* This could result in a faster solve if we were to check not only the visited nodes
but also the unvisited nodes before generating new children. */
void Solver::ExpandNode() {
    Node* parentNode = unvisited.top();
    std::string data = parentNode->state->state;
    int positionOfEmpty = parentNode->state->FindPiecePosition('E');

    /* Remove from queue and insert into visited set. */
    unvisited.pop();
    visited.insert(data);

    /* Move E space left if possible. */
    std::string tempData = data;
    if(positionOfEmpty % 3 != 0) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty - 1];
        tempData[positionOfEmpty - 1] = 'E';

        if(visited.find(tempData) == visited.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
        }
        
        tempData = data;
    }

    /* Move E space right if possible. */
    if(positionOfEmpty % 3 != 2) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty + 1];
        tempData[positionOfEmpty + 1] = 'E';
        
        if(visited.find(tempData) == visited.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
        }
        
        tempData = data;
    }

    /* Move E space up if possible. */
    if(positionOfEmpty > 2) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty - 3];
        tempData[positionOfEmpty - 3] = 'E';
        
        if(visited.find(tempData) == visited.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
        }
        
        tempData = data;
    }

    /* Move E space down if possible. */
    if(positionOfEmpty < 6) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty + 3];
        tempData[positionOfEmpty + 3] = 'E';
        
        if(visited.find(tempData) == visited.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
        }
    }
}

void Solver::SolvePuzzle() {
    while(unvisited.top()->state->state != "12345678E") {
        ExpandNode();
    }

    Node* pathNode = unvisited.top();
    std::stack<char> moveOrder;
    int i = 0;
    while(pathNode->parent != NULL) {
        moveOrder.push(pathNode->direction);
        pathNode = pathNode->parent;
        i++;
    }

    std::cout << "Solution (" << i << " moves): [";

    while(moveOrder.size() > 1) {
        std::cout << moveOrder.top() << ", ";
        moveOrder.pop();
    }

    std::cout << moveOrder.top() << "]\nStates tested: " << visited.size() + 1 << "\n\n";
}
