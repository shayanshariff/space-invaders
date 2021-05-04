#pragma once

#include<SDL.h>
#include "unit.hpp"

class powerUp : public Unit{
    bool destroy = false;

    public:
        void draw(SDL_Renderer*, SDL_Texture* assets);
        bool isDestroy();
        void destroyTrue();
        void descend();
        SDL_Rect* mover();
};