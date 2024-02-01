#include "Alcohol.h"

Alcohol::Alcohol(std::string name, std::string brand, double price, double volume, double alcoholVolume)
	:Beverage(name, brand, price, volume), alcoholVolume(alcoholVolume) {
	//this->alhocolVolume = alcoholVolume;
}

double Alcohol::calculatePrice()
{
	return Beverage::getPrice() * Beverage::getTax() *alcoholTax;
}

void Alcohol::printInfo()
{
	Beverage::printInfo();
	std::cout << "Alcohol volume: " << this->alcoholVolume << std::endl;
	std::cout  << std::fixed << std::setprecision(2) << "Price with taxes: " << this->calculatePrice()  << std::endl;
}
