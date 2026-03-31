/*
    Getting started with SDL2 - Just project setup and includes.  
*/

//For exit()
#include <cstdlib>

#include "Game.hpp"

int main( int argc, char* args[] )
{
    Game game;
    game.init();
    game.runGameLoop();
    
    exit(EXIT_SUCCESS);
}
