#pragma once
#include<iostream>
class Workstation
{
public:
	Workstation(int,int,int);
	void print() const;
	~Workstation();
private:
	int building;
	int floor;
	int desk;
};

