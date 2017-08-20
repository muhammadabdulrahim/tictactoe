#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tictactoe.h"

/* Set all board tokens to TOKEN_NONE */
void clear_board(board *b)
{
	int i;
	for( i=0; i<BOARD_SIZE; i++ )
	{
		set_token(b,TOKEN_NONE,i);
	}
}

/* Logic for AI move decision making */
void make_ai_move(board *b)
{
	int i;
	for( i=0; i<BOARD_SIZE; i++ )
	{
		if( (*b).tokens[i]==TOKEN_NONE )
		{
			set_token(b,TOKEN_O,i);
			return;
		}
	}
}

/* Set the given token in a given position */
void set_token(board *b, short int token, short int position)
{
	(*b).tokens[position] = token;
}

/* Get the string representation of the token at the position */
char get_token(short int token)
{
	return token == TOKEN_X ? 'X' : token == TOKEN_O ? 'O' : '-';
}

/* Check if board is full */
bool is_board_full(board b)
{
	int i;
	for( i=0; i<BOARD_SIZE; i++ )
	{
		if( b.tokens[i]==TOKEN_NONE)
			return false;
	}
	return true;
}

/* Get the winner, if any */
int get_winner(board b)
{
	// Top horizontal
	if(
		b.tokens[TOP_LEFT] != TOKEN_NONE && 
		b.tokens[TOP_LEFT] == b.tokens[TOP_CENTER] &&
		b.tokens[TOP_LEFT] == b.tokens[TOP_RIGHT]
	)
	{
		return b.tokens[TOP_LEFT]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Center horizontal
	if(
		b.tokens[CENTER_LEFT] != TOKEN_NONE && 
		b.tokens[CENTER_LEFT] == b.tokens[CENTER_CENTER] &&
		b.tokens[CENTER_LEFT] == b.tokens[CENTER_RIGHT]
	)
	{
		return b.tokens[CENTER_LEFT]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Bottom horizontal
	if(
		b.tokens[BOTTOM_LEFT] != TOKEN_NONE && 
		b.tokens[BOTTOM_LEFT] == b.tokens[BOTTOM_CENTER] &&
		b.tokens[BOTTOM_LEFT] == b.tokens[BOTTOM_RIGHT]
	)
	{
		return b.tokens[BOTTOM_LEFT]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Left vertical
	if(
		b.tokens[TOP_LEFT] != TOKEN_NONE &&
		b.tokens[TOP_LEFT] == b.tokens[CENTER_LEFT] &&
		b.tokens[TOP_LEFT] == b.tokens[BOTTOM_LEFT]
	)
	{
		return b.tokens[TOP_LEFT]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Center vertical
	if(
		b.tokens[TOP_CENTER] != TOKEN_NONE &&
		b.tokens[TOP_CENTER] == b.tokens[CENTER_CENTER] &&
		b.tokens[TOP_CENTER] == b.tokens[BOTTOM_CENTER]
	)
	{
		return b.tokens[TOP_CENTER]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Right vertical
	if(
		b.tokens[TOP_RIGHT] != TOKEN_NONE &&
		b.tokens[TOP_RIGHT] == b.tokens[CENTER_RIGHT] &&
		b.tokens[TOP_RIGHT] == b.tokens[BOTTOM_RIGHT]
	)
	{
		return b.tokens[TOP_RIGHT]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Top-left to bottom-right diagonal
	if(
		b.tokens[TOP_LEFT] != TOKEN_NONE &&
		b.tokens[TOP_LEFT] == b.tokens[CENTER_CENTER] &&
		b.tokens[TOP_LEFT] == b.tokens[BOTTOM_RIGHT]
	)
	{
		return b.tokens[TOP_LEFT]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Bottom-left to top-right diagonal
	if(
		b.tokens[BOTTOM_LEFT] != TOKEN_NONE &&
		b.tokens[BOTTOM_LEFT] == b.tokens[CENTER_CENTER] &&
		b.tokens[BOTTOM_LEFT] == b.tokens[TOP_RIGHT]
	)
	{
		return b.tokens[BOTTOM_LEFT]==TOKEN_X ? WINNER_PLAYER : WINNER_AI;
	}

	// Check if tie condition is met
	return is_board_full(b) ? WINNER_TIE : WINNER_NONE;
}

/* Print the board to the terminal */
void print_board(board b)
{
	printf("  %c|%c|%c\n",
		get_token(b.tokens[TOP_LEFT]),
		get_token(b.tokens[TOP_CENTER]),
		get_token(b.tokens[TOP_RIGHT])
	);

	printf("  %c|%c|%c\n",
		get_token(b.tokens[CENTER_LEFT]),
		get_token(b.tokens[CENTER_CENTER]),
		get_token(b.tokens[CENTER_RIGHT])
	);

	printf("  %c|%c|%c\n",
		get_token(b.tokens[BOTTOM_LEFT]),
		get_token(b.tokens[BOTTOM_CENTER]),
		get_token(b.tokens[BOTTOM_RIGHT])
	);

	puts("");
}