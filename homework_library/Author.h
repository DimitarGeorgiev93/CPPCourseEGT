#pragma once

#include<string>
#include<iostream>
class Author
{
public:

	Author(std::string, std::string, std::string);
	void print();
	const std::string getFirstName();
	const std::string getLastName();
	const std::string getNationality();
private:
	std::string authorFirstName;
	std::string authorLastName;
	std::string authorNationality;
};

