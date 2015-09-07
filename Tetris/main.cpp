#include <SDL.h>
#include <iostream>
#include <time.h>
#include <sstream>
#include "pieces.h"
#include "graphics.h"
#include "board.h"

bool gameOver;
void initGame()
{
	gameOver = false;
	drawBoard();
	createNewPiece();
}

int main( int argc, char* args[] )
{
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

			//Event handler
			SDL_Event e;

			//While application is running
			while( !gameOver )
			{
				
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{

					//User requests quit
					if( e.type == SDL_QUIT)
					{
						gameOver = true;
					}
					else if( e.type == SDL_KEYDOWN )
					{
					
						switch( e.key.keysym.sym )
						{
                        case SDLK_LEFT:
							movePiece(-1, 0);
							break;
                        case SDLK_RIGHT:
							movePiece(1, 0);
							break;
						case SDLK_UP:
							rotate(1);
							break;
						case SDLK_DOWN:
							rotate(-1);
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
				if( SDL_GetTicks() > startTime + MOVE_DELAY )//this defines the time between each "drop" of the piece
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