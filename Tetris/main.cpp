#include <SDL.h>
#include <iostream>
#include <time.h>
#include "pieces.h"
#include "graphics.h"
#include "board.h"

void initGame()
{
	currentPiece = rand()%7;
	nextPiece = rand()%7;
	currentRotation = rand()%4;
	//figure out initial postion stuff
	currentX = (BOARD_WIDTH / 2); // in the middle of the board
	currentY = 3; // number of blocks down
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
						}
					}
				}
				//Clear screen
				SDL_RenderClear( gRenderer );
				drawBoard();
				drawPiece();
				movePiece(0, 1);

				//Update screen
				SDL_RenderPresent( gRenderer );
				SDL_Delay(50);
			}
		}
	}
	close();

	return 0;
}