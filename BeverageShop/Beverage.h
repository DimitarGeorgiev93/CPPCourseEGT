#pragma once
#include <string>
#include <iostream>
#include <iomanip>
class Beverage
{
public:
	Beverage(std::string, std::string, double, double );
	const std::string getName();
	const double getPrice();
	const std::string getBrand();
	const double getVolume();
	void setPrice(const double&);
	const double getTax();
	void setName(const std::string&);
	bool operator==(Beverage const& b);

	virtual double calculatePrice() = 0;
	virtual void printInfo();
private:
	std::string name;
	double price;
	const std::string brand;
	double volume;
	const double tax = 1.2;
};

