#pragma once

#include<SDL.h>
#include "unit.hpp"

class Lives: Unit{


public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    bool isDestroy();
    void destroyTrue();
    int getX();
    Lives(); 
    Lives(int x, int y);
    // may add other overloaded constructors here... 
};
