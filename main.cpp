#include <SDL.h>
#include"Game.hpp"



Game *game = nullptr;

int main(int arg, char *argv[])
{
    game = new Game;
    game->init("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0);
    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }
    game->close();


    return 0;
}