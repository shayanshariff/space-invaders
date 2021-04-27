#include<SDL.h>
#include "Player.hpp"
#include "egg.hpp"
#include "nest.hpp"
#include<vector>
#include<list>



class SpaceInvaders{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
       
    
    public:
    Player p1;
    Egg e1;
    Nest n1;
    std::list<Player*> pigList;
    std::list<Egg*> eggList;
    std::list<Nest*> nestList;
    SpaceInvaders(SDL_Renderer *, SDL_Texture *);
    void babyPlayer(Egg* e1, const SDL_Rect *  eggMover);
    void createPlayer(int x, int y);
    Player* getPlayer();
    void drawPlayer();
    void drawEgg();
    void drawNest();
    void drawObjects(); 
    void createObject(int, int);
};