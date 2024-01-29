#pragma once
#include "TwoDimShape.h"
class Circle :
    public TwoDimShape
{
public:
    Circle(int, int, char);
    virtual void print();
    bool operator<(const Circle&) const;
    bool operator<=(const Circle&) const;
    bool operator>(const Circle&) const;
    bool operator>=(const Circle&) const;
    bool operator==(const Circle&) const;
    bool operator!=(const Circle&) const;
    virtual double getArea();
    virtual void draw();
private:
    const double p = 3.14;
};

