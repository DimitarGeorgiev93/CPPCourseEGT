#include "Circle.h"

Circle::Circle(double radius): radius(radius)
{
}

// overrides the pure virtual function from the base class
double Circle::area() const
{
	return this->radius * this->radius * M_PI;
}
