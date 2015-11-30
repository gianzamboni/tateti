#include "gui.h"


SDL_Window* WINDOW;
SDL_Surface* SCREEN_SURFACE, *CELDA, *SELEC_V, *SELEC_H, *PLY_O, *PLY_X, *GAMOVR;

void initTatetiWindow(){
	WINDOW = SDL_CreateWindow( "TATETI", SDL_WINDOWPOS_UNDEFINED, 
				SDL_WINDOWPOS_UNDEFINED, 310, 310, SDL_WINDOW_SHOWN);
}
void loadSurfaces(){
	SCREEN_SURFACE = SDL_GetWindowSurface( WINDOW );	
	CELDA = SDL_LoadBMP("GUI/imgs/celda.bmp");
	cout << SDL_GetError();
	SELEC_V = SDL_LoadBMP("GUI/imgs/selv.bmp");
	SELEC_H = SDL_LoadBMP("GUI/imgs/selh.bmp");
	PLY_O = SDL_LoadBMP("GUI/imgs/plyO.bmp");
	PLY_X = SDL_LoadBMP("GUI/imgs/plyX.bmp");
	GAMOVR = SDL_LoadBMP("GUI/imgs/gamover0.bmp");
}

void freeSurfaces(){
	SDL_FreeSurface(SCREEN_SURFACE);
	SDL_FreeSurface(CELDA);
	SDL_FreeSurface(SELEC_V);
	SDL_FreeSurface(SELEC_H);
	SDL_FreeSurface(PLY_O);
	SDL_FreeSurface(PLY_X);
	SDL_FreeSurface(GAMOVR);
}

void renderBoard(){

	SDL_Rect* positionInit = new SDL_Rect;

	for(int i=0; i < 312; i= i+105){
	    positionInit->y=0;
	    positionInit->x=i;
	    SDL_BlitSurface(CELDA, NULL, SCREEN_SURFACE, positionInit);

	    positionInit->y=105;
	    positionInit->x=i;
	    SDL_BlitSurface(CELDA, NULL, SCREEN_SURFACE, positionInit);

	    positionInit->y=210;
	    positionInit->x=i;
	    SDL_BlitSurface(CELDA, NULL, SCREEN_SURFACE, positionInit);
	}

	SDL_UpdateWindowSurface(WINDOW);
    delete positionInit;

}

vector<int> boardPosition(SDL_Rect* coords){
	vector<int> v(2);
	switch(coords->x){
		case 0:
			v[0] = 0;
			break;
		
		case 105:
			v[0] = 1;
			break;
		
		case 210:
			v[0] = 2;
			break;
	}
	
	switch(coords->y){
		case 0:
			v[1] = 0;
			break;
		
		case 105:
			v[1] = 1;
			break;
		
		case 210:
			v[1] = 2;
			break;
	}

	return v;
}

void updateSelectorPosition(int key, SDL_Rect* position){
	switch(key){
		case SDLK_UP:
			position->y = (position->y <= 100)? 210 : position->y - 105;
			break;
		
		case SDLK_DOWN:
			position->y = (position->y >= 210)? 0 : position->y + 105;
			break;
		
		case SDLK_RIGHT:
			position->x = (position->x >= 210)? 0 : position->x + 105;
			break;

		case SDLK_LEFT:
			position->x = (position->x <= 0)? 210 : position->x - 105;
			break;
	}
}

void reloadCell(Tateti* game, SDL_Rect* position){
	
	vector<int> cellToReload = boardPosition(position);
	char slotValue = game->getSlotValue(cellToReload[0], cellToReload[1]);
	if(slotValue == 'X'){
		SDL_BlitSurface(PLY_X, NULL, SCREEN_SURFACE, position);
	} else if(slotValue == 'O'){
		SDL_BlitSurface(PLY_O , NULL, SCREEN_SURFACE, position);
	} else {
		SDL_BlitSurface(CELDA , NULL, SCREEN_SURFACE, position);
	}
}

int updateBoard(Tateti* tateti, SDL_Rect* position){

	vector<int> cellToSet = boardPosition(position);
	if(!tateti->notAValidMove(cellToSet[0], cellToSet[1])){
		tateti->setSlot(cellToSet[0], cellToSet[1]);
	} else {
		return 0;
	}
	return 1;
}

void drawSelector(SDL_Rect* position){

	SDL_Rect* selectorPositionAux = new SDL_Rect;

	SDL_BlitSurface(SELEC_V, NULL, SCREEN_SURFACE, position);
    SDL_BlitSurface(SELEC_H, NULL, SCREEN_SURFACE, position);

    selectorPositionAux->y = position->y;
    selectorPositionAux->x = position->x + 95;
    SDL_BlitSurface(SELEC_V, NULL, SCREEN_SURFACE, selectorPositionAux);

    selectorPositionAux->y = position->y + 95;
    selectorPositionAux->x = position->x;
    SDL_BlitSurface(SELEC_H, NULL, SCREEN_SURFACE, selectorPositionAux);

    delete selectorPositionAux;
}
void drawEndGame(){
	cout << "Loading END GAME..." << endl;
	SDL_Rect* position = new SDL_Rect;
	position->y = 120;
   	position->x = 0;
   	SDL_BlitSurface(GAMOVR, NULL, SCREEN_SURFACE, position);
}

// TODO Refactor this
void  mainLoop(){
	
	Tateti* tateti = new Tateti();
	SDL_Event event;

	bool quit = false;

	SDL_Rect* selectorPosition = new SDL_Rect;
	selectorPosition->x = 0;
	selectorPosition->y = 0;

	bool count = 0;
    while( !quit ) {
        //Handle events on queue
		while( SDL_PollEvent( &event ) != 0 ){

			if(event.type == SDL_QUIT){
	        	quit = true;
	        } 
	    	else if (tateti->gameOver() && !count){
	    		reloadCell(tateti, selectorPosition);
	    		drawEndGame();
	    		count++;
	    	}
			else if(!tateti->gameOver()){

	    		reloadCell(tateti, selectorPosition);
				if(event.type == SDL_KEYDOWN){
		        	switch( event.key.keysym.sym ) {//Esta cosa horrible es "que tecla se apreto"

			  			case SDLK_UP:
			  			case SDLK_DOWN:
			  			case SDLK_RIGHT:
			  			case SDLK_LEFT:
					    	updateSelectorPosition(event.key.keysym.sym, selectorPosition);
					        break;
				
						case SDLK_RETURN:
							updateBoard(tateti, selectorPosition);
					        break;
					}
		        }
	        	drawSelector(selectorPosition);

		    }

   			SDL_UpdateWindowSurface(WINDOW);

    	}

	}

    delete selectorPosition;
    delete tateti;
}
