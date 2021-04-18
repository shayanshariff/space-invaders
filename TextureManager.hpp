#pragma once

#include"SDL_Image.h"


class TextureManager{

    public:
        static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
        
};
