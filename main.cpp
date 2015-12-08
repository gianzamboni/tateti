#include <iostream>
#include <chrono>
#include "GUI/gui.h"
using namespace std;


int main(int argc, char** argv)
{
	//The WINDOW we'll be rendering to
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );

	} else {
		cout << "SDL initialized..." << endl;
		cout << "Loading surfaces..." << endl;
		initTatetiWindow();
   		loadSurfaces();
		cout << "Drawing board..." << endl;
		renderBoard();
	    cout << "Initalizing game..." << endl;
	    mainLoop();
       	cout << "Stoping game..." << endl;
        freeSurfaces();
		SDL_DestroyWindow( WINDOW );
	}
	
	SDL_Quit();

	return 0;
}
