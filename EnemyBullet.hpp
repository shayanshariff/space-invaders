#include<SDL.h>
#include "unit.hpp"
#include"Bullet.hpp"

class EnemyBullet: Unit{

public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void shoot();
    bool isDestroy();
    void destroyTrue();
    SDL_Rect *mover();
    EnemyBullet();
    EnemyBullet(int x, int y);
};