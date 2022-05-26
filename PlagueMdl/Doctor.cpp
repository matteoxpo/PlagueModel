#include "Doctor.h"
#include <iostream>
Doctor::Doctor() :
    xCoord{ 0 },
    yCoord{ 0 },
    xSpeed{ 0 },
    ySpeed{ 0 }
{}
Doctor::Doctor(float x, float y, float xspeed, float yspeed) {
    xCoord = x;
    yCoord = y;
    xSpeed = xspeed;
    ySpeed = yspeed;
}

void Doctor::positionUpdate() {
    xCoord += xSpeed;
    yCoord += ySpeed;
}

void Doctor::treat(SimplePeople &ppl) {
    ppl.sickStatusUpdate(false);
}

std::ostream& operator <<(std::ostream& out, Doctor& d){clude "Doctor.h"
#include <iostream>
Doctor::Doctor() :
    xCoord{ 0 },
    /*asdasdvbjhvbu*/yCoord{0},

    out << "X coord: " << d.getX() << std::endl;
    out << "Y coord: " << d.getY() << std::endl;
    out << "X speed: " << d.getSpeedX() << std::endl;
    out << "Y speed: " << d.getSpeedY() << std::endl;
    out << std::endl;
    return out;
}
