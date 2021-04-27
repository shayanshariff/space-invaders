#include<SDL.h>

#ifndef UNIT         //Added a guard to prevent redefinition of the Unit class, as multiple header files inherit from it
#define UNIT
class Unit{

    protected:
        SDL_Rect srcRect, moverRect;
        bool destroy = false;
    public:
        void draw(SDL_Renderer*, SDL_Texture* assets);

};
#endif