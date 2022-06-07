#include "Doctor.h"
#include <iostream>
Doctor::Doctor() : People(){}
Doctor::Doctor(float x, float y, float xspeed, float yspeed) : People(x,y,xspeed,yspeed) {}

void Doctor::treat(SimplePeople& ppl) {
    ppl.sickStatusUpdate(false, 0);
}

std::ostream& operator <<(std::ostream& out, Doctor& d) {
    out << "X coord: " << d.getX() << std::endl;
    out << "Y coord: " << d.getY() << std::endl;
    out << "X speed: " << d.getSpeedX() << std::endl;
    out << "Y speed: " << d.getSpeedY() << std::endl;
    out << std::endl;
    return out;
}

