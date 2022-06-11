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

    void Nothing();
    //std::ostream& operator<<(std::ostream&, const Doctor&);
    friend std::ostream& operator <<(std::ostream&, Doctor&);
    friend std::ostream& operator <<(std::ostream&, std::shared_ptr<Doctor>);
};

