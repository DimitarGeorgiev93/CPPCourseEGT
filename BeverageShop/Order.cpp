#include "Order.h"

unsigned Order::orderNumberTotal = 0;

Order::Order(Beverage* beverage, unsigned quantity):orderNumber(++orderNumberTotal)
{
	orderList.push_back({ beverage, quantity });
}

void Order::addToOrder(Beverage* beverage, unsigned quantity)
{
	orderList.push_back({ beverage, quantity });
}

void Order::printOrderInfo()
{
	std::vector < std::pair<Beverage*, unsigned>>::iterator ptr = orderList.begin();
	std::cout << std::endl << "Order number: " << this->orderNumber << std::endl;

	do {
		ptr->first->printInfo();
		std::cout << "Quantity: " << ptr->second << std::endl;
	} while (++ptr != orderList.end());
}

double Order::getTotalPrice()
{
	std::vector < std::pair<Beverage*, unsigned>>::iterator ptr = orderList.begin();
	double sum = 0;
	do {
		//std::cout << ptr->first->calculatePrice() * ptr->second << std::endl;
		sum += ptr->first->calculatePrice() * ptr->second;
	} while (++ptr != orderList.end());

	return sum;
}

std::vector<std::pair<Beverage*, unsigned>> Order::getBeverageList()
{
	return this->orderList;
}
