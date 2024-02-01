#pragma once

#include<iostream>
#include<string>

enum Brand {Opel, BMW, Mazda, Shkoda, Kia, Audi, VW, Dacia};
//std::string carBrands[] = {"Opel", "BMW", "Mazda", "Shkoda", "Kia", "Audi", "VW", "Dacia"};
enum Colour {RED, BLACK, WHITE, GREY, GREEN, YELLOW, ORANGE, BLUE};
enum Type {COMBI, HATCHBACK, SEDAN };

class Car
{
public:
	Car(Brand, std::string, Type,  Colour, std::string , std::string, double, double);
	const std::string getModel();
	const double getGas() const;
	const std::string getRegPlate();
	const std::string getID();
	const Brand getBrand() const;
	const Type getType() const;
	void setColour(Colour) const;
	const double getTax() const;
	virtual void print();
	void calculateCost();
private:
	const Brand brand;
	const std::string model;
	const Type type;
	Colour colour;
	const std::string id;
	const std::string regPlate;
	const double gas;
	double traveledDistance;
	const double tax;
};

