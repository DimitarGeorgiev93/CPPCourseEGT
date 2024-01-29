#pragma once
#include "TwoDimShape.h"

class Triangle:
    public TwoDimShape
{public:
    Triangle(int, int, int, char);
    virtual void print();
    virtual double getArea() const;
    virtual void draw();

    bool operator<(const Triangle&) const;
    bool operator<=(const Triangle&) const;
    bool operator>(const Triangle&) const;
    bool operator>=(const Triangle&) const;
    bool operator==(const Triangle&) const;
    bool operator!=(const Triangle&) const;
private:
    double hypotenuse;
};

