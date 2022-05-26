#include "SimplePeople.h"
#include <string>
#include <iostream>

SimplePeople::SimplePeople() :
    xCoord{ 0 },
    yCoord{ 0 },
    xSpeed{ 0 },
    ySpeed{ 0 },
    sickStatus{ false },
    incubationPeriod{ 0 },
    infective{ false }
{}
SimplePeople::SimplePeople(const SimplePeople& other):
    xCoord{ other.xCoord },
    yCoord{ other.yCoord },
    xSpeed{ other.xSpeed },
    ySpeed{ other.ySpeed },
    sickStatus{ other.sickStatus },
    incubationPeriod{ other.incubationPeriod },
    infective{ other.infective }
{}

SimplePeople::SimplePeople(float x, float y, float xspeed, float yspeed) :
    xCoord{x},
    yCoord{y},
    xSpeed{xspeed},
    ySpeed{yspeed},
    sickStatus{false},
    incubationPeriod{0},
    infective{false}
{}
SimplePeople::SimplePeople(float x, float y, float xspeed, float yspeed, bool sick, int incubPer, bool inf) {
    if (incubationPeriod < 0) throw std::logic_error("Negative incubation period!");
    xCoord = x;
    yCoord = y;
    xSpeed = xspeed;
    ySpeed = yspeed;
    sickStatus = sick;
    incubationPeriod = incubPer;
    infective = inf;
}


void SimplePeople::positionUpdate() {
    xCoord += xSpeed;
    yCoord += ySpeed;
}
void SimplePeople::sickStatusUpdate(bool sick, int per) {
    sickStatus = sick;
    incubationPeriod = per;
}
void SimplePeople::infect() {

}



std::ostream& operator <<(std::ostream& out, SimplePeople& p) {
        out << "X coord: " << p.getX() << std::endl;
        out << "Y coord: " << p.getY() << std::endl;
        out << "X speed: " << p.getSpeedX() << std::endl;
        out << "Y speed: " << p.getSpeedY() << std::endl;
        out << "Incubation period: " << p.getIncubationPerion() << std::endl;
        out << "Sick status: " << p.getSickStatus();
        if (p.getSickStatus() == true)
            out << " - is ill" << std::endl;
        else
            out << " - isn't ill" << std::endl;
        std::cout << std::endl;
        return out;
}

/*
std::ostream& operator<<(std::ostream& out,SimplePeople ppl)
{
    out << "x coord: " << ppl.getX();
    return out;
}
*/