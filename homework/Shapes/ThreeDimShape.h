#pragma once
#include "TwoDimShape.h"
class ThreeDimShape :
    public TwoDimShape
{
public:
    virtual double getArea();
    virtual void print();
    ThreeDimShape(int,int,int,char);


private:
    int z;
};

