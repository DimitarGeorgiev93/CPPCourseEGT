#pragma once
#include "Shape.h"


class TwoDimShape :
    public Shape
{
public:
    //virtual double getArea();
    //virtual void print();
    TwoDimShape(int,int,int, char);
    int getY() const;
private:
    int y;
};

