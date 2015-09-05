#ifndef graphics_h_
#define graphics_h_
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#include <string>


SDL_Texture* loadTexture( std::string path );
bool init();
bool loadMedia();
void close();
void drawRect();

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The renderer
extern SDL_Renderer* gRenderer;

//The two textures
extern SDL_Texture* blockTexture;
extern SDL_Texture* borderTexture;
extern SDL_Texture* pieceTexture;

#endif