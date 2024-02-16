#pragma once
#include<string>
#include<iostream>


//base shape class
class Shape
{
public:
	Shape(std ::string);
	virtual void draw() const;
protected:
	std::string colour;
};

