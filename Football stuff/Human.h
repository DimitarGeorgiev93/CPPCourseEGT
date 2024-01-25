#pragma once
#include<iostream>
#include<string>

class Human
{
public:
	Human(std::string);
	const std::string getName();
	virtual void printInfo();
private:
	std::string name;
};

