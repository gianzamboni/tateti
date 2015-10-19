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
			SDL_Window* window = SDL_CreateWindow( "TATETI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 320, SDL_WINDOW_SHOWN);
			//Get window surface
    		SDL_Surface* screenSurface = SDL_GetWindowSurface( window );
    		SDL_Surface* fondo = SDL_LoadBMP("imgs/p01.bmp");
    		SDL_Surface* selector = SDL_LoadBMP("imgs/car.bmp");

		    //Fill the surface white
   			SDL_BlitSurface( fondo, NULL, screenSurface, NULL );
   			SDL_UpdateWindowSurface(window);
			
			   //Main loop flag
            bool quit = false;

			SDL_Rect* position = new SDL_Rect;
		    position->x=0;
		    position->y=0;

            //Event handler
            SDL_Event event;
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &event ) != 0 ){
                if( event.type == SDL_KEYDOWN ){
                		switch( event.key.keysym.sym ) {//Esta cosa horrible es "que tecla se apreto"
	  						case SDLK_UP: //Por ejemplo aca la flechita arriba
			                    //Actualizamos las coordenadas del rectangulo
			                    position->x=0;
			                    position->y=0;
			                    break;
			                case SDLK_DOWN:
			                    position->x=110;
			                    position->y=0;
			                    break;
			                case SDLK_LEFT:
			                    position->x=110;
			                    position->y=110;
			                    break;
			                case SDLK_RIGHT:
			                    position->x=200;
			                    position->y=200;
			                    break;
			                }
                } else if(event.type == SDL_QUIT){
                    quit = true;
                }

                SDL_BlitSurface( selector, NULL, screenSurface, position );
       			SDL_UpdateWindowSurface(window);
            }

        }

            SDL_FreeSurface(fondo);
            SDL_FreeSurface(selector);
			SDL_DestroyWindow( window );
	}
	
	SDL_Quit();

	return 0;
}