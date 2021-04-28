#include "SpaceInvaders.hpp"
#include<iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//These three draw functions are all basically the same, the isDestroy() in Player and Bullet check if they need to be destroyed fir eg reaching the bottom for Bullet or colliding with a nest
void SpaceInvaders::drawPlayer(){
        for (auto iPig = pigList.begin(); iPig != pigList.end(); ++iPig){
            (*iPig)->draw(gRenderer, assets);
            (*iPig)->fly(); 
            (*iPig)->unBaby();    //if the Player is a baby, it will grow with this function, otherwise there will be no change
            if((*iPig)->isDestroy()){
                delete *iPig;
                *iPig = NULL;
                pigList.erase(iPig);
            }
        }
    }

void SpaceInvaders::drawBullet(){
    for (auto iBullet = BulletList.begin(); iBullet != BulletList.end(); ++iBullet){
            (*iBullet)->draw(gRenderer, assets);
            (*iBullet)->shoot();
            babyPlayer((*iBullet), (*iBullet)->mover());    
            if((*iBullet)->isDestroy()){
                    delete *iBullet;
                    *iBullet = NULL;
                    BulletList.erase(iBullet);
                }
    }
}

void SpaceInvaders::drawNest(){
    for (auto iNest = nestList.begin(); iNest != nestList.end(); ++iNest){
            (*iNest)->draw(gRenderer, assets);
            (*iNest)->wiggle();
        }
}

void SpaceInvaders::babyPlayer(Bullet* e1, const SDL_Rect * BulletMover){       
    //Checks for intersection with a nest for the Bullet passed into it.
    for (auto iNestIntersect = nestList.begin(); iNestIntersect != nestList.end(); ++iNestIntersect){
            if(SDL_HasIntersection(BulletMover, (*iNestIntersect)->mover())){
                Player *baby = new Player((*iNestIntersect)->mover()->x, (*iNestIntersect)->mover()->y, 5, 6);
                pigList.push_back(baby);
                    drawPlayer();     
                    e1->destroyTrue();  //To set destroy to true after the collision

            }
        }
}

void SpaceInvaders::drawObjects(){
    //Checks if each list is empty, before drawing whatever is in that list. We have to perform the check because if we call draw on an empty list, it crashes the game(and my computer)
    if(!BulletList.empty()){
        drawBullet();
    }
    drawPlayer();
}

void SpaceInvaders::createObject(int x, int y){

    BulletList.push_back(new Bullet(x, y));

            

}

void SpaceInvaders::createPlayer(int x, int y){
    pigList.push_back(new Player(x, y));
}

Player* SpaceInvaders::getPlayer(){
    return pigList.front();
}

SpaceInvaders::SpaceInvaders(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){}
