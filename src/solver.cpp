#include "solver.h"

Solver::Solver(Puzzle* start) {
    Node* nodeStart = new Node(start, NULL, 'S');
    unvisited.push(nodeStart);
    generated.insert(start->state);
    statesTested = 0;
    startString = start->state;
}

Solver::~Solver() {
    while(!visited.empty()) {
        delete visited.front();
        visited.pop();
    }
    
    while(!unvisited.empty()) {
        delete unvisited.top();
        unvisited.pop();
    }
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
    visited.push(parentNode);
    generated.insert(data);
    statesTested++;

    /* Move E space left if possible. */
    std::string tempData = data;
    if(positionOfEmpty % 3 != 0) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty - 1];
        tempData[positionOfEmpty - 1] = 'E';

        if(generated.find(tempData) == generated.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
            generated.insert(tempData);
        }
        
        tempData = data;
    }

    /* Move E space right if possible. */
    if(positionOfEmpty % 3 != 2) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty + 1];
        tempData[positionOfEmpty + 1] = 'E';
        
        if(generated.find(tempData) == generated.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
            generated.insert(tempData);
        }
        
        tempData = data;
    }

    /* Move E space up if possible. */
    if(positionOfEmpty > 2) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty - 3];
        tempData[positionOfEmpty - 3] = 'E';
        
        if(generated.find(tempData) == generated.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
            generated.insert(tempData);
        }
        
        tempData = data;
    }

    /* Move E space down if possible. */
    if(positionOfEmpty < 6) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty + 3];
        tempData[positionOfEmpty + 3] = 'E';
        
        if(generated.find(tempData) == generated.end()) {
            Puzzle* p = new Puzzle(tempData, parentNode->state->g + 1);
            Node* childNode = new Node(p, parentNode, tempData[positionOfEmpty]);
            unvisited.push(childNode);
            generated.insert(tempData);
        }
    }
}

void Solver::SolvePuzzle() {
    if(!HasSolution()) {
        return;
    }
    while(unvisited.top()->state->state != "12345678E") {
        ExpandNode();
    }

    Node* pathNode = unvisited.top();
    while(pathNode->parent != NULL) {
        moveOrder.push(pathNode->direction);
        pathNode = pathNode->parent;
    }
}

std::string Solver::PrintSolution(int puzzleNum) {
    std::string solutionString = "Puzzle";

    if(puzzleNum != -1) {
        solutionString += " #";
        solutionString += std::to_string(puzzleNum);
    }

    solutionString += "\n";

    for(int piece = 0; piece < 9; piece++) {
        solutionString += startString[piece];
        solutionString += ((piece + 1) % 3 == 0) ? "\n" : " ";
    }

    if(moveOrder.size() > 0) {
        solutionString += "Solution (";
        solutionString += std::to_string(moveOrder.size());
        solutionString += " moves): [";

        while(moveOrder.size() > 1) {
            solutionString += moveOrder.top();
            solutionString += ", ";
            moveOrder.pop();
        }

        auto diff = std::chrono::steady_clock::now() - startTime;

        solutionString += moveOrder.top();
        solutionString += "]\nStates tested: ";
        solutionString += std::to_string(statesTested);
        solutionString += "\nStates generated: ";
        solutionString += std::to_string(generated.size() + 1);
        solutionString += "\nElapsed time: ";
        solutionString += std::to_string(std::chrono::duration <double, std::milli> (diff).count());
        solutionString += " ms\n\n";
    }
     
    else {
        solutionString += "No Solution\n\n";
    }

    return solutionString;
}