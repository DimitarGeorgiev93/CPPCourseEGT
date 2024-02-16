#include "Circle.h"

Circle::Circle(std::string colour): Shape(colour)
{
}

void Circle::draw() const
{
	std::cout << "Drawing a " << this->colour << " circle!\n";
}
