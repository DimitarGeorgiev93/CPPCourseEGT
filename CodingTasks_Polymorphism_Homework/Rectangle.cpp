#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : a(width), b(height)
{
}

// overrides the pure virtual function from the base class
double Rectangle::area() const
{
	return a * b;
}
