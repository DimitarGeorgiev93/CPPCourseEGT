#include "Customer.h"

Customer::Customer(std::string name)
{
	setName(name);
}

void Customer::printOrders()
{
	std::vector<Order>::iterator ptr = orderList.begin();
	
	while (ptr != orderList.end()) {
		ptr->printOrderInfo();
		ptr++;
	}
}

void Customer::printClientInfo()
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Client name: " << this->name << std::endl;
	std::vector<Order>::iterator ptr = orderList.begin();

	while (ptr != orderList.end()) {
		ptr->printOrderInfo();
		std::cout << "-----------------------------" << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "Total cost: " << ptr->getTotalPrice() <<std::endl;
		ptr++;
	}
}

void Customer::addOrder(Order order)
{
	orderList.push_back(order);
}

void Customer::addOrder(std::string name, std::string brand, double price, double volume, unsigned quantity, double alcoholVolume = 0)
{
	Beverage* newBev;
	if (alcoholVolume == 0) {
		 newBev = new NonAlcoholic(name,brand,price,volume);
	}
	else newBev = new Alcohol(name,brand,price,volume, alcoholVolume);

	Order* newOrder = new Order(newBev, quantity);
}

void Customer::setName(std::string name)
{
	this->name = name;
}

const std::string Customer::getName()
{
	return this->name;
}

std::vector<Order> Customer::getOrderList()
{
	return this->orderList;
}
