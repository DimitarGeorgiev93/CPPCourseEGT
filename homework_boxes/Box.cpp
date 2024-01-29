#include "Box.h"


Box::Box(unsigned x, unsigned y, unsigned z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


unsigned Box::getX() const
{
	return this->x;
}

unsigned Box::getY() const
{
	return this->y;
}

unsigned Box::getZ() const
{
	return this->z;
}

const Box& Box::operator=(const Box& box)
{
	if (*this != box) {
		this->setX(box.getX());
		this->setY(box.getY());
		this->setZ(box.getZ());
	}
	return *this;
}

const Box& Box::operator+(const Box& box)
{
	mergHelper(box);
	return *this;
}

bool Box::operator!=(const Box& box) const
{
	if (this->x == box.getX() && this->y == box.getY() && this->z == box.getZ()) return false;
	else return true;
}

void Box::printInfo() const
{
	std::cout << "X: " << this->x << " Y: " << this->y << " Z: " << this->z << std::endl;
}

void Box::setX(unsigned x)
{
	this->x = x;
}

void Box::setY(unsigned y)
{
	this->y = y;
}

void Box::setZ(unsigned z)
{
	this->z = z;
}

void Box::setDimensions(unsigned x, unsigned y, unsigned z)
{
	setX(x);
	setY(y);
	setZ(z);
}

void Box::mergHelper(const Box& box)
{
	if (this->x == box.getX() && this->y == box.getY()) {
		this->z += box.getZ();
	}
	else if (this->z == box.getZ() && this->y == box.getY()) {
		this->x += box.getX();

	}
	else if (this->x == box.getX() && this->z == box.getZ()) {
		this->y += box.getY();
	}
}
