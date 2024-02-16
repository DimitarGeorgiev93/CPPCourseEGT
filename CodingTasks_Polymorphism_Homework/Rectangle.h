#pragma once
#include "Shape.h"

//derived rectangle class from the abstract shape class, with override on the area method
class Rectangle :
    public Shape
{
public:
    Rectangle(double, double);
    double area() const override;
private:
    double a;
    double b;
};

