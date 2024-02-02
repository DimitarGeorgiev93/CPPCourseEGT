#include "ExpressPackage.h"

ExpressPackage::ExpressPackage(Adress sender, Adress receiver, double weight, double basePrice, double extraCost) 
	:Package(sender,receiver,weight,basePrice)
{
	this->extraCost = extraCost;
}

void ExpressPackage::calculateCost()
{
	std::cout << "Total cost: " << Package::getWeight() * Package::getBasePrice() * extraCost << std::endl;
}

void ExpressPackage::print()
{
	std::cout << "Express Package " << std::endl;
	Package::print();
}

