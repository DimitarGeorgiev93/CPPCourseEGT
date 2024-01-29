#include "TwoDimShape.h"




TwoDimShape::TwoDimShape(int x = 1, int y = 1, int pos = 0, char drawingShape = '*') : Shape(x, pos, drawingShape)
{
	this->y = y;
}

int TwoDimShape::getY() const
{
	return this->y;
}
