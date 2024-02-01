#include "Adress.h"


Adress::Adress(std::string name, std::string PN, std::string city,std::string adress)
{
	this->name = name;
	this->PN = PN;
	this->city = city;
	this->adress = adress;
}

void Adress::print()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Phone number: " << PN << std::endl;
	std::cout << "City: " << city << std::endl;
	std::cout << "Adress: " << adress << std::endl;
}

const std::string Adress::getName()
{
	return this->name;
}

const std::string Adress::getPN()
{
	return this->PN;
}

const std::string Adress::getCity()
{
	return this->city;
}

const std::string Adress::getAdress()
{
	return this->adress;
}
