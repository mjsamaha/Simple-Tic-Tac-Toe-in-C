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

/* checking for a winner */

/* looping through to check all possible winning patterns
 * If three matching marks (x) or (o) are found, it returns that winner
 */

int checkWinner(){
	// all winning combinations
	int winPatterns[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // cows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
        {0, 4, 8}, {2, 4, 6}              // diagonals
	};
	
	for (int i = 0; i < 8; i++){
		int a = winPatterns[i][0], b = winPatterns[i][1], c = winPatterns[i][2];
		
		// checking if all three spots match and are not empty
		if (board[a] == board[b] && board[b] == board[c] && board[a] != EMPTY){
			return (board[a] == PLAYER) ? 1 : 2; // 1 = player wins, 2 = computer wins
		}
	}
	return 0;
}

void playerMove(){
	int move;
    char buffer; // Used to clear invalid input

    do {
        printf("Enter your move (1-9): ");
        
        // Check if input is a valid integer
        if (scanf("%d", &move) != 1) {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            
            // Clear invalid input
            while ((buffer = getchar()) != '\n' && buffer != EOF);
            continue; // Restart the loop
        }

        move--; // Convert user input (1-9) to array index (0-8)

        // Check if move is valid (within range and unoccupied)
        if (move < 0 || move >= 9 || board[move] != EMPTY) {
            printf("Invalid move! Choose an empty position between 1 and 9.\n");
        }

    } while (move < 0 || move >= 9 || board[move] != EMPTY);

    board[move] = PLAYER; // Places 'X' on the board
	
}

/* no engine algorithm: computer makes a random legal move */
void computerMove(){
	int move;
	do {
		move = rand() % 8; // pick a random number from 0-9
	} while (board[move] != EMPTY);  // ensure that spot is empty
		board[move] = COMPUTER; // places 'O' on the board
	
}

void mainGameLoop(){
	initBoard(); // reset board
	printReferenceBoard(); // show coords reference before game starts
	printBoard(); // show empty board
	
	while (isMovesLeft()){
		playerMove(); // player starts first
		printBoard(); 
		
		if (checkWinner() == 1){
			printf("You beat the machine!\n");
			return;
		}
		if (!isMovesLeft()) break; // stop if board becomes full
		
		computerMove();
		printBoard();
		
		if (checkWinner() == 2){
			printf("Sorry!! -- You lost!\n");
			return;
		}
	}
	
	printf("It's a draw!\n"); 
}

// main function
int main(){
	srand(time(0)); // seed random num for computer moves
	mainGameLoop(); // start game
	return 0;
}
