#ifndef __TICTACTOE__
#define __TICTACTOE__

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

enum winner {
	WINNER_NONE,
	WINNER_TIE,
	WINNER_PLAYER,
	WINNER_AI
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
int get_winner(board b);
void print_board(board b);

#endif