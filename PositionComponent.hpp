#pragma once
#include"Components.hpp"

class PositionComponent : public Component{
    int xpos, ypos;

    public:

    PositionComponent(){
        xpos = 0;
        ypos = 0;
    }
    
    PositionComponent(int x, int y){
        xpos = x;
        ypos = y;
    }

    int x() {return xpos;}
    int y() {return ypos;}

    void x(int x){
        xpos = x;
    }
    void y(int y){
        ypos = y;
    }

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
