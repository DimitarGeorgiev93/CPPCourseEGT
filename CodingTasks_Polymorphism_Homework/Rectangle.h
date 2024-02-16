#pragma once
#include "Shape.h"

//derived rectangle class from the abstract shape class, with override on the area method
class Rectangle :
    public Shape
{
public:
    Rectangle(std::string, double, double);
    double area() const override;
    void draw() const override;
private:
    double a;
    double b;
};

