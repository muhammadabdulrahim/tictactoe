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
	//	TODO: Pick first spot available
	if( is_board_full(*b) )
	{
		puts("ERROR: AI CANNOT MAKE ANY LEGAL MOVE");
		exit(-1);
	}

	int i=0;
	for( i=0; i<BOARD_SIZE; i++ )
	{
		if( (*b).tokens[i]==TOKEN_NONE )
		{
			set_token(b,TOKEN_O,i);
			return;
		}
	}

	puts("ERROR: AI CANNOT MAKE ANY LEGAL MOVE");
	exit(-1);
}

/* Set the given token in a given position */
void set_token(board *b, short int token, short int position)
{
	printf("Token: %d, Position: %d\n",token,position);
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

/* Print the board to the terminal */
void print_board(board b)
{
	printf("%c|%c|%c\n",
		get_token(b.tokens[TOP_LEFT]),
		get_token(b.tokens[TOP_CENTER]),
		get_token(b.tokens[TOP_RIGHT])
	);

	printf("%c|%c|%c\n",
		get_token(b.tokens[CENTER_LEFT]),
		get_token(b.tokens[CENTER_CENTER]),
		get_token(b.tokens[CENTER_RIGHT])
	);

	printf("%c|%c|%c\n",
		get_token(b.tokens[BOTTOM_LEFT]),
		get_token(b.tokens[BOTTOM_CENTER]),
		get_token(b.tokens[BOTTOM_RIGHT])
	);

	puts("");
}