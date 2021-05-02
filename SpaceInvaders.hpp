#include<SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include"Lives.hpp"
#include<vector>
#include<list>



class SpaceInvaders{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    int score = 0;
    bool gameOverState = false;
    
    public:
    Player p1;
    Bullet e1;
    Enemy n1;
    int getScore();
    std::list<Player*> playerList;
    std::list<Bullet*> BulletList;
    std::list<Enemy*> EnemyList;
    std::list<Lives*> LivesList;
    SpaceInvaders(SDL_Renderer *, SDL_Texture *);
    void enemyHit(Bullet* e1, const SDL_Rect *  BulletMover);
    void createPlayer(int x, int y);
    void createEnemy(int x, int y);
    void createLife(int x, int y);
    bool isGameOver();
    void gameOver();
    Player* getPlayer();
    void drawPlayer();
    void drawBullet();
    void drawEnemy();
    void drawLife();
    void drawObjects(); 
    void createBullet(int, int);
};