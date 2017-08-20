#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9

enum token {
	TOKEN_NONE,
	TOKEN_X,
	TOKEN_O
};

enum position {
	TOP_LEFT,//0
	TOP_CENTER,
	TOP_RIGHT,
	CENTER_LEFT,
	CENTER_CENTER,
	CENTER_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT
};

typedef struct struct_board
{
	short int tokens[BOARD_SIZE];
} board;


void clear_board(board *b);
void make_ai_move(board *b);
void set_token(board *b, short int token, short int position);
char get_token(short int token);
bool is_board_full(board b);
void print_board(board b);

void clear_board(board *b)
{
	int i;
	for( i=0; i<BOARD_SIZE; i++ )
	{
		set_token(b,TOKEN_NONE,i);
	}
}


//	Assume AI is always O
void make_ai_move(board *b)
{
	//	TODO: Pick first spot available
	if( is_board_full(*b) )
	{
		printf("ERROR: AI CANNOT MAKE ANY LEGAL MOVE");
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


void set_token(board *b, short int token, short int position)
{
	//	TODO: Assume position is in bounds
	printf("Token: %d, Position: %d\n",token,position);
	(*b).tokens[position] = token;
}

char get_token(short int token)
{
	return token == TOKEN_X ? 'X' : token == TOKEN_O ? 'O' : '-';
}

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


int main()
{
	board b;
	clear_board(&b);
	set_token(&b,TOKEN_X,TOP_CENTER);
	puts("AI will make moves:");
	while( true )
	{
		make_ai_move(&b);
		print_board(b);
	}

	//set_token(&b,TOKEN_X,TOP_CENTER);
	//print_board(b);
	//printf("Is board full? %d\n",is_board_full(b));



	return 0;
}