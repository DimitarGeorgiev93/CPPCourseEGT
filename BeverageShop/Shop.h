#pragma once
#include "Alcohol.h"
#include "NonAlcoholic.h"
#include <map>
#include<iterator>
#include "Order.h"
#include "Customer.h"
#include <set>


class Shop
{
public:
	Shop(std ::string);
	void printInfo();
	void addBeverage(Beverage* , unsigned);
	void sellBeverage(Beverage*, unsigned);
	void setShopName(std::string);
	const std::string getShopName();
	void printSoldBeverages();
	void printClientList();
	Customer* getBestCustomer();
	void addCustomer(Customer*);
	void getCustomersByDrink(Beverage&);
private:
	std::string shopName;
	std::map<Beverage*, unsigned> beverageList;
	std::set<Customer*> customerList;
	std::map<Beverage*, unsigned> soldList;
	//std::set<std::pair<Beverage, unsigned>> foodList;
};

