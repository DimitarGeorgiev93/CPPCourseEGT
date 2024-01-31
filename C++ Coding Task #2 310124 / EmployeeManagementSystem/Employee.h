#pragma once
#include<iostream>
#include<string>

class Employee
{
public:
	Employee(std::string, std::string, std::string);

	void setName(std::string);
	void setID(std::string);
	void setPosition(std::string);

	std::string getName() const;
	std::string getID() const;
	std::string getPosition() const;

	void display() const;
private:
	std::string name;
	std::string employeeID;
	std::string position;
};
 
