#pragma once

#include<iostream>

class Box
{


public:
	Box(unsigned x = 1, unsigned y = 1, unsigned z = 1); //default constructor values

	unsigned getX() const;
	unsigned getY() const;
	unsigned getZ() const;
	const Box& operator=(const Box&);
	const Box& operator+(const Box&);
	void printInfo() const;
	

	void setX(unsigned);
	void setY(unsigned);
	void setZ(unsigned);
	void setDimensions(unsigned, unsigned, unsigned);
private:
	void mergHelper(const Box&);
	unsigned x, y, z;
};

