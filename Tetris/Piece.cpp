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
int nextRotation;

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
				SDL_Rect a = {(i + currentX) * MAGNIFICATION /*X*/, (j + currentY) * MAGNIFICATION /*Y*/, MAGNIFICATION/*size*/,MAGNIFICATION/*size*/};
				SDL_RenderCopy( gRenderer, pieceTexture, NULL, &a );
			}
        }
    }
	for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[nextPiece][nextRotation][i][j] == POS_TAKEN )
			{
				SDL_Rect a = {(i + BOARD_WIDTH) * MAGNIFICATION /*X*/, (j) * MAGNIFICATION /*Y*/, MAGNIFICATION/*size*/,MAGNIFICATION/*size*/};
				SDL_RenderCopy( gRenderer, pieceTexture, NULL, &a );
			}
        }
    }
}

//This method moves the piece and calls the collision method, if collision is true, revert the movement
bool movePiece(int x, int y)
{
	currentY += y;
	currentX += x;
	if( collision() )
	{
		currentY -= y;
		currentX -= x;
		if( y != 0 )
		{
			return true;
		}
	}
	return false;
}
//Slam the piece to the bottom of the current Y value
void slam()
{
	while( !collision() )
	{
		currentY++;
	}
	currentY--;/*This is here otherwise when a piece is slammed, it will go 1 block too deep i.e. it will land inside the border
			   rather than on the border*/
}

void createNewPiece()
{
	currentPiece = nextPiece;
	currentRotation = nextRotation;
	nextPiece = rand()%7;
	nextRotation = rand()%4;
	//figure out initial postion stuff
	currentX = (BOARD_WIDTH / 2) - 2; // in the middle of the board
	currentY = -1; // number of blocks down
}

void rotate(int direction)
{
	if( direction == 1 )
	{
		int temp = currentRotation;
		currentRotation++;
		if( currentRotation > 3 /*magic to change*/ )
		{
			currentRotation = 0;
		}
		if( collision() )
		{
			currentRotation = temp;
		}
	}
	else 
	{
		int temp = currentRotation;
		currentRotation--;
		if( currentRotation < 0 )
		{
			currentRotation = 3;
		}
		if( collision() )
		{
			currentRotation = temp;
		}
	}
}
void swapPiece()
{
	
	int temp = currentPiece;
	currentPiece = nextPiece;
	nextPiece = temp;
	//This if statement stops a piece from glitcing into the wall when changed
	if( collision() )
	{
		//revert the piece to it's original place if a swap would collide
		int temp = nextPiece;
		nextPiece = currentPiece;
		currentPiece = temp;
	}
}