#include "Triangle.h"

Triangle::Triangle(int x, int y, int pos, char drawingChar) :TwoDimShape(x, y, pos, drawingChar)
{
	this->hypotenuse = std::sqrt(x * x + y * y);
}

void Triangle::print()
{
}

double Triangle::getArea() const
{
    return this->getX() * this->getY() / 2;
}

void Triangle::draw()
{
    drawLinesAbove();

    int triangleBuffer = 1;
    for (int i = 0; i < Shape::getX() ; i++) {

        drawLinesLeft();

        for (int j = 0; j < TwoDimShape::getY(); j++) { //Shape::getX()

            if (i == 0 || (i == Shape::getX()  && Shape::getX() != triangleBuffer) || j == 0 || j == Shape::getX() - triangleBuffer) {
                std::cout << Shape::getDrawingChar();
            }
            else std::cout << ' ';
        }
        //4 15 10 5 h
        triangleBuffer++;
        std::cout << std::endl;
    }
}

bool Triangle::operator<(const Triangle& triangle) const
{
    return this->getArea() < triangle.getArea();
}
bool Triangle::operator<=(const Triangle& triangle) const
{
    return this->getArea() <= triangle.getArea();
}

bool Triangle::operator>(const Triangle& triangle) const
{
    return this->getArea() > triangle.getArea();
}

bool Triangle::operator>=(const Triangle& triangle) const
{
    return this->getArea() >= triangle.getArea();
}

bool Triangle::operator==(const Triangle& triangle) const
{
    return this->getArea() == triangle.getArea();
}

bool Triangle::operator!=(const Triangle& triangle) const
{
    return this->getArea() != triangle.getArea();
}

