#pragma once

#include <string>
#include "Adress.h"
class Package
{
public:

	Package(Adress, Adress, double, double);
	
	const std::string getSenderName();
	const std::string getSenderPN();
	const std::string getSenderAdress();
	const std::string getReceiverName();
	const std::string getReceiverPN();
	const std::string getReceiverAdress();
	virtual void print();
	virtual void calculateCost();
	const double getWeight();
	const double getBasePrice();

private:
	Adress sender;
	Adress receiver;
	double weigth;
	double basePrice;
};

