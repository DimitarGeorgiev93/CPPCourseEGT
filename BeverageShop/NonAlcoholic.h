#pragma once
#include "Beverage.h"


class NonAlcoholic :
    public Beverage
{
public:
    NonAlcoholic(std::string name, std::string brand, double price, double volume);
    virtual double calculatePrice();
    virtual void printInfo();
private:

};

