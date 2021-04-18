#include"BaseObject.hpp"
#include"TextureManager.hpp"

BaseObject::BaseObject(const char* textureSheet, SDL_Renderer* ren, int x, int y){
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);
    xPos = x;
    yPos = y;

}

void BaseObject::update(){


    xPos++;
    yPos--;

    srcRect.h = 450;
    srcRect.w = 360;
    srcRect.x = 100;
    srcRect.y = 60;

    dstRect.x = xPos;
    dstRect.y = yPos;
    dstRect.w = 64;
    dstRect.h = 64;
}

void BaseObject::render(){
    SDL_RenderCopy(renderer, objTexture, &srcRect, &dstRect);
}