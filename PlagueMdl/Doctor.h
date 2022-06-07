#pragma once
#include <iostream>
#include "SimplePeople.h"
#include "People.h"
class Doctor : public People
{
public:
    Doctor();
    Doctor(float, float, float, float);

    void treat(SimplePeople &);

    friend std::ostream& operator <<(std::ostream&, Doctor&);
};

