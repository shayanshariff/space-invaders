#pragma once
#include"ECS.hpp"

class PositionComponent : public Component{
    int xpos, ypos;

    public:

    int x() {return xpos;}
    int y() {return ypos;}

    void init() override{
        xpos = 0;
        ypos = 0;
    }

    void update() override{
        xpos++;
        ypos++;
    }
    void setPos(int x, int y){
        xpos = x;
        ypos = y;
    }

};