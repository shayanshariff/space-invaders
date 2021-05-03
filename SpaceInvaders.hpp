#include<SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include"SmallEnemy.hpp"
#include"BigEnemy.hpp"
#include "Enemy.hpp"
#include"Lives.hpp"
#include<vector>
#include<list>



class SpaceInvaders{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    int score = 0;
    bool gameOverState = false;
    int enemyCount = 0;
    
    public:
    int getScore();
    std::list<Player*> playerList;
    std::list<Bullet*> BulletList;
    std::list<Enemy*> EnemyList;
    std::list<Lives*> LivesList;
    std::list<BigEnemy*> BigList;
    std::list<SmallEnemy*> SmallList;
    SpaceInvaders(SDL_Renderer *, SDL_Texture *);
    void smallHit(Bullet* e1, const SDL_Rect *  BulletMover);
    void bigHit(Bullet* e1, const SDL_Rect *  BulletMover);
    void createPlayer(int x, int y);
    void createSmallEnemy(int x, int y);
    void createBigEnemy(int x, int y);
    void createLife(int x, int y);
    bool isGameOver();
    void gameOver();
    Player* getPlayer();
    int getEnemyCount();
    void resetEnemyCount();
    void drawPlayer();
    void drawBullet();
    void drawSmallEnemy();
    void drawBigEnemy();
    void drawLife();
    void drawObjects(); 
    void createBullet(int, int);
};