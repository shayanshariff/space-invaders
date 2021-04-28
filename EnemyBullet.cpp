#include"EnemyBullet.hpp"


void EnemyBullet::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);

}

void EnemyBullet::shoot(){
        moverRect.y += 2;
    if(moverRect.y <= 0){
        srcRect = {207, 244, 231, 186};
        destroyTrue();                   //sets destroy = true when EnemyBullet reaches the bottom
    }

}


SDL_Rect *EnemyBullet::mover(){  //getter function for the moverRect
    return &moverRect;
}

void EnemyBullet::destroyTrue(){
    destroy = true;
}
bool EnemyBullet::isDestroy(){
   return destroy;
}

EnemyBullet::EnemyBullet(){
    srcRect = {670, 300, 20, 100};
    moverRect = {40, 40, 5, 20};
}
EnemyBullet::EnemyBullet(int x, int y){
    srcRect = {670, 300, 20, 100};
    moverRect = {x, y, 5, 20};
}
