#pragma once
#include "TwoDimShape.h"
class Square :
    public TwoDimShape
{
public:
    Square(int ,int, int, char);
    virtual void print();
    virtual double getArea();
    virtual void draw();
    bool operator<(const Square&) const;
    bool operator<=(const Square&) const;
    bool operator>(const Square&) const;
    bool operator>=(const Square&) const;
    bool operator==(const Square&) const;
    bool operator!=(const Square&) const;
private:

};

