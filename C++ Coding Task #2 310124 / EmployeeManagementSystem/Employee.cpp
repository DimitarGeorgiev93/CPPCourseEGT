#include "Employee.h"

Employee::Employee(std::string name, std::string id, std::string position)
{
	setName(name);
	setID(id);
	setPosition(position);
}

void Employee::setName(std::string name)
{
	this->name = name;
}

void Employee::setID(std::string id)
{
	this->employeeID = id;
}

void Employee::setPosition(std::string position)
{
	this->position = position;
}

std::string Employee::getName() const
{
	return this->name;
}

std::string Employee::getID() const
{
	return this->employeeID;
}

std::string Employee::getPosition() const
{
	return this->position;
}

void Employee::display() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Employee ID: " << this->employeeID << std::endl;
	std::cout << "Position: " << this->position << std::endl;
	std::cout << std::endl;
}
