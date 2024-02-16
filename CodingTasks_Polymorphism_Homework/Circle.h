#pragma once
#include "Shape.h"

//derived circle class from the abstract shape class, with override on the draw method

const double M_PI = 3.14;

class Circle :
    public Shape
{
public:
    Circle(double);
    double area() const override;

private:
    double radius;
};

