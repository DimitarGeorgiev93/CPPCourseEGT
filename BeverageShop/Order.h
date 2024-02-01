#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Alcohol.h"
#include <iterator>
#include "NonAlcoholic.h"

class Order
{
public:
	Order(Beverage*, unsigned);
	void addToOrder(Beverage*, unsigned);
	void printOrderInfo();
	double getTotalPrice();
	std::vector<std::pair<Beverage*, unsigned>> getBeverageList();
private:
	static unsigned orderNumberTotal;
	const unsigned orderNumber;
	std::vector <std::pair<Beverage*, unsigned>> orderList;
};

