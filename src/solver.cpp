#include "solver.h"

Solver::Solver(Puzzle* start) {
    Node nodeStart(start, NULL);
    unvisited.push(nodeStart);
}

bool Solver::HasSolution() {
    std::string data = unvisited.top().state->state;
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
    Node parentNode = unvisited.top();
    std::string data = parentNode.state->state;
    int positionOfEmpty = parentNode.state->FindPiecePosition('E');

    /* Remove from queue and insert into visited set. */
    unvisited.pop();
    visited.insert(data);

    /* Move E space left if possible. */
    std::string tempData = data;
    if(positionOfEmpty % 3 != 0) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty - 1];
        tempData[positionOfEmpty - 1] = 'E';
        
        Puzzle* p = new Puzzle("4E2516738", parentNode.state->g + 1);
        Node childNode(p, NULL);
        unvisited.push(childNode);
        tempData = data;
    }

    /* Move E space right if possible. */
    if(positionOfEmpty % 3 != 2) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty + 1];
        tempData[positionOfEmpty + 1] = 'E';

    }

    /* Move E space up if possible. */
    if(positionOfEmpty > 3) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty - 3];
        tempData[positionOfEmpty - 3] = 'E';

        tempData = data;
    }

    /* Move E space down if possible. */
    if(positionOfEmpty < 7) {
        tempData[positionOfEmpty] = tempData[positionOfEmpty + 3];
        tempData[positionOfEmpty + 3] = 'E';
 /*
        Puzzle p(tempData);
        Node childNode(p, parentNode);
        unvisited.push(childNode); /*/
    }
}