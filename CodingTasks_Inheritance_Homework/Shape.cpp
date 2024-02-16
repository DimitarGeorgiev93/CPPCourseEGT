#include "Shape.h"

Shape::Shape(std::string colour):colour(colour)
{
}

void Shape::draw() const
{
	std::cout << "Drawing a " << this->colour << " shape!\n";
}


