#include "SpaceInvaders.hpp"
#include<iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int SpaceInvaders::getScore(){
    return score;
}

bool SpaceInvaders::isGameOver(){
    return gameOverState;
}

void SpaceInvaders::gameOver(){
    gameOverState = true;
}
//These three draw functions are all basically the same, the isDestroy() in Player and Bullet check if they need to be destroyed fir eg reaching the bottom for Bullet or colliding with a Enemy
void SpaceInvaders::drawPlayer(){
        for (auto iplayer = playerList.begin(); iplayer != playerList.end(); ++iplayer){
            (*iplayer)->draw(gRenderer, assets);
            if((*iplayer)->isDestroy()){
                delete *iplayer;
                *iplayer = NULL;
                playerList.erase(iplayer);
            }
        }
    }

void SpaceInvaders::drawLife(){
        for (auto iLife = LivesList.begin(); iLife != LivesList.end(); ++iLife){
            (*iLife)->draw(gRenderer, assets);
            if((*iLife)->isDestroy()){
                delete *iLife;
                *iLife = NULL;
                LivesList.erase(iLife);
            }
        }
    }

void SpaceInvaders::drawBullet(){
    for (auto iBullet = BulletList.begin(); iBullet != BulletList.end(); ++iBullet){
            (*iBullet)->draw(gRenderer, assets);
            (*iBullet)->shoot(); 
            smallHit(*iBullet, (*iBullet)->mover());
            bigHit(*iBullet, (*iBullet)->mover());
            if((*iBullet)->isDestroy()){
                    delete *iBullet;
                    *iBullet = NULL;
                    BulletList.erase(iBullet);
                }
    }
}

void SpaceInvaders::drawSmallEnemy(){
    for (auto iEnemy = SmallList.begin(); iEnemy != SmallList.end(); ++iEnemy){
            (*iEnemy)->draw(gRenderer, assets);
            (*iEnemy)->descend();
            if((*iEnemy)->isDestroy()){
                if((*iEnemy)->hasCrossed()){
                        if(!LivesList.empty()){
                            LivesList.back()->destroyTrue();
                        }
                        else{
                            SpaceInvaders::gameOver();
                        }
                    }
                    delete *iEnemy;
                    *iEnemy = NULL;
                    SmallList.erase(iEnemy);
                    
                    std::cout << "destroyed" << std::endl;
                }
        }
}
void SpaceInvaders::drawBigEnemy(){
    for (auto iBig = BigList.begin(); iBig != BigList.end(); ++iBig){
            (*iBig)->draw(gRenderer, assets);
            (*iBig)->descend();
            if((*iBig)->isDestroy()){
                if((*iBig)->hasCrossed()){
                        if(!LivesList.empty()){
                            LivesList.back()->destroyTrue();
                        }
                        else{
                            SpaceInvaders::gameOver();
                        }
                    }
                    delete *iBig;
                    *iBig = NULL;
                    BigList.erase(iBig);
                    
                    std::cout << "Big destroyed" << std::endl;
                }
        }
}
void SpaceInvaders::smallHit(Bullet* e1, const SDL_Rect * BulletMover){       
    //Checks for intersection with a Enemy for the Bullet passed into it.
    for (auto iEnemyIntersect = SmallList.begin(); iEnemyIntersect != SmallList.end(); ++iEnemyIntersect){
            if(SDL_HasIntersection(BulletMover, (*iEnemyIntersect)->mover())){   
                    e1->destroyTrue();  //To set destroy to true after the collision
                    (*iEnemyIntersect)->destroyTrue();
                    score += 10;
                    enemyCount++;
                    
                    std::cout << std::to_string(SpaceInvaders::getScore()) << std::endl;


            }
        }
}
void SpaceInvaders::bigHit(Bullet* e1, const SDL_Rect * BulletMover){       
    //Checks for intersection with a Enemy for the Bullet passed into it.
    for (auto iBigIntersect = BigList.begin(); iBigIntersect != BigList.end(); ++iBigIntersect){
            if(SDL_HasIntersection(BulletMover, (*iBigIntersect)->mover())){   
                    e1->destroyTrue();  //To set destroy to true after the collision
                    if((*iBigIntersect)->getHealth() == 0){
                        (*iBigIntersect)->destroyTrue();
                        score += 100;
                        std::cout << std::to_string(SpaceInvaders::getScore()) << std::endl;
                    }
                    else{
                        (*iBigIntersect)->reduceHealth();
                        std::cout << "hit" << std::endl;
                    }
                    
                    


            }
        }
}
void SpaceInvaders::drawObjects(){
    //Checks if each list is empty, before drawing whatever is in that list. We have to perform the check because if we call draw on an empty list, it crashes the game(and my computer)
    if(!BulletList.empty()){
        drawBullet();
    }
    if(!SmallList.empty()){
        drawSmallEnemy();
    }
    if(!BigList.empty()){
        drawBigEnemy();
    }
    if(!LivesList.empty()){
        drawLife();
    }
    drawPlayer();
}

void SpaceInvaders::createBullet(int x, int y){
    BulletList.push_back(new Bullet(x, y));
}

void SpaceInvaders::createPlayer(int x, int y){
    playerList.push_back(new Player(x, y));
}

void SpaceInvaders::createSmallEnemy(int x, int y){
    SmallList.push_back(new SmallEnemy(x, y));
}

void SpaceInvaders::createBigEnemy(int x, int y){
    BigList.push_back(new BigEnemy(x, y));
}

void SpaceInvaders::createLife(int x, int y){
    LivesList.push_back(new Lives(x, y));
}

Player* SpaceInvaders::getPlayer(){
    return playerList.front();
}

int SpaceInvaders::getEnemyCount(){
    return enemyCount;
}

void SpaceInvaders::resetEnemyCount(){
    enemyCount = 0;
}
SpaceInvaders::SpaceInvaders(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){}
