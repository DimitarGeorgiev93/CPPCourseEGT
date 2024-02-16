#include "Circle.h"

Circle::Circle(std::string colour, double radius): Shape(colour), radius(radius)
{
}

// overrides the pure virtual method from the base class
double Circle::area() const
{
	return this->radius * this->radius * M_PI;
}

//overrides the draw method
void Circle::draw() const
{
	std::cout << "Drawing a " << this->colour << "circle!\n";
}
