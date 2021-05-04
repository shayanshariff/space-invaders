#pragma once

#include<SDL.h>
#include "unit.hpp"

class Enemy: Unit{
friend class BigEnemy;
friend class SmallEnemy;

public:

    void draw(SDL_Renderer*, SDL_Texture* assets);
    void descend();
    bool isDestroy();
    void destroyTrue();
    bool crossed = false;
    bool hasCrossed();
    void cross();
    SDL_Rect *mover();
    Enemy(); 
    Enemy(int x, int y);
};
