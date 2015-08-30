int pieces [7 /*kind */ ][4 /* rotation */ ][5][5] =
{
// Square
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },
 
// I
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}, 
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
  ,
// L
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// L mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
 
 
 
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// T
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
};
int initialPlace  [7 /*kind */ ][4 /* r2otation */ ][2 /* position */] =
{
/* Square */
  {
    {-2, -3}, 
    {-2, -3},
    {-2, -3},
    {-2, -3}
   },
/* I */
  {
    {-2, -2},
    {-2, -3},
    {-2, -2},
    {-2, -3}
   },
/* L */
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* L mirrored */
  {
    {-2, -3},
    {-2, -2},
    {-2, -3},
    {-2, -3}
   },
/* N */
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* N mirrored */
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* T */
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
};

#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

const int BOARD_WIDTH = 12; //in blocks
const int BOARD_HEIGHT = 22; //in blocks
const int POS_FREE = 0;
const int POS_TAKEN = 1;
const int BORDER = 2;
const int PIECE_BLOCKS = 5; // in blocks

int currentPiece = NULL;
int nextPiece= NULL;
int currentY= NULL;
int currentX = NULL;
int currentRotation = NULL;
int board[BOARD_WIDTH][BOARD_HEIGHT];

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* blockTexture = NULL;
SDL_Texture* borderTexture = NULL;




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
	if( blockTexture == NULL || borderTexture == NULL )
	{
		std::cout <<  "Failed to load texture image!" << std::endl;
		success = false;
	}

	return success;
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
//void creatNewPiece()
//{
//	int kind
//	piece[kind][rotation][horizontal][vertical]
//}

void drawBoard()
{
	int count = 0;
	for( int i = 0; i < BOARD_WIDTH; i++)
	{
		for( int j = 0; j < BOARD_HEIGHT; j++)
		{
			if( board[i][j] == POS_TAKEN )
			{
				SDL_Rect a = {i * 11 /*X*/, j * 11 /*Y*/, 10/*size*/,10/*size*/};
				SDL_RenderCopy( gRenderer, blockTexture, NULL, &a );
			}
			else if( board[i][j] == BORDER )
			{
				SDL_Rect a = {i * 11 /*X*/, j * 11 /*Y*/, 11/*size*/,11/*size*/};
				SDL_RenderCopy( gRenderer, borderTexture, NULL, &a );
			}
		}
	}
}

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

void initGame()
{
	currentPiece = rand()%7;
	nextPiece = rand()%7;
	currentRotation = rand()%4;
	//figure out initial postion stuff
	currentX = (BOARD_WIDTH / 2); // in the middle of the board
	currentY = 3; // number of blocks down
}

bool collision()
{
	//create temp piece arrray that holds the layout of the current piece and rotation
	//check if the temp piece is 1 && if the board location is 0, then draw a block there

	
    // Store each block of the piece into the board
    for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {   
			if( pieces[currentPiece][currentRotation][i][j] == POS_TAKEN && ((board[i + currentX][j + currentY] == POS_TAKEN) || (board[i + currentX][j + currentY] == BORDER)) )
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
				SDL_Rect a = {(i + currentX) * 11 /*X*/, (j + currentY) * 11 /*Y*/, 10/*size*/,10/*size*/};
				SDL_RenderCopy( gRenderer, blockTexture, NULL, &a );
			}
        }
    }
}
void movePiece()
{
	currentY++;
	if( collision() )
	{
		currentY--;
	}
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
							currentX--;
							if( collision() )
							{
								currentX++;
							}
							break;

                        case SDLK_RIGHT:
							currentX++;
							if( collision() )
							{
								currentX--;
							}
							break;
						}
					}
				}

				//Clear screen
				SDL_RenderClear( gRenderer );
				drawBoard();
				drawPiece();
				movePiece();
				//collision();


				//Update screen
				SDL_RenderPresent( gRenderer );
				SDL_Delay(50);

				//when moving piece, set old piece spots to zero before drawing next piece

				//MovePiece() Check if valid
				//drawPiece()
				//check for next move collision
				//check for completed lines
				//create new piece if needed
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}