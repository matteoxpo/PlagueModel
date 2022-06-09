#include "SimplePeople.h"
#include <string>
#include <iostream>

SimplePeople::SimplePeople() : People(),
    sickStatus{ false },
    incubationPeriod{ 0 },
    infective{ false }
{}
SimplePeople::SimplePeople(const SimplePeople& other): People(other.xCoord, other.yCoord, other.xSpeed, other.ySpeed),
    sickStatus{ other.sickStatus },
    incubationPeriod{ other.incubationPeriod },
    infective{ other.infective }
{}

SimplePeople::SimplePeople(float x, float y, float xspeed, float yspeed) :
    People(x,y,xspeed,yspeed),
    sickStatus{false},
    incubationPeriod{0},
    infective{false}
{}
SimplePeople::SimplePeople(float x, float y, float xspeed, float yspeed, bool sick, int incubPer, bool inf): People(x,y,xspeed,yspeed),sickStatus(sick)
{
    if (incubPer < 0) throw std::logic_error("Negative incubation period!");
    incubationPeriod = incubPer;
    infective = inf;
}

void SimplePeople::sickStatusUpdate(bool sick, int per) {
    sickStatus = sick;
    incubationPeriod = per;
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

std::ostream& operator <<(std::ostream& out, std::shared_ptr<SimplePeople> p) {
    out << "X coord: " << p->getX() << std::endl;
    out << "Y coord: " << p->getY() << std::endl;
    out << "X speed: " << p->getSpeedX() << std::endl;
    out << "Y speed: " << p->getSpeedY() << std::endl;
    out << "Incubation period: " << p->getIncubationPerion() << std::endl;
    out << "Sick status: " << p->getSickStatus();
    if (p->getSickStatus() == true)
        out << " - is ill" << std::endl;
    else
        out << " - isn't ill" << std::endl;
    std::cout << std::endl;
    return out;
}