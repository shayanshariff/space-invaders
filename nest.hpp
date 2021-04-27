#include<SDL.h>
#include "unit.hpp"

class Nest: Unit{


public:

    void draw(SDL_Renderer*, SDL_Texture* assets);
    void wiggle();
    SDL_Rect *mover();
    Nest(); 
    Nest(int x, int y);
};
