#pragma once
#include<iostream>
class Shape
{
public:
	virtual double getArea() = 0;
	virtual void print();
	void drawLinesAbove();
	void drawLinesLeft();
	virtual void draw() = 0;
	const int getPositionFromCenter();
	Shape(int, int, char);
	int getX() const;
	const char getDrawingChar();
private:
	int x;
	char drawingChar;;
	int positionFromCenter;
};

