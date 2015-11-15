#include <iostream>
#include <stdio.h>
#include <vector>
#include "cositasDelSDL.h"
#include "Tateti/Tateti.h"
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

vector<int> boardPosition(SDL_Rect* coords){
	std::vector<int> v(2);
	switch(coords->x){
		case 0:
			v[0] = 0;
			break;
		case 105:
			v[0] = 1;
			break;
		case 210:
			v[0] = 2;
	}
	
	switch(coords->x){
		case 0:
			v[1] = 0;
			break;
		case 105:
			v[1] = 1;
			break;
		case 210:
			v[1] = 2;
	}
	return v;
}
int main(int argc, char** argv)
{
	//The window we'll be rendering to
	Tateti* tateti = new Tateti();

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
			SDL_Window* window = SDL_CreateWindow( "TATETI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 310, 310, SDL_WINDOW_SHOWN);
			//Get window surface
    		SDL_Surface* screenSurface = SDL_GetWindowSurface( window );
    		SDL_Surface* celda = SDL_LoadBMP("imgs/celda.bmp");
    		SDL_Surface* selecV = SDL_LoadBMP("imgs/selv.bmp");
    		SDL_Surface* selecH = SDL_LoadBMP("imgs/selh.bmp");
    		SDL_Surface* plyO = SDL_LoadBMP("imgs/plyO.bmp");
    		SDL_Surface* plyX = SDL_LoadBMP("imgs/plyX.bmp");


            bool quit = false;

			SDL_Rect* positionInit = new SDL_Rect;

			for(int i=0; i < 312; i= i+105){
			    positionInit->y=0;
			    positionInit->x=i;
			    SDL_BlitSurface(celda, NULL, screenSurface, positionInit);

			    positionInit->y=105;
			    positionInit->x=i;
			    SDL_BlitSurface(celda, NULL, screenSurface, positionInit);

			    positionInit->y=210;
			    positionInit->x=i;
			    SDL_BlitSurface(celda, NULL, screenSurface, positionInit);
		    }

		    delete positionInit;

		    SDL_Rect* selectorPosition = new SDL_Rect;
		    SDL_Rect* selectorPositionAux = new SDL_Rect;
		    
		    SDL_UpdateWindowSurface(window);
            //Event handler
            SDL_Event event;
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &event ) != 0 ){
	               
	                SDL_BlitSurface(celda, NULL, screenSurface, selectorPosition);

	                if( event.type == SDL_KEYDOWN ){
	                	switch( event.key.keysym.sym ) {//Esta cosa horrible es "que tecla se apreto"
		  					case SDLK_UP: //Por ejemplo aca la flechita arriba
				                //Actualizamos las coordenadas del rectangulo
				                if(selectorPosition->y <= 100){
				                  	selectorPosition->y = 210;
				                }else{
				                   	selectorPosition->y = selectorPosition->y - 105;
				                }
				                break;
				            case SDLK_DOWN:
				        		if(selectorPosition->y >= 210){
				                	selectorPosition->y = 0;
				                }else{
				                	selectorPosition->y = selectorPosition->y + 105;
								}
				                break;
							case SDLK_RIGHT:
		                   		if(selectorPosition->x >= 210){
				                   	selectorPosition->x = 0;
				                }else{
				                   	selectorPosition->x = selectorPosition->x + 105;
				                }
				                break;
				            case SDLK_LEFT:
				                if(selectorPosition->x <= 100){
				                    selectorPosition->x = 210;
				                }else{
				                    selectorPosition->x = selectorPosition->x - 105;
				                }
				                break;
				            case SDLK_RETURN:
				            	vector<int> matrixIndexes = boardPosition(selectorPosition);
				            	if(tateti->actual_player() == 0){
				            		SDL_BlitSurface(plyX, NULL, screenSurface, selectorPosition);
				            		tateti->set_slot(matrixIndexes[0], matrixIndexes[1], 0);
				            		std::cout << tateti->actual_player() << std::endl;
				            	} else {
				            		SDL_BlitSurface(plyO, NULL, screenSurface, selectorPosition);
				            		tateti->set_slot(matrixIndexes[0], matrixIndexes[1], 1);
				            		std::cout << tateti->actual_player() << std::endl;
				            	}
				            	break;
				        }
	                } else if(event.type == SDL_QUIT){
	                    quit = true;
	                }


	            SDL_BlitSurface(selecV, NULL, screenSurface, selectorPosition);
	            SDL_BlitSurface(selecH, NULL, screenSurface, selectorPosition);

	            selectorPositionAux->y = selectorPosition->y;
	            selectorPositionAux->x = selectorPosition->x + 95;
	            SDL_BlitSurface(selecV, NULL, screenSurface, selectorPositionAux);

	            selectorPositionAux->y = selectorPosition->y + 95;
	            selectorPositionAux->x = selectorPosition->x;
	            SDL_BlitSurface(selecH, NULL, screenSurface, selectorPositionAux);

       			SDL_UpdateWindowSurface(window);
            }

        }

        	delete selectorPosition;	

        	SDL_FreeSurface(plyO);
        	SDL_FreeSurface(plyX);
        	SDL_FreeSurface(selecV);
        	SDL_FreeSurface(selecH);
            SDL_FreeSurface(celda);
			SDL_DestroyWindow( window );
	}
	
	SDL_Quit();

	return 0;
}
