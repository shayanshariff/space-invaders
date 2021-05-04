#include "powerUp.hpp"
#include <iostream>;
#pragma once

void powerUp::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);
    
}

bool powerUp::isDestroy(){
    return destroy;
}

SDL_Rect *powerUp::mover(){  //getter function for the moverRect
    return &moverRect;
}

void powerUp::destroyTrue(){
    destroy = true;
}



void powerUp::descend(){
    moverRect.y += 1;
    if(moverRect.y > 600){
        destroyTrue();
    }
}