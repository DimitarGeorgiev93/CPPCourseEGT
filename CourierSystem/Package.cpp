#include "Package.h"




Package::Package(Adress sender, Adress receiver, double weight, double basePrice) :
	 sender(sender), receiver(receiver)
{	
	this->weigth = weight;
	this->basePrice = basePrice;
	this->sender = sender;
	this->receiver = receiver;
}

const std::string Package::getSenderName()
{
	return this->sender.getName();
}

const std::string Package::getSenderPN()
{
	return this->sender.getPN();
}

const std::string Package::getSenderAdress()
{
	return this->sender.getAdress();
}

const std::string Package::getReceiverName()
{
	return this->receiver.getAdress();
}

const std::string Package::getReceiverPN()
{
	return this->receiver.getPN();
}

const std::string Package::getReceiverAdress()
{
	return this->receiver.getAdress();
}

void Package::print()
{
	std::cout << "Sender: " << std::endl;
	this->sender.print();
	std::cout << "Receiver: " << std::endl;
	this->receiver.print();
	calculateCost();
}

void Package::calculateCost()
{
	std::cout << "Total cost: " << weigth * basePrice << std::endl;
	
}

const double Package::getWeight()
{
	return this->weigth;
}

const double Package::getBasePrice()
{
	return this->basePrice;
}
