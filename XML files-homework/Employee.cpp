#pragma once

#include "Employee.h"

Employee::Employee(std::string name, std::string type, int age, Workstation& workstation )
{
	this->name = name;
	this->type = type;
	this->age = age;
	this->workstation = &workstation;
}



void Employee::print() const
{
	std::cout << "Name: " << this->name << " Type: " << this->type << " age: " << this->age;
	if (workstation != nullptr) this->workstation->print();
	else std::cout<< std::endl;
}

Employee::~Employee()
{
	std::cout << "deleting employee" << std::endl;
	delete this->workstation;
	this->workstation = nullptr;
}
