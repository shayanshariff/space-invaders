#include "SpaceInvaders.hpp"
#include<iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//These three draw functions are all basically the same, the isDestroy() in Player and Bullet check if they need to be destroyed fir eg reaching the bottom for Bullet or colliding with a Enemy
void SpaceInvaders::drawPlayer(){
        for (auto iplayer = playerList.begin(); iplayer != playerList.end(); ++iplayer){
            (*iplayer)->draw(gRenderer, assets);
            (*iplayer)->fly(); 
            (*iplayer)->unBaby();    //if the Player is a baby, it will grow with this function, otherwise there will be no change
            if((*iplayer)->isDestroy()){
                delete *iplayer;
                *iplayer = NULL;
                playerList.erase(iplayer);
            }
        }
    }

void SpaceInvaders::drawBullet(){
    for (auto iBullet = BulletList.begin(); iBullet != BulletList.end(); ++iBullet){
            (*iBullet)->draw(gRenderer, assets);
            (*iBullet)->shoot(); 
            enemyHit(*iBullet, (*iBullet)->mover());
            if((*iBullet)->isDestroy()){
                    delete *iBullet;
                    *iBullet = NULL;
                    BulletList.erase(iBullet);
                }
    }
}

void SpaceInvaders::drawEnemy(){
    for (auto iEnemy = EnemyList.begin(); iEnemy != EnemyList.end(); ++iEnemy){
            (*iEnemy)->draw(gRenderer, assets);
            (*iEnemy)->descend();
            if((*iEnemy)->isDestroy()){
                    delete *iEnemy;
                    *iEnemy = NULL;
                    EnemyList.erase(iEnemy);
                    std::cout << "destroyed" << std::endl;
                }
        }
}

void SpaceInvaders::enemyHit(Bullet* e1, const SDL_Rect * BulletMover){       
    //Checks for intersection with a Enemy for the Bullet passed into it.
    for (auto iEnemyIntersect = EnemyList.begin(); iEnemyIntersect != EnemyList.end(); ++iEnemyIntersect){
            if(SDL_HasIntersection(BulletMover, (*iEnemyIntersect)->mover())){   
                    e1->destroyTrue();  //To set destroy to true after the collision
                    (*iEnemyIntersect)->destroyTrue();
                    std::cout << "collide" << std::endl;

            }
        }
}

void SpaceInvaders::drawObjects(){
    //Checks if each list is empty, before drawing whatever is in that list. We have to perform the check because if we call draw on an empty list, it crashes the game(and my computer)
    if(!BulletList.empty()){
        drawBullet();
    }
    if(!EnemyList.empty()){
        drawEnemy();
    }
    drawPlayer();
}

void SpaceInvaders::createBullet(int x, int y){
    BulletList.push_back(new Bullet(x, y));
}

void SpaceInvaders::createPlayer(int x, int y){
    playerList.push_back(new Player(x, y));
}

void SpaceInvaders::createEnemy(int x, int y){
    EnemyList.push_back(new Enemy(x, y));
}

Player* SpaceInvaders::getPlayer(){
    return playerList.front();
}

SpaceInvaders::SpaceInvaders(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){}
