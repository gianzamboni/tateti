#include <stdio.h>
#include "cositasDelSDL.h"
#include "Tateti/Tateti.h"
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv)
{
	//The window we'll be rendering to
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		SDL_Window* window = crear_tablero();
		
		SDL_Delay( 5000 );
		SDL_DestroyWindow( window );
	}
	
	SDL_Quit();

	return 0;
}