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
