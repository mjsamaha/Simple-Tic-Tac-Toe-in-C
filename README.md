# Simple-Tic-Tac-Toe-in-C
Simple Tic Tac Toe in C with an easy randomized move generation. Learning C through use of textbooks is cool and all, but making game is more fun.

## Game Structure
- Player places an 'X' while the computer places an 'O'
- Computer plays randomly, ensuring they only play legal moves


### The Computer's "engine" in this simple implementation:
In this simple approach to tic-tac-toe, I implemented a simple random move generation, where the machine picks any available position on the board...
- simply chooses any empty position at random, it does not find any 'winning' moves or evaluate.
- purely simple for practice

## Defining Our Board and Global Variables
**A 1D Array**
- 3D arrays makes things more complicated in indexing and reducing the complexities, so I'll be using a 1D array, with a size of 9, instead of over-complicating with a 3x3 Matrix.
- 3x3 board would be like `board[row][col]` which seems not as complicated, but I wanted a simpler approach: `board[index]`

```
/* defining constants */
#define PLAYER 'X' // user symbol
#define COMPUTER 'O' // computer's symbol
#define EMPTY ' ' // defines empty space on board

char board[9]; 
```

### Create the function to initialize the board
Set every board to an empty char cell at the start
```
void initBoard(){
	for (int i = 0; i < 9; i++){
		board[i] = EMPTY; // fill all elements with empty spaces
	}
}
```

### Printing a reference board
This makes it so players can see the numbers(index), of which correspond on the board
- Hopefully this helps you choose moves more faster and easily
```
void printReferenceBoard(){
	printf("\nReference Board:\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n\n");
}
```

### Printing the Current Game Board
We need to print the current updated game board as it is, displaying the X's and O's, and also showcase the numbers (positions) for empty spaces
This seems complex, but I'll break it down:
- loop through all 9 positions in the array (0-8)
- if board pos is empty (' '), print the position number, so player's knows where to play their moves
- otherwise, we print the current value ('X' or 'O')
- after every 3 elements, (end of row), we add a new line, or print | to separate columns
- adding horizontal dividiers after row 1 and row 2
- i == 2 (end of row 1), or i == 5 (end of row 2), then we print a horizontal divider --> ---+---+----


```
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
```


### Checking for Available Legal Moves
This function will check if a space is empty, in which it is, we return 1 (moves are available to make)
- if board is full, we return 0; game ends
```
int isMovesLeft(){
	for (int i = 0; i < 9; i++){
		if (board[i] == EMPTY){
			return 1; // if any spaces are empty, true
		}
	}
	return 0; // none are left
}
```

### Checking for a Winner
We need to add a function that defines winning conditions, by creating those conditions, and comparing those positions with all winning patterns
Here is a step by step breakdown of how to implement this:
- all winning combinations are stored in an array, of a sub-array {a, b, c}, which form a winning line
- in tic-tac-toe, you only win by forming a solid row, column, or diagonal with 3 board positions
- in this, we're going to loop through all 8 winning conditions constantly, until a winning combination was found
- we check if all 3 positions in the current winning pattern have that same symbol (player or computer)
X X X win for user
O O O win for computer
X O X no win, we continue checking
- if a winning condition is true; stop the checking loop
- if no winning pattern is found, return 0; (game continues until board is complete)

```
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
```
