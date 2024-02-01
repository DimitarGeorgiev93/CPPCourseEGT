#include "Car.h"

Car::Car(Brand brand, std::string model, Type type, Colour colour, std::string id, std::string regPlate, double gas, double tax)
	:brand(brand), model(model), id(id), regPlate(regPlate), gas(gas), type(type), tax(tax)
{
	this->colour = colour;
	traveledDistance = 0;
}

const std::string Car::getModel()
{
	return this->model;
}

const Brand Car::getBrand() const
{
	return this->brand;
}

const Type Car::getType() const
{
	return this->type;
}

void Car::setColour(Colour colour) const
{	
	this->colour = colour;
}

const double Car::getTax() const
{
	return this->tax;
}

void Car::print()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Brand " << this->brand << std::endl;
	std::cout << "Model " << this->model << std::endl;
	std::cout << "Type " << this->type << std::endl;
	std::cout << "Colour " << this->colour << std::endl;
	std::cout << "ID " << this->id << std::endl;
	std::cout << "Reg. plate  " << this->regPlate << std::endl;
	std::cout << "Gas usage  " << this->gas << std::endl;
	std::cout << "Tax " << this->tax << std::endl;

}

const double Car::getGas() const
{
	return this->gas;
}

const std::string Car::getRegPlate()
{
	return this->regPlate;
}

const std::string Car::getID()
{
	return this->id;
}
