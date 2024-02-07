#pragma once

#include <iostream>

#include"pugixml.h"
#include "Employee.h"
#include <vector>

std::vector<Employee*>* doItAll(const char* filename) {
    pugi::xml_document doc;

    if (!doc.load_file(filename)) {
        return nullptr;
    }
    pugi::xml_node empls = doc.child("EmployeesData").child("Employees");

    std::vector<Employee*>* employees = new std::vector<Employee*>;

    for (pugi::xml_node_iterator it = empls.begin(); it != empls.end(); it++) {

        pugi::xml_node workNode = it->child("Workstation");

        Workstation* tempWorkstation = new Workstation(workNode.attribute("Building").as_int(), workNode.attribute("Floor").as_int(), workNode.attribute("Desc").as_int());
        Employee* tempEmployee = new Employee(it->attribute("Name").as_string(), it->attribute("Type").as_string(), it->attribute("Age").as_int(), *tempWorkstation);

        employees->push_back(tempEmployee);

    }
    return employees;
}

void printAndDel(std::vector<Employee*>* employees) {
    for (Employee* empl : *employees) {
        empl->print();
    };
    /*for (Employee* empl : *employees) {

        delete empl;
        empl = nullptr;
    };*/
    //deleteDynamicStuff(employees);
}

void deleteDynamicStuff(std::vector<Employee*>* employees) {
    for (Employee* empl : *employees) {

        delete empl;
        empl = nullptr;
    };
}
