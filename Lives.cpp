#include "Lives.hpp"
#include <iostream>;
#pragma once



void Lives::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);
    
}

bool Lives::isDestroy(){
    return destroy;
}

void Lives::destroyTrue(){
    destroy = true;
}

int Lives::getX(){
    return moverRect.x;
}
Lives::Lives(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {100,60,360,453};

    // it will display Player on x = 30, y = 40 location, the size of Player is 50 width, 60 height
    moverRect = {0, 900, 16, 16};
}

Lives::Lives(int x, int y){  //spawning a Player at specific co ordinates
    srcRect = {100,60,360,453};
    moverRect = {x, y, 16, 16};
}