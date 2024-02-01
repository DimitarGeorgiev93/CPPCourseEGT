#pragma once
#include "Car.h"

enum PremTax {SHAMPAGNE = 100,WINE = 50,CHOCOLATE = 40 };
class PremiumCar :
    public Car
{
public:
    PremiumCar( PremTax, Brand, std::string, Type, Colour, std::string, std::string, double, double);
    const PremTax getPremiumTax();
    virtual void print();
private:
    PremTax premiumTax;
};

