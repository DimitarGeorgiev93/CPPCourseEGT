#include "ThreeDimShape.h"

double ThreeDimShape::getArea()
{
	return 0;
}

void ThreeDimShape::print()
{
	std::cout << Shape::getX() << " " << TwoDimShape::getY() << " " << z << std::endl;
}

ThreeDimShape::ThreeDimShape(int x = 1, int y = 1 , int z = 1, char drawingShape = '*') :TwoDimShape(x, y, 0, drawingShape)
{
	this->z = z;
}
