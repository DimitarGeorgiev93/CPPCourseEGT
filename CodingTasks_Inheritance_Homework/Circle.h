#pragma once
#include "Shape.h"

//derived circle class with override on the draw method
class Circle :
    public Shape
{
public:
    Circle(std::string);
    void draw() const override;
};

