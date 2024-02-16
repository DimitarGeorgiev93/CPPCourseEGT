#pragma once
#include<string>
#include<iostream>


//base shape class with a pure virtual area() method
class Shape
{
public:
	Shape();
	virtual double area() const = 0;
protected:
};

