#pragma once

#include<SDL.h>
#include "unit.hpp"

class Player: Unit{


public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void fly();
    bool isDestroy();
    void move(char direction);
    void unBaby();
    Player(); 
    Player(int x, int y);
    Player(int x, int y, int w, int h);
    SDL_Rect* mover();
    // may add other overloaded constructors here... 
};
