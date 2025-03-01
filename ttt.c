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
