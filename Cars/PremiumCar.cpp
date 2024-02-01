#include "PremiumCar.h"

PremiumCar::PremiumCar(PremTax premimumTax, Brand brand, std::string model, Type type, Colour colour, std::string id, std::string regPlate, double gas, double tax)
	: Car(brand, model, type, colour, id, regPlate, gas, tax), premiumTax(premimumTax)
{	
}

const PremTax PremiumCar::getPremiumTax()
{
	return this->premiumTax;
}

void PremiumCar::print()
{
	Car::print();
	std::cout << "Luxury tax: " << this->premiumTax << std::endl;
}
