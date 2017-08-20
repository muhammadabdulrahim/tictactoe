#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tictactoe.h"

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