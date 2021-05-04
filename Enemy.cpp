#include "Enemy.hpp"
#include<iostream>

void Enemy::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);


}
void Enemy::descend(){
    moverRect.y += 1;
    if(moverRect.y > 600){
        destroyTrue();
        cross();
    }
        
}

bool Enemy::hasCrossed(){
    std::cout << "cross" << std::endl;
    return crossed;

}

void Enemy::cross(){
    crossed = true;
}
bool Enemy::isDestroy(){
    return destroy;
}
void Enemy::destroyTrue(){
    destroy = true;
}
SDL_Rect *Enemy::mover(){  //getter function for the moverRect
    return &moverRect;
}

Enemy::Enemy(){
    srcRect = {940, 130, 200, 200};
    moverRect = {40, 40, 60, 70};
}
Enemy::Enemy(int x, int y){
    srcRect = {940, 130, 200, 200};
    moverRect = {x, y, 32, 32};

}