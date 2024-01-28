#include "Rectangle.h"

Rectangle::Rectangle(int x = 1, int y = 1, int pos = 0, char drawingChar = '*') : TwoDimShape(x, y, pos, drawingChar)
{

}

void Rectangle::print()
{
    std::cout << "This is a Rectangle " << getArea() << std::endl;
}

double Rectangle::getArea() const
{
    return Shape::getX() * TwoDimShape::getY();
}

void Rectangle::draw()
{
    drawLinesAbove();

    for (int i = 0; i < Shape::getX(); i++) {

        drawLinesLeft();

        for (int j = 0; j < TwoDimShape::getY(); j++) {
            if (i == 0 || i == Shape::getX()-1 || j == 0 || j == TwoDimShape::getY()-1) {
                std::cout << Shape::getDrawingChar();
            }
            else std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

bool Rectangle::operator<(const Rectangle& rec) const
{
    return this->getArea() < rec.getArea();
}
bool Rectangle::operator<=(const Rectangle& rec) const
{
    return this->getArea() <= rec.getArea();
}
bool Rectangle::operator>(const Rectangle& rec) const
{
    return this->getArea() > rec.getArea();
}
bool Rectangle::operator>=(const Rectangle& rec) const
{
    return this->getArea() >= rec.getArea();
}
bool Rectangle::operator==(const Rectangle& rec) const
{
    return this->getArea() == rec.getArea();
}
bool Rectangle::operator!=(const Rectangle& rec) const
{
    return this->getArea() != rec.getArea();
}

