#include "People.h"

People::People() :
    xCoord{ 0 },
    yCoord{ 0 },
    xSpeed{ 0 },
    ySpeed{ 0 }
{}
People::People(float x, float y, float xspeed, float yspeed) :
    xCoord{ x },
    yCoord{ y },
    xSpeed{ xspeed },
    ySpeed{ yspeed }
{}

void People::positionUpdate(int dt) {
    xCoord += xSpeed * dt;
    yCoord += ySpeed * dt;
}


