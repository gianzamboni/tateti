#include <iostream>
#include "tateti_struct/Tateti.h"
using namespace std	;


int main()
{
     cout << "New GAME" << endl;
     Tateti newGame(PVP);
     newGame.init_game();

    return 0;
}