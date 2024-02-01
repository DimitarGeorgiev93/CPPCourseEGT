#pragma once
#include <iostream>
#include<math.h>

class Rectangle {

public:
    Rectangle();
    void setBotLeft();
    void setTopLeft();
    void setTopRight();
    void setBotRight();
    bool coordCheck( const double,const double);
    void calculateParams();
    bool rectangleCheck();
    bool squareCheck();
    void printLenth();
    void printHeight();
    void printPerim();
    void printArea();
private:

    double lenght;
    double height;
    double perim, area;
    double d1, d2, d3; // botleft->botright, botleft-topright, botleft-topleft
    std::pair<double,double> topLeft;
    std::pair<double, double> topRight;
    std::pair<double, double> botLeft;
    std::pair<double, double> botRight;
    
};
