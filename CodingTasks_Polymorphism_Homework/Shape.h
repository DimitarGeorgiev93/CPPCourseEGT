#pragma once
#include<string>
#include<iostream>


//base shape class with a pure virtual area() method
class Shape
{
public:
	Shape(std ::string);
	virtual double area() const = 0;
	virtual void draw() const;
	virtual ~Shape();
protected:
	std::string colour;
};

