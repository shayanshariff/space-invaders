#include<SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "nest.hpp"
#include<vector>
#include<list>



class SpaceInvaders{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
       
    
    public:
    Player p1;
    Bullet e1;
    Nest n1;
    std::list<Player*> pigList;
    std::list<Bullet*> BulletList;
    std::list<Nest*> nestList;
    SpaceInvaders(SDL_Renderer *, SDL_Texture *);
    void babyPlayer(Bullet* e1, const SDL_Rect *  BulletMover);
    void createPlayer(int x, int y);
    Player* getPlayer();
    void drawPlayer();
    void drawBullet();
    void drawNest();
    void drawObjects(); 
    void createObject(int, int);
};