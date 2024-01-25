#include "Human.h"

Human::Human(std::string name)
{
	this->name = name;
}

const std::string Human::getName()
{
	return this->name;
}

void Human::printInfo()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Name: " << this->name << std::endl;
}
