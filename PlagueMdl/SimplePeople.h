#pragma once
#include <iostream>
class SimplePeople
{
    float xCoord;
    float yCoord;
    float xSpeed;
    float ySpeed;
    bool sickStatus;

    int incubationPeriod;
    bool infective;

public: 
    //SimplePeople p();
    SimplePeople();
    SimplePeople(const SimplePeople&);
    SimplePeople(float, float, float, float);
    SimplePeople(float, float, float, float, bool, int, bool);
    //friend std::ostream& operator<<(std::ostream& ,SimplePeople);
    //SimplePeople(const SimplePeople&);
    inline float getX() const {
        return xCoord;
    }
    inline float getY() const {
        return yCoord;
    }
    inline float getSpeedX() const {
        return xSpeed;
    }
    inline float getSpeedY() const {
        return ySpeed;
    }
    inline bool getSickStatus() const {
        return sickStatus;
    }
    inline int getIncubationPerion() const {
        return incubationPeriod;
    }
    inline void setX(float coordX) {
        xCoord = coordX;
    }
    inline void setY(float coordY) {
        yCoord = coordY;
    }
    inline void setSpeedX(float speedX) {
        xSpeed = speedX;
    }
    inline void setSpeedY(float speedY) {
        ySpeed = speedY;
    }
    inline void setIncubationPeriod(int per) {
        incubationPeriod = per;
    }
    inline void setInfective(bool inf) {
        infective = inf;
    }
    void positionUpdate();
    void sickStatusUpdate(bool);

    void infect(SimplePeople &);

    friend std::ostream& operator <<(std::ostream&, SimplePeople&);
    // std:: cout << p;
};

