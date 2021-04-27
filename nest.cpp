#include "nest.hpp"


void Nest::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);


}
void Nest::wiggle(){
    if(srcRect.y == 0){
        srcRect.x = 484;
        srcRect.y = 167;
        srcRect.w = 163;
        srcRect.h = 112;
    }
    else if(srcRect.y == 167){
        srcRect.x = 493;
        srcRect.y = 296;
        srcRect.w = 154;
        srcRect.h = 124;
    }
    else if(srcRect.y == 296){
        srcRect.x = 465;
        srcRect.y = 0;
        srcRect.w = 182;
        srcRect.h = 164;

    }
        
}
SDL_Rect *Nest::mover(){  //getter function for the moverRect
    return &moverRect;
}

Nest::Nest(){
    srcRect = {940, 130, 200, 200};
    moverRect = {40, 40, 60, 70};
}
Nest::Nest(int x, int y){
    srcRect = {940, 130, 200, 200};
    moverRect = {x, y, 32, 32};

}