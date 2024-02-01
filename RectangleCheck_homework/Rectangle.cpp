#include "Rectangle.h"

Rectangle::Rectangle()
{
	setBotLeft();
	setBotRight();
	setTopRight();
	setTopLeft();
	calculateParams();
	if (rectangleCheck() == true) {
		if (squareCheck()) {
			std::cout << "The points form a square" << std::endl;
		}
		else {
			std::cout << "The points form a rectangle" << std::endl;
		}
		printLenth();
		printHeight();
		printPerim();
		printArea();
	} 
	else {
		std::cout << "The points dont form a rectangle" << std::endl;
	}
}

void Rectangle::setBotLeft()
{
	botLeft.first = -1;
	botLeft.second = -1;
	while (!coordCheck(botLeft.first, botLeft.second)) {
		std::cout << " Enter x and y for bot left point ( 0 - 20 range): " << std::endl;
		std::cin >> botLeft.first >> botLeft.second;
	}
}

void Rectangle::setBotRight()
{
	botRight.first = -1;
	botRight.second = -1;
	while (!coordCheck(botRight.first, botRight.second)) {
		std::cout << " Enter x and y for bot right point ( 0 - 20 range): " << std::endl;
		std::cin >> botRight.first >> botRight.second;
	}
}

void Rectangle::setTopRight()
{
	topRight.first = -1;
	topRight.second = -1;
	while (!coordCheck(topRight.first, topRight.second)) {
		std::cout << " Enter x and y for top right point ( 0 - 20 range): " << std::endl;
		std::cin >> topRight.first >> topRight.second;
	}
}

void Rectangle::setTopLeft()
{
	topLeft.first = -1;
	topLeft.second = -1;
	while (!coordCheck(topLeft.first, topLeft.second)) {
		std::cout << " Enter x and y for top left point ( 0 - 20 range): " << std::endl;
		std::cin >> topLeft.first >> topLeft.second;
	}
}

bool Rectangle::coordCheck(const double x, const double y)
{
	return x >= 0 && x <= 20 && y >= 0 && y <= 20;
}

void Rectangle::calculateParams()
{
	d1 = pow(botRight.first - botLeft.first, 2) + pow(botRight.second - botLeft.second, 2);
	d1 = std::sqrt(d1);

	d2 = pow(topRight.first - botLeft.first, 2) + pow((topRight.second - botLeft.second), 2); // the middle one
	d2 = std::sqrt(d2);

	d3 = pow(topLeft.first - botLeft.first, 2) + pow(topLeft.second - botLeft.second, 2);
	d3 = std::sqrt(d3);



	//std::cout << d1 << " " << d2 << " " << d3 << std::endl;

	lenght = d1 < d3 ? d3 : d1;
	height = d1 < d3 ? d1 : d3;
	//std::cout << lenght << " " << height << std::endl;

	perim = 2 * (lenght + height);
	area = lenght * height;
}

bool Rectangle::rectangleCheck()
{


	return botLeft.first == topLeft.first && botRight.first == topRight.first;
}

bool Rectangle::squareCheck()
{
	return d1 == d3;
}

void Rectangle::printLenth()
{
	std::cout << " Lenght: " << lenght << std::endl;
}

void Rectangle::printHeight()
{
	std::cout << " Height: " << height << std::endl;
}

void Rectangle::printPerim()
{
	std::cout << " Perimeter: " << perim << std::endl;
}

void Rectangle::printArea()
{
	std::cout << " Area: " << area << std::endl;
}
