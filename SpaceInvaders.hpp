#include<SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include<vector>
#include<list>



class SpaceInvaders{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
       
    
    public:
    Player p1;
    Bullet e1;
    Enemy n1;
    std::list<Player*> playerList;
    std::list<Bullet*> BulletList;
    std::list<Enemy*> EnemyList;
    SpaceInvaders(SDL_Renderer *, SDL_Texture *);
    void enemyHit(Bullet* e1, const SDL_Rect *  BulletMover);
    void createPlayer(int x, int y);
    void createEnemy(int x, int y);
    Player* getPlayer();
    void drawPlayer();
    void drawBullet();
    void drawEnemy();
    void drawObjects(); 
    void createBullet(int, int);
};