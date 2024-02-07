#pragma once

#include<string>
#include"Workstation.h"

class Employee {
public:
	Employee(std::string, std::string, int, Workstation&);
	//Employee(std::string, std::string);
	void print() const;
	~Employee();
	//void setName(std::string);
private:
	Workstation* workstation;
	std::string name;
	std::string type;
	int age;

};