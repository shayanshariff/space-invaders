#include<SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include"SmallEnemy.hpp"
#include"BigEnemy.hpp"
#include "Enemy.hpp"
#include"Lives.hpp"
#include"fireUp.hpp"
#include"lifeUp.hpp"
#include<vector>
#include<list>



class SpaceInvaders{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    int score = 0;
    bool gameOverState = false;
    bool fireUpTaken = false;
    int enemyCount = 0;
    bool bossKilled = false;
    public:
    int getScore();
    std::list<Player*> playerList;
    std::list<Bullet*> BulletList;
    std::list<Enemy*> EnemyList;
    std::list<Lives*> LivesList;
    std::list<BigEnemy*> BigList;
    std::list<SmallEnemy*> SmallList;
    std::list<lifeUp*> LifeUpList;
    std::list<fireUp*> FireUpList;
    SpaceInvaders(SDL_Renderer *, SDL_Texture *);
    bool fireUpCheck();
    void smallHit(Bullet* e1, const SDL_Rect *  BulletMover);
    void bigHit(Bullet* e1, const SDL_Rect *  BulletMover);
    void collectLife(Player* p1, const SDL_Rect * PlayerMover);
    void collectFire(Player* p1, const SDL_Rect * PlayerMover);
    bool isBossKilled();
    void resetBossKilled();
    void createPlayer(int x, int y);
    void createSmallEnemy(int x, int y);
    void createBigEnemy(int x, int y);
    void createLife(int x, int y);
    void createLifeUp(int x, int y);
    void createFireUp(int x, int y);
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
    void drawLifeUp();
    void drawFireUp();
    void drawObjects(); 
    void createBullet(int, int);
};