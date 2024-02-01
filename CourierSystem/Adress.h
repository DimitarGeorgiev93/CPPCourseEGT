#pragma once

#include <string>
#include <iostream>

class Adress
{
public:
	Adress(std::string, std::string, std::string, std::string);
	void print();
	const std::string getName();
	const std::string getPN();
	const std::string getCity();
	const std::string getAdress();
private:
	std::string name;
	std::string PN;
	std::string city;
	std::string adress;

};

