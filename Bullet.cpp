#include "Bullet.hpp"


void Bullet::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);

}
void Bullet::shoot(){
        moverRect.y -= 2;
    if(moverRect.y <= 0){
        srcRect = {207, 244, 231, 186};
        destroyTrue();                   //sets destroy = true when Bullet reaches the bottom
    }

        
}

SDL_Rect *Bullet::mover(){  //getter function for the moverRect
    return &moverRect;
}

void Bullet::destroyTrue(){
    destroy = true;
}
bool Bullet::isDestroy(){
   return destroy;
}

Bullet::Bullet(){
    srcRect = {670, 300, 20, 100};
    moverRect = {40, 40, 5, 20};
}
Bullet::Bullet(int x, int y){
    srcRect = {670, 300, 20, 100};
    moverRect = {x, y, 5, 20};
}

