#include "Shape.h"

void Shape::print()
{
	std::cout << x << " " << std::endl;
}

void Shape::drawLinesAbove()
{
	int count = 0;
	while (count++ < Shape::getPositionFromCenter()) {
		std::cout << std::endl;
	}
}

void Shape::drawLinesLeft()
{
	int count = 0;
	while (count++ < Shape::getPositionFromCenter()) {
		std::cout << " ";
	}
}

const int Shape::getPositionFromCenter()
{
	return positionFromCenter;
}

Shape::Shape(int x = 1, int pos = 0, char drawingChar = '*')
{	
	this->drawingChar = drawingChar;
	this->positionFromCenter = pos;
	this->x = x;
}

int Shape::getX() const
{
	return x;
}

const char Shape::getDrawingChar()
{
	return this->drawingChar;
}
