#include "NonAlcoholic.h"

NonAlcoholic::NonAlcoholic(std::string name, std::string brand, double price, double volume)
: Beverage(name, brand, price, volume) {
}

double NonAlcoholic::calculatePrice()
{
	return Beverage::getPrice() * Beverage::getTax();
}

void NonAlcoholic::printInfo()
{
	Beverage::printInfo();
	std::cout << std::fixed << std::setprecision(2) << "Price with taxes: " << this->calculatePrice() << std::endl;
}
