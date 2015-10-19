#include "cositasDelSDL.h"


SDL_Window* crear_tablero(){
	
	SDL_Window* window = SDL_CreateWindow( "TATETI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 320, SDL_WINDOW_SHOWN);
	//Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface( window );
    SDL_Surface* fondo = SDL_LoadBMP("imgs/p01.bmp");

    //Fill the surface white
   	SDL_BlitSurface( fondo, NULL, screenSurface, NULL );

   	SDL_UpdateWindowSurface(window);
	return window;
}