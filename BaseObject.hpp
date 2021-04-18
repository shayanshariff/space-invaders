#pragma once

#include"SDL.h"

class BaseObject{

    int xPos;
    int yPos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, dstRect;
    SDL_Renderer* renderer;

    public:
        BaseObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
        ~BaseObject();

        void update();
        void render();


};