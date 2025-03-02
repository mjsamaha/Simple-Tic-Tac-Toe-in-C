#include <stdio.h> 
#include <stdlib.h> // for the game to make random moves
#include <time.h> // seed random num generator

/* defining constants */
#define PLAYER 'X' 
#define COMPUTER 'O' 
#define EMPTY ' ' 

char board[9]; 

/* setting the board all empty at the start */
void initBoard(){
	for (int i = 0; i < 9; i++){
		board[i] = EMPTY; // fill all elements with empty spaces
	}
}

/* print tic tac toe board with coord for the user */
void printReferenceBoard(){
	printf("\nReference Board:\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n\n");
}

/* printing the board in a 3x3 format -- using % to add | */
void printBoard() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            printf(" %d ", i + 1);  // Show available position number
        } else {
            printf(" %c ", board[i]);  // Show 'X' or 'O'
        }
        
        if ((i + 1) % 3 == 0)
            printf("\n");
        else
            printf("|");
        
        if (i == 2 || i == 5)
            printf("---+---+---\n");
    }
    printf("\n");
}

/* checking if empty spaces are left to take */
int isMovesLeft(){
	for (int i = 0; i < 9; i++){
		if (board[i] == EMPTY){
			return 1; // if any spaces are empty, true
		}
	}
	return 0; // none are left
}

/* checks for a winning condition */
int checkWinPattern(char symbol){
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        int a = winPatterns[i][0], b = winPatterns[i][1], c = winPatterns[i][2];

        if (board[a] == symbol && board[b] == symbol && board[c] == symbol) {
            return 1; // Winning pattern found
        }
    }
    return 0; // No win found
}

/* calls the checkWinPattern instead of repeating the loop */
int checkWinner() {
    if (checkWinPattern(PLAYER)) return 1; // Player wins
    if (checkWinPattern(COMPUTER)) return 2; // Computer wins
    return 0; // No winner yet
}


/* checking for a winner */

/* looping through to check all possible winning patterns
 * If three matching marks (x) or (o) are found, it returns that winner
 */

int findWinningMove(char symbol) {
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        int a = winPatterns[i][0], b = winPatterns[i][1], c = winPatterns[i][2];
        
        // Check if two positions match symbol, and third is empty
        if (board[a] == symbol && board[b] == symbol && board[c] == EMPTY) return c;
        if (board[a] == symbol && board[c] == symbol && board[b] == EMPTY) return b;
        if (board[b] == symbol && board[c] == symbol && board[a] == EMPTY) return a;
    }

    return -1; // No winning or blocking move found
}
