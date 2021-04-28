#pragma once

#include<SDL.h>
#include "unit.hpp"

class Bullet: Unit{

public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void shoot();
    bool isDestroy();
    void destroyTrue();
    SDL_Rect *mover();
    Bullet();
    Bullet(int x, int y);
};