#include"BigEnemy.hpp"

int BigEnemy::getHealth(){
    return health;
}

void BigEnemy::reduceHealth(){
    health--;
}

void BigEnemy::descend(){
    moverRect.y += 1;
    if(moverRect.y > 600){
        destroyTrue();
        cross();
    }

}

BigEnemy::BigEnemy(){
    srcRect = {940, 130, 200, 200};
    moverRect = {40, 40, 60, 70};
}
BigEnemy::BigEnemy(int x, int y){
    srcRect = {940, 130, 200, 200};
    moverRect = {x, y, 160, 160};

}