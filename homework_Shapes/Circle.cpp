#include "Circle.h"

Circle::Circle(int r, int pos = 0, char drawingChar = '*') :TwoDimShape(r, 1, pos, drawingChar)
{

}

void Circle::print()
{
	std::cout << "This is a Circle " << getArea() << std::endl;
}

bool Circle::operator<(const Circle& circle) const
{
    return this->Shape::getX() < circle.Shape::getX();
}

bool Circle::operator<=(const Circle& circle) const
{
    return this->Shape::getX() <= circle.Shape::getX();
}

bool Circle::operator>(const Circle& circle) const
{
    return this->Shape::getX() > circle.Shape::getX();
}

bool Circle::operator>=(const Circle& circle) const
{
    return this->Shape::getX() >= circle.Shape::getX();
}

bool Circle::operator==(const Circle& circle) const
{
    return this->Shape::getX() == circle.Shape::getX();
}

bool Circle::operator!=(const Circle& circle) const
{
    return this->Shape::getX() != circle.Shape::getX();
}


 double Circle::getArea()
  {
     return 2 * p * Shape::getX();
  }

void Circle::draw()
{
    drawLinesAbove();

    int radius = Shape::getX();
    for (int i = 0; i <= 2 * radius; i++)
    {
        drawLinesLeft();

        for (int j = 0; j <= 2 * radius; j++)
        {
            double distance = sqrt((double)(i - radius) * (i - radius) + (j - radius) * (j - radius));
            if (distance > radius - 0.65 && distance < radius + 0.2)
            {
                std::cout << Shape::getDrawingChar();
            }
            else
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}
