#pragma once
#include "Shape.h"

//derived rectangle class from the base shape class, with override on the draw method
class Rectangle :
    public Shape
{
public:
    Rectangle(std::string);
    void draw() const override;

};

