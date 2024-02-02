#pragma once

#include "Package.h"

class ExpressPackage :
    public Package
{
public:
    ExpressPackage(Adress, Adress, double, double, double);
    virtual void calculateCost();
    virtual void print();
private:
    double extraCost;
};

