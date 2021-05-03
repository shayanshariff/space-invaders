#include"SmallEnemy.hpp"


SmallEnemy::SmallEnemy(){
    srcRect = {940, 130, 200, 200};
    moverRect = {40, 40, 60, 70};
}
SmallEnemy::SmallEnemy(int x, int y){
    srcRect = {940, 130, 200, 200};
    moverRect = {x, y, 32, 32};

}