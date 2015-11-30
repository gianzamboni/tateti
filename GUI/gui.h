#ifndef _GUI_H_
#define _GUI_H_

#include <SDL2/SDL.h>
#include <string>
#include "../Tateti/tateti.h"
using namespace std;

    extern SDL_Window* WINDOW;
    extern SDL_Surface* SCREEN_SURFACE, *CELDA, *SELEC_V, *SELEC_H, *PLY_O, *PLY_X, *GAMOVR;
	int updateBoard(Tateti* tateti, SDL_Rect* position);

	vector<int> boardPosition(SDL_Rect* coords);

	void drawEndGame();
	void drawSelector(SDL_Rect* position);
	void freeSurfaces();
	void initTatetiWindow();
	void loadSurfaces(); 	
	void mainLoop();
	void reloadCell(Tateti* game, SDL_Rect* position);
	void renderBoard();
	void updateSelectorPosition(int key, SDL_Rect* position);


 #endif