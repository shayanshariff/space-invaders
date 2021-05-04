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
//These  draw functions are all basically the same, iterate through the list to draw, and call the destroy function if isDestroy(). Also call the collision functions where applicable
void SpaceInvaders::drawPlayer(){
        for (auto iplayer = playerList.begin(); iplayer != playerList.end(); ++iplayer){
            (*iplayer)->draw(gRenderer, assets);
            collectLife((*iplayer), (*iplayer)->mover());
            collectFire((*iplayer), (*iplayer)->mover());
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

void SpaceInvaders::drawLifeUp(){
        for (auto iLifeUp = LifeUpList.begin(); iLifeUp != LifeUpList.end(); ++iLifeUp){
            (*iLifeUp)->draw(gRenderer, assets);
            (*iLifeUp)->descend();
            if((*iLifeUp)->isDestroy()){
                delete *iLifeUp;
                *iLifeUp = NULL;
                LifeUpList.erase(iLifeUp);
            }
        }
    }


void SpaceInvaders::drawFireUp(){
        for (auto iFireUp = FireUpList.begin(); iFireUp != FireUpList.end(); ++iFireUp){
            (*iFireUp)->draw(gRenderer, assets);
            (*iFireUp)->descend();
            if((*iFireUp)->isDestroy()){
                delete *iFireUp;
                *iFireUp = NULL;
                FireUpList.erase(iFireUp);
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
                    bossKilled = true;
                    delete *iBig;
                    *iBig = NULL;
                    BigList.erase(iBig);
                    

                }
        }
}

void SpaceInvaders::collectLife(Player* p1, const SDL_Rect * PlayerMover){       

    for (auto iLifeIntersect = LifeUpList.begin(); iLifeIntersect != LifeUpList.end(); ++iLifeIntersect){
            if(SDL_HasIntersection(PlayerMover, (*iLifeIntersect)->mover())){   
                    (*iLifeIntersect)->destroyTrue();
                    if(LivesList.empty()){
                        createLife(5, 570);
                    }
                    createLife(LivesList.back()->getX() + 21, 570);

            }
        }
}

void SpaceInvaders::collectFire(Player* p1, const SDL_Rect * PlayerMover){       

    for (auto iFireIntersect = FireUpList.begin(); iFireIntersect != FireUpList.end(); ++iFireIntersect){
            if(SDL_HasIntersection(PlayerMover, (*iFireIntersect)->mover())){   
                    (*iFireIntersect)->destroyTrue();
                    fireUpTaken = true;

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

//check if a fireUp has been picked up, to avoid repeated drops
bool SpaceInvaders::fireUpCheck(){
    return fireUpTaken;
}
//Check if boss has been killed, to spawn a powerUp
bool SpaceInvaders::isBossKilled(){
    return bossKilled;
}
//reset the boss bool after the powerup is spawned
void SpaceInvaders::resetBossKilled(){
    bossKilled = false;
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
    if(!LifeUpList.empty()){
        drawLifeUp();
    }
    if(!FireUpList.empty()){
        drawFireUp();
    }
    //no check needed for this since we instantiate player in game.cpp 
    drawPlayer();
}

//to create new instances of each object
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

void SpaceInvaders::createLifeUp(int x, int y){
    LifeUpList.push_back(new lifeUp(x, y));
}

void SpaceInvaders::createFireUp(int x, int y){
    FireUpList.push_back(new fireUp(x, y));
}

//returns the player
Player* SpaceInvaders::getPlayer(){
    return playerList.front();
}
//functions to get and reset enemy count, for boss spawning
int SpaceInvaders::getEnemyCount(){
    return enemyCount;
}

void SpaceInvaders::resetEnemyCount(){
    enemyCount = 0;
}
SpaceInvaders::SpaceInvaders(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){}
