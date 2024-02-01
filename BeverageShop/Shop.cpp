#include "Shop.h"


Shop::Shop(std::string shopName)
{
	this->shopName = shopName;
}

void Shop::addBeverage(Beverage* beverage, unsigned quantity)
{
	if (beverageList.find(beverage) != beverageList.end()) {
		beverageList.find(beverage)->second += quantity;
	}
	beverageList.insert({ beverage,quantity });
}

void Shop::sellBeverage(Beverage* beverage, unsigned quantity)
{
	if (beverageList.find(beverage) != beverageList.end() && beverageList.find(beverage)->second >= quantity) {
		beverageList.find(beverage)->second -= quantity;
		//std::cout << "asdasd" << std::endl;
		if (soldList.find(beverage) != soldList.end()) {
			soldList.find(beverage)->second += quantity;
		}
		else soldList.insert({ beverage,quantity });

	}
	else std::cout << "Not enough quanity, current quantity: " << beverageList.find(beverage)->second << std::endl;
}

void Shop::setShopName(std::string shopName)
{
	if (shopName != "") this->shopName = shopName;
}

void Shop::printInfo()
{
	std::cout << " -------------------------" << std::endl;
	std::cout << "Shop name: " << this->shopName << std::endl;

	std::map<Beverage*, unsigned>::iterator ptr = beverageList.begin();
	while (ptr != beverageList.end()) {
		ptr->first->printInfo();
		std::cout << "Quantity in stock: " << ptr->second << std::endl;
		ptr++;
	}
}

const std::string Shop::getShopName()
{
	return this->shopName;
}

void Shop::printSoldBeverages()
{
	std::map<Beverage*, unsigned>::iterator ptr = soldList.begin();
	while (ptr != soldList.end()) {
		std::cout <<"Product name: " << ptr->first->getBrand() << std::endl;
		std::cout <<"Quantity sold: "<<  ptr->second << std::endl;
		ptr++;
	}
}

void Shop::printClientList()
{
	for (Customer* customer : customerList) {
		std::cout << "-----------------------------" << std::endl;
		std::cout << customer->getName() << std::endl;
		std::cout << "Numbers of orders: " << customer->getOrderList().size() << std::endl;
	}
}

Customer* Shop::getBestCustomer()
{
	Customer* bestCust = nullptr;
	double max = 0;
	for (Customer* customer : customerList) {
		for (Order order : customer->getOrderList()) {
			if (max < order.getTotalPrice()) {
				max = order.getTotalPrice();
				bestCust = customer;
			}
		}
	}
	std::cout << "Best client: \n";
	return bestCust;
}


void Shop::addCustomer(Customer* customer)
{	
	this->customerList.insert(customer);
	//customer->printClientInfo();
	//std::vector<Order>::iterator ptr = this->customerList.find(customer)->getOrderList().begin();
	//std::vector<Order>::iterator ptr = (customer->getOrderList()).begin();
	for ( Order o: customer->getOrderList()) {
		for (std::pair< Beverage*, unsigned> bev : o.getBeverageList()) {
			sellBeverage(bev.first, bev.second);
		}
	}
	
	//while (ptr != customer->getOrderList().end()) {
	//	std::vector <std::pair<Beverage*, unsigned>>::iterator ptr2 = ptr->getBeverageList().begin();
	//	//sellBeverage(ptr->g);
	//	while (ptr2 != ptr->getBeverageList().end()) {
	//		sellBeverage(ptr2->first, ptr2->second);
	//	}
	//}
}

void Shop::getCustomersByDrink(Beverage& beverage) {

	std::cout << "Customers who bought " << beverage.getName() << ":" << std::endl;
	bool alreadyBought = false;
	for (Customer* customer : customerList) {
		for (Order order : customer->getOrderList()) {
			for (std::pair<Beverage*, unsigned> orderBeverage : order.getBeverageList()) {
				if (beverage == *orderBeverage.first && alreadyBought == false) {
					std::cout << "Name " << customer->getName() << std::endl;
					alreadyBought = true;
				}
			}
		}
		alreadyBought = false;
	}
}

