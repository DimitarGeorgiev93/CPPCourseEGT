#pragma once

#include<string>
#include<iostream>
#include "Road.h"
//#include "BaseVenicle.h"

//class RepairVenicle;

class BaseVenicle
{
public:

    //friend void RepairVenicle::repairCar(BaseVenicle*);
    
    BaseVenicle(std::string name) : road(NULL), name(name), meters(0), crashed(false) {};
    virtual void tick(double sec) = 0;
    void assignRoad(Road* road);
    bool hasFinished();
    Road* getRoad() const;
    bool hasCrashed() const;
    void printName() const;
    double getMeters() const;
    void getRepaired();
protected:
    bool crashed;
    std::string name;
    Road* road;
    double meters;
};

