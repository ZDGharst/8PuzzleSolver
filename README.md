### 8 Puzzle
This project solves an 8 piece sliding puzzle solution using the A* algorithm. The heuristic is Manhattan distance: the minimum amount of moves needed to complete the puzzle if collision is allowed.

Receives input from the file at **data/input.txt**. Input is expected as the number of puzzles followed by each puzzle. Input is not sanitized or checked.

Type "make" in the terminal in the project folder to compile and run the project.

Credit goes to [Geeks for Geeks](https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/) for their instructions on how to calculate the possibility of a puzzle being unsolvable. There are 9! possible states, but only 9!/2 solvable states.

## Optimizations:
I originally calculated the manhattan distance for a single piece using this method:


	int Puzzle::SingleManhattanDistance(int position) {
		if(state[position] == 'E') return 0;
		
		int sum = 0;

		/* Convert from ASCII character to integer equivalent and increment position
		 * by 1 to correct for 0-indexed arrays. */
		int piece = state[position] - 48;

		while(piece != position) {
		    /* Move up or down */
		    if((piece - position) % 3 == 0) {
		        if(position > piece) position -= 3;
		        else position += 3;
		        sum++;
		    }

		    /* Move left or right */
		    else {
		        /* Flatten the possibilities to 1, 2, or 3 in order in order to compare which column.
		         * Otherwise, 4 > 3 would result in 4 moving right when it should move left. */
		        if((position + 2) % 3 > (piece + 2) % 3) position--;
		        else position++;
		        sum++;
		    }
		}

		return sum;
	}

I optimized it algebraically to this:


	int Puzzle::SingleManhattanDistance(int position) {
		if(state[position] == 'E') return 0;

		/* Convert from ASCII character to integer equivalent and increment position
		 * by 1 to correct for 0-indexed arrays. */
		int pieceValue = state[position] - 48;
		int rowDifference = abs((pieceValue - 1) / 3 - position / 3);
		int columnDifference = abs((pieceValue - 1) % 3 - position % 3);

		return rowDifference + columnDifference;
	}
