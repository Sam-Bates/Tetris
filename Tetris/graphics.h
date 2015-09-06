#ifndef graphics_h_
#define graphics_h_
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700
#include <string>



bool init();
bool loadMedia();
void close();
void drawRect(int, int, int);

const int MAGNIFICATION = 32;

SDL_Texture* loadTexture( std::string path );

extern bool gameOver;
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* loseTexture;
extern SDL_Texture* blockTexture;
extern SDL_Texture* borderTexture;
extern SDL_Texture* pieceTexture;
extern SDL_Texture* ghostPieceTexture;

#endif