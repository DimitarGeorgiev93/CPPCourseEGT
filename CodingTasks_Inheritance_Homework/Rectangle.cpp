#include "Rectangle.h"

Rectangle::Rectangle(std::string colour) :Shape(colour){
}

//overrides the draw method
void Rectangle::draw() const
{
	std::cout << "Drawing a " << this->colour << " rectangle!\n";
}