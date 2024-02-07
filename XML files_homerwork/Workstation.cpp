#include "Workstation.h"

Workstation::Workstation(int building, int floor, int desk)
{
	this->building = building;
	this->floor = floor;
	this->desk = desk;
}

void Workstation::print() const
{
	std::cout << " Building: " << this->building << " Floor: " << this->floor << " Desk: " << this->desk << std::endl;
}

Workstation::~Workstation()
{
	std::cout << "deleting workstation" << std::endl;
}
