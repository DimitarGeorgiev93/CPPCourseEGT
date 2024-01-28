#pragma once
#include "TwoDimShape.h"
class Rectangle :
    public TwoDimShape
{
public:
    Rectangle(int, int, int, char);
    virtual void print();
    virtual double getArea() const;
    virtual void draw();
    bool operator<( const Rectangle&) const;
    bool operator<=(const Rectangle&) const;
    bool operator>(const Rectangle&) const;
    bool operator>=(const Rectangle&) const;
    bool operator==(const Rectangle&) const;
    bool operator!=(const Rectangle&) const;
private:
};

