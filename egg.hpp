#include<SDL.h>
#include "unit.hpp"

class Egg: Unit{

public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void drop();
    bool isDestroy();
    void destroyTrue();
    SDL_Rect *mover();
    Egg();
    Egg(int x, int y);
};