#include "egg.hpp"


void Egg::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);

}
void Egg::drop(){
    if(moverRect.y < 550){
        moverRect.y -= 2;
    }
    if(moverRect.y <= 0){
        srcRect = {207, 244, 231, 186};
        destroyTrue();                   //sets destroy = true when egg reaches the bottom
    }

        
}

SDL_Rect *Egg::mover(){  //getter function for the moverRect
    return &moverRect;
}

void Egg::destroyTrue(){
    destroy = true;
}
bool Egg::isDestroy(){
   return destroy;
}

Egg::Egg(){
    srcRect = {670, 300, 20, 100};
    moverRect = {40, 40, 5, 20};
}
Egg::Egg(int x, int y){
    srcRect = {670, 300, 20, 100};
    moverRect = {x, y, 5, 20};
}

