#include <stdio.h>
#include <stdbool.h>
#include "tictactoe.h"

bool has_winner(board b)
{
	switch( get_winner(b) )
	{
		default:
		case WINNER_NONE:
			return false;
		case WINNER_TIE:
			puts("TIE GAME!");
			return true;
		case WINNER_PLAYER:
			puts("YOU WIN!");
			return true;
		case WINNER_AI:
			puts("YOU LOSE!");
			return true;
	}
}

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
	while( true )
	{
		// Player turn
		puts("PLAYER TURN");
		puts("  1|2|3");
		puts("  4|5|6");
		puts("  7|8|9");
		
		// Query for player input
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

		// Set player input
		set_token(&b, TOKEN_X, move);
		print_board(b);
		if( has_winner(b) ) break;

		// Enemy AI turn
		puts("ENEMY TURN");
		make_ai_move(&b);
		print_board(b);
		if( has_winner(b) ) break;
	}

	puts("GAME OVER. Thank you for playing!");
	return 0;
}