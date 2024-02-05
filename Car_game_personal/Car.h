#pragma once


#include "BaseVenicle.h"
class Road;

class Car : public BaseVenicle{
public:
    Car(std::string name) : BaseVenicle(name) {};
 /*   void assignRoad(Road* road);
    bool hasFinished();*/
    virtual void tick(double sec);
    /*Road* getRoad() const;
    bool hasCrashed() const;
    void printName() const;*/
//private:
//    bool crashed;
//    std::string name;
//    Road* road;
//    double meters;
};
