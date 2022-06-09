#pragma once
#include <iostream>
#include "People.h"
class SimplePeople : public People
{
    bool sickStatus;
    int incubationPeriod;
    bool infective;

public: 
    SimplePeople();
    SimplePeople(const SimplePeople&);
    SimplePeople(float, float, float, float);
    SimplePeople(float, float, float, float, bool, int, bool);

    inline bool getSickStatus() const {
        return sickStatus;
    }
    inline int getIncubationPerion() const {
        return incubationPeriod;
    }

    inline void setIncubationPeriod(int per) {
        incubationPeriod = per;
    }
    inline void setInfective(bool inf) {
        infective = inf;
    }
    
    void sickStatusUpdate(bool,int);

    friend std::ostream& operator <<(std::ostream&, SimplePeople&);
    friend std::ostream& operator <<(std::ostream&, std::shared_ptr<SimplePeople>);
};

