#pragma once
#include <iostream>
#include "SimplePeople.h"
class Doctor
{
    float xCoord;
    float yCoord;
    float xSpeed;
    float ySpeed;
public:
    Doctor();
    Doctor(float, float, float, float);
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

    void positionUpdate();

    void treat(SimplePeople &);

    friend std::ostream& operator <<(std::ostream&, Doctor&);
};

