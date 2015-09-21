#include <stdio.h>
using namespace std;


int main(int argc, char** argv)
{
     printf("New Game\n");
     Tateti newGame(PVP);
     newGame.init_game();

    return 0;
}