#pragma once
#include "Beverage.h"

class Alcohol :
    public Beverage
{

public:
    Alcohol(std::string, std::string, double, double, double);
    virtual double calculatePrice();
    virtual void printInfo();
private:
    const double alcoholVolume;
    const double alcoholTax = 1.07;
};

