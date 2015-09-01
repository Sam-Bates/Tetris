#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "board.h"
#include "pieces.h"

int board[BOARD_WIDTH][BOARD_HEIGHT];

//This method creates a 2X2 array that is used to define where blocks are drawn
void initBoard()
{
    for (int x = 0; x < BOARD_WIDTH; x++)
	{
        for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			if( x == 0 || x == (BOARD_WIDTH -1) || y == (BOARD_HEIGHT -1) || y == 0 )
			{
				board[x][y] = BORDER;
			}
			else
			{
				board[x][y] = POS_FREE;
			}
		}
	}
}

//This method loops through to board array and draws the board itself
void drawBoard()
{
	for( int i = 0; i < BOARD_WIDTH; i++)
	{
		for( int j = 0; j < BOARD_HEIGHT; j++)
		{
			if( board[i][j] == POS_TAKEN )
			{
				//create 2d rectangle to apply texture to, MAGNIFICATION defines the size of the rendered game
				SDL_Rect a = {i * MAGNIFICATION /*X*/, j * MAGNIFICATION /*Y*/, 10/*size*/,10/*size*/};
				//actually tell SDL to render the blockTexture to the screen
				SDL_RenderCopy( gRenderer, blockTexture, NULL, &a );
			}
			else if( board[i][j] == BORDER ) //Same thing as above, expect loading borderTexture instead of the block texture
			{
				//The size is 11 so there is no gap between the drawn border blocks
				SDL_Rect a = {i * MAGNIFICATION /*X*/, j * MAGNIFICATION /*Y*/, 11/*size*/,11/*size*/};
				SDL_RenderCopy( gRenderer, borderTexture, NULL, &a );
			}
		}
	}
}

void savePieceToBoard()
{
	for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[currentPiece][currentRotation][i][j] == POS_TAKEN )
			{
				board[i + currentX][j + currentY] = POS_TAKEN;
			}
        }
    }
}

