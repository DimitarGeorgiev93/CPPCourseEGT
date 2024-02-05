#pragma once
#include "Car.h"

class FastCar :
    public Car
{
public:
    FastCar(std::string name) : Car(name+"fc") {};
    virtual void tick (double sec);
private:

};

