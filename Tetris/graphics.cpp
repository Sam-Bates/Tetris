#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "graphics.h"
#include "board.h"
#include "pieces.h"

//The window
SDL_Window* gWindow;

//The renderer
SDL_Renderer* gRenderer;


SDL_Texture* blockTexture;
SDL_Texture* borderTexture;
SDL_Texture* pieceTexture;
SDL_Texture* ghostPieceTexture;
SDL_Texture* loseTexture;

bool init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
		}

		//Create window
		gWindow = SDL_CreateWindow( "Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	blockTexture = loadTexture( "texture.png" );
	borderTexture = loadTexture( "borderTexture.png" );
	pieceTexture = loadTexture( "pieceTexture.png" );
	ghostPieceTexture = loadTexture( "ghostPieceTexture.png" );
	loseTexture = loadTexture( "lose.png" );
	if( blockTexture == NULL || borderTexture == NULL || pieceTexture == NULL )
	{
		std::cout <<  "Failed to load texture image!" << std::endl;
		success = false;
	}

	return success;
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		std::cout <<  "Unable to load image" <<  path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			std::cout << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError() << std::endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture( blockTexture );
	blockTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
void drawRect( int x, int y, int pieceType )
{
	SDL_Rect a = {x * MAGNIFICATION, y * MAGNIFICATION, MAGNIFICATION/*size*/,MAGNIFICATION/*size*/};
	if( pieceType == BORDER )
	{
		SDL_RenderCopy( gRenderer, borderTexture, NULL, &a );
	}
	else if( pieceType == POS_TAKEN )
	{
		SDL_RenderCopy( gRenderer, pieceTexture, NULL, &a );
	}
	else if ( pieceType == -1 )
	{
		SDL_RenderCopy( gRenderer, ghostPieceTexture, NULL, &a );
	}
}
