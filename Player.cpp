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
void Player::fly()
{
    //animating them for the flap
   if (srcRect.x==6){
       
        srcRect.x = 0;
        srcRect.y = 154;
        srcRect.w = 153;
        srcRect.h = 83;
   }
   //animating them for the bottom flap
   else if (srcRect.x == 2){
       srcRect.x = 6;
       srcRect.y = 6;
       srcRect.w = 155;
       srcRect.h = 102;
   }
   //animating them for the middle.
   else if (srcRect.x == 0){
       srcRect.x = 2;
       srcRect.y = 270;
       srcRect.w = 150;
       srcRect.h = 123;
   }
   //move 


}

bool Player::isDestroy(){
    return destroy;
}
void Player::unBaby(){       //This is the function to grow the Player to normal size if it is a baby. If the height and width are already equal to the full size, nothing happens
                            //so we can call it on every Player without any problems.
    if(moverRect.w != 50 && moverRect.h != 60){
        moverRect.w += 2.5;
        moverRect.h += 3;
    }
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

Player::Player(int x, int y, int w, int h){  //spawning a Player of a specific size at specific co ordinates, this is used to make baby Players
    srcRect = {100,60,360,453};
    moverRect = {x, y, w, h};
}