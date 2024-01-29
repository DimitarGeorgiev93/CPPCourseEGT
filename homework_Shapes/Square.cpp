#include "Square.h"

Square::Square(int x, int y = 1, int pos = 0, char drawingChar = '*') :TwoDimShape(x, y, pos, drawingChar)
{
}

void Square::print()
{
    std::cout << "This is a Square " << getArea() << std::endl;
}

double Square::getArea()
{
    return Shape::getX() * Shape::getX();
}

void Square::draw()
{
    drawLinesAbove();

    for (int i = 0 ; i < Shape::getX() ; i++) {

        drawLinesLeft();

        for (int j = 0; j < Shape::getX() ; j++) {

            if (i == 0 || i == Shape::getX() - 1 || j == 0 || j == Shape::getX() - 1) {
                std::cout << Shape::getDrawingChar();
            }
            else std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

bool Square::operator<(const Square& square) const
{
    return this->Shape::getX() < square.Shape::getX();
}

bool Square::operator<=(const Square& square) const
{
    return this->Shape::getX() <= square.Shape::getX();
}

bool Square::operator>(const Square& square) const
{
    return this->Shape::getX() > square.Shape::getX();
}

bool Square::operator>=(const Square& square) const
{
    return this->Shape::getX() >= square.Shape::getX();
}

bool Square::operator==(const Square& square) const
{
    return this->Shape::getX() == square.Shape::getX();
}

bool Square::operator!=(const Square& square) const
{
    return this->Shape::getX() != square.Shape::getX();
}
