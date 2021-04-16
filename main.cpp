#include <SDL.h>
#include"Game.hpp"

//Let's Make Games's series on SDL2 game dev has been a HUGE help in figuring all this out, credit to him.

Game *game = nullptr;

int main(int arg, char *argv[])
{

    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game;
    game->init("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0);
    while(game->running()){
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->close();


    return 0;
}