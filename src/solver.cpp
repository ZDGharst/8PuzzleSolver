#include "solver.h"
#include <stack>
#include <iostream>

Solver::Solver(Puzzle* start) {
    Node* nodeStart = new Node(start, NULL, 'S');
    unvisited.push(nodeStart);
}

bool Solver::HasSolution() {
    std::string data = unvisited.top()->state->state;
    int inversions = 0;

    for(int i = 0; i < 9; i++)
        for(int j = i + 1; j < 9; j++)
            if(data[i] > data[j] && data[i] != 'E' && data[j] != 'E')
                inversions++;

    if(inversions % 2 == 0)
        return true;
    return false;
}

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
            Node* childNode = new Node(p, parentNode, 'R');
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
            Node* childNode = new Node(p, parentNode, 'L');
            unvisited.push(childNode);
        }
        
        tempData = data;
    }

    /* Move E space up if possible. */
    if(positionOfEmpty > 3) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty - 3];
        tempData[positionOfEmpty - 3] = 'E';
        
        if(visited.find(tempData) == visited.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, 'D');
            unvisited.push(childNode);
        }
        
        tempData = data;
    }

    /* Move E space down if possible. */
    if(positionOfEmpty < 7) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty + 3];
        tempData[positionOfEmpty + 3] = 'E';
        
        if(visited.find(tempData) == visited.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, 'U');
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

    std::cout << moveOrder.top() << "]\n\n";
}