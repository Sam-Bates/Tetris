#include <SDL.h>
#include <iostream>
#include <time.h>
#include <sstream>
#include "pieces.h"
#include "graphics.h"
#include "board.h"

void initGame()
{
	currentPiece = rand()%7;
	nextPiece = rand()%7;
	currentRotation = rand()%4;
	nextRotation = rand()%4;
	//figure out initial postion stuff
	currentX = (BOARD_WIDTH / 2); // in the middle of the board
	currentY = -1; // number of blocks down
}

int main( int argc, char* args[] )
{
	//make a collided piece save into the board
	//piece rotations
	//score
	//game end
	srand(time(NULL));
	initGame();
	initBoard();
	Uint32 startTime = SDL_GetTicks();
	bool check = false; //***Delete this at some point***
	//Start up SDL and create window
	if( !init() )
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			std::cout << "Failed to load media!" << std::endl;
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{

					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else if( e.type == SDL_KEYDOWN )
					{
					
						switch( e.key.keysym.sym )
						{
                        case SDLK_LEFT:
							movePiece(-1, 0);
							break;

                        case SDLK_RIGHT:
							//make enum at some point
							movePiece(1, 0);
							break;
						case SDLK_UP:
							//make enum at some point
							rotate(1);
							break;
						case SDLK_DOWN:
							//make enum at some point
							rotate(0);
							break;
						case SDLK_SPACE:
							slam();
							break;
						case SDLK_LSHIFT:
							swapPiece();
							break;
						}
					}
				}
				drawBoard();
				drawPiece();
				
				
				SDL_RenderPresent( gRenderer );
				if( check )
				{
					checkLines();
					check = false;
				}
				
				if( SDL_GetTicks() > startTime + MOVE_DELAY )
				{
					startTime = SDL_GetTicks();
					if( movePiece(0, 1) )
					{
						savePieceToBoard();
						createNewPiece();
						check = true;
					}
				}
				
				//Clear screen
				SDL_RenderClear( gRenderer );
			}
		}
	}
	close();
	return 0;
}