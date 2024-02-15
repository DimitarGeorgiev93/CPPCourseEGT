#pragma once
#include <string>
#include<vector>
#include"Employee.h"

class Department
{
public:
	Department(std::string);

	void addEmplyee(Employee*);

	void displayEmployees() const;

	void setDepartmentName(std::string);

	~Department();
private:
	std::string departmentName;
	std::vector<Employee*> employeeList;
	int numEmployees;
	
};

