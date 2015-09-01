#include <SDL.h>
#include <SDL_image.h>
#include "pieces.h"
#include "board.h"
#include "graphics.h"

int currentPiece; // the current in play piece
int nextPiece;
int currentY;
int currentX;
int currentRotation;

bool collision()
{
	//create temp piece arrray that holds the layout of the current piece and rotation
	//check if the temp piece is 1 && if the board location is 0, then draw a block there

    // Store each block of the piece into the board
    for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[currentPiece][currentRotation][i][j] == POS_TAKEN && ((board[i + currentX][j + currentY] == POS_TAKEN)
				|| (board[i + currentX][j + currentY] == BORDER)) )
			{
				return true;
			}
        }
    }
	return false;
}
void drawPiece( )
{
	for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[currentPiece][currentRotation][i][j] == POS_TAKEN )
			{
				SDL_Rect a = {(i + currentX) * MAGNIFICATION /*X*/, (j + currentY) * MAGNIFICATION /*Y*/, 10/*size*/,10/*size*/};
				SDL_RenderCopy( gRenderer, blockTexture, NULL, &a );
			}
        }
    }
}

//This method moves the piece and calls the collision method, if collision is true, revert the movement
void movePiece(int x, int y)
{
	currentY += y;
	currentX += x;
	if( collision() )
	{
		currentY -= y;
		currentX -= x;
	}
}