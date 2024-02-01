#pragma once
#include"Order.h"


class Customer
{
public:
	Customer(std::string);
	void printOrders();
	void printClientInfo();
	void addOrder(Order);
	void addOrder(std::string, std::string, double, double, unsigned, double);
	void setName(std::string);
	const std::string getName();
	std::vector<Order> getOrderList();

private:
	std::string name;
	std::vector<Order> orderList;
};

