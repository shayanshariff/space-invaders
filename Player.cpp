#include "Player.hpp"
#include <iostream>;
#pragma once
// Player implementation will go here.

float speed = 15;


void Player::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    Unit::draw(gRenderer, assets);
    
}

void Player::move(char direction){
    if (direction == 'w'){
        if(moverRect.y > 0){
            moverRect.y -= speed;
        }
    }
    if (direction == 's'){
        if(moverRect.y < 552){
            moverRect.y += speed;
        }
    }
    if (direction == 'a'){
        if(moverRect.x > 0){
            moverRect.x -= speed;
        }
    }
    if (direction == 'd'){
        if(moverRect.x < 952){
            moverRect.x += speed;
        }
    }
}


bool Player::isDestroy(){
    return destroy;
}

SDL_Rect *Player::mover(){  //getter function for the moverRect
    return &moverRect;
}
Player::Player(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {100,60,360,453};

    // it will display Player on x = 30, y = 40 location, the size of Player is 50 width, 60 height
    moverRect = {300, 400, 50, 60};
}

Player::Player(int x, int y){  //spawning a Player at specific co ordinates
    srcRect = {100,60,360,453};
    moverRect = {x, y, 50, 60};
}

Player::Player(int x, int y, int w, int h){  //spawning a Player of a specific size at specific co ordinates
    srcRect = {100,60,360,453};
    moverRect = {x, y, w, h};
}