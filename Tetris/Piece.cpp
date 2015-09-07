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

bool collision(int y = currentY)
{
	//create temp piece arrray that holds the layout of the current piece and rotation
	//check if the temp piece is 1 && if the board location is 0, then draw a block there

    // Store each block of the piece into the board
    for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[currentPiece][currentRotation][i][j] == POS_TAKEN && ((board[i + currentX][j + y] == POS_TAKEN)
				|| (board[i + currentX][j + y] == BORDER)) )
			{
				return true;
			}
        }
    }
	return false;
}
void drawPiece()
{
	for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[currentPiece][currentRotation][i][j] == POS_TAKEN )
			{
				drawRect( i + currentX, j + currentY, POS_TAKEN );
			}
        }
    }
	//This loops and draws the next piece next to the game board
	for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[nextPiece][nextRotation][i][j] == POS_TAKEN )
			{
				drawRect( i + BOARD_WIDTH, j, POS_TAKEN );
			}
        }
    }
	int ghostCurrentY = currentY;
	while( !collision(ghostCurrentY) )
	{

		ghostCurrentY++;
	}
	ghostCurrentY--;
	for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[currentPiece][currentRotation][i][j] == POS_TAKEN )
			{
				drawRect( i + currentX, j + ghostCurrentY, -1 );
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
	currentY = 0; // number of blocks down
	if( collision() )
	{
		gameOver = true;//This is done badly but I couldn't think of a better way
	}
}

void rotate(int direction)
{
	int oldRotation=currentRotation;

	currentRotation=(currentRotation+direction+4)%4;// mod by 4 to cahnge rotation, add 4 in order to handle -1 case
	if ( collision() )// check for collision and reverse the rotate if true
	{
		currentRotation=oldRotation;
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