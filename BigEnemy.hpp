#pragma once

#include<SDL.h>
#include"Enemy.hpp"

class BigEnemy : public Enemy {
    int health = 20;

    public:
    SDL_Rect * mover();
    int getHealth();
    void reduceHealth();
    void descend();
    BigEnemy();
    BigEnemy(int x, int y);
};