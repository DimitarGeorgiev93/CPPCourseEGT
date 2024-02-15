#include "Department.h"

Department::Department(std::string name)
{
	setDepartmentName(name);
	this->numEmployees = 0;
}

void Department::addEmplyee(Employee* employee)
{
	if (employee != nullptr) {
		employeeList.push_back(employee);
		numEmployees++;
	}
}

void Department::displayEmployees() const
{
	std::cout << "Currently the deparment has " << this->numEmployees <<" employees" << std::endl;
	std::cout << std::endl;
	for (Employee* employee : employeeList) {
		employee->display();
	}
}

void Department::setDepartmentName(std::string name)
{
	this->departmentName = name;
}

Department::~Department()
{
	for (Employee* employee : employeeList) {
		delete employee;
		employee = nullptr;
	}
}
