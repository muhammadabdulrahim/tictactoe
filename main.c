#include <stdio.h>
#include <stdbool.h>
#include "tictactoe.h"

int get_move()
{
	int move;
	char input[64];
	if( fgets(input,sizeof(input),stdin) )
	{
		if( 1 == sscanf(input,"%d",&move) )
		{
			return move-1;
		}
	}
	return -1;
}

int main()
{
	// Initialize board
	board b;
	clear_board(&b);

	// Main game loop
	bool do_game_loop = true;
	while( do_game_loop )
	{
		// Display board at start of loop
		print_board(b);

		// Player turn
		puts("PLAYER TURN");
		puts("  1|2|3");
		puts("  4|5|6");
		puts("  7|8|9");
		
		int move = -1;
		do
		{
			printf("Your move? ");
			move = get_move();
			
			if( move<0 || move>=BOARD_SIZE )
			{
				puts("Input was invalid. Please try again.");
			}
			else if( b.tokens[move] != TOKEN_NONE )
			{
				puts("Space is already taken. Please try again.");
				move = -1;
			}

		}while( move<0 || move>=BOARD_SIZE );

		set_token(&b, TOKEN_X, move);
		print_board(b);

		// TODO: Enemy AI turn
		puts("ENEMY TURN");

		// TODO: Determine if loop is over
		//do_game_loop = false;
	}

	puts("GAME OVER. Thank you for playing!");
	return 0;
}