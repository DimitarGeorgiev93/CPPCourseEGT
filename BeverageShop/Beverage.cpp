#include "Beverage.h"

Beverage::Beverage(std::string name, std::string brand,double price, double volume)
: brand(brand){
	//this->brand = brand;
	this->name = name;
	this->price = price;
	this->volume = volume;
}

void Beverage::printInfo()
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Beverage name: " << this->name << std::endl;
	std::cout << "Brand: " << this->brand << std::endl;
	std::cout << "Price: " << this->price << std::endl;
	std::cout << "Volume: " << this->volume <<"L" << std::endl;
}

const std::string Beverage::getName()
{
	return this->name;
}

const double Beverage::getPrice()
{
	return this->price;
}

const std::string Beverage::getBrand()
{
	return this->brand;
}

const double Beverage::getVolume()
{
	return this->volume;
}

void Beverage::setPrice(const double& price)
{
	if(price > 0 && price != this->price) this->price = price;
}

const double Beverage::getTax()
{
	return this->tax;
}

void Beverage::setName(const std::string& name)
{
	if(name != "") this->name = name;
}

bool Beverage::operator==(Beverage const& b)
{
	return this->name == b.name && this->brand == b.brand && this->price == b.price && this->volume == volume;
}
