#include "Rectangle.h"

Rectangle::Rectangle(std::string colour,double width, double height) :Shape(colour), a(width), b(height)
{
}

// overrides the pure virtual method from the base class
double Rectangle::area() const
{
	return a * b;
}

//overrides the draw method
void Rectangle::draw() const
{
	std::cout << "Drawing a " << this->colour << "rectangle!\n";
}