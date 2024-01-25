#include "Date.h"

Date::Date(int day, Month month, int year)
{
	this->month = month;
	setDay(day);
	this->year = year;
}

Date::Date()
{
	this->year = 2024;
	this->day = 1;
	this->month = JANUARY;
}

int Date::getDay()
{
	return this->day;
}


int Date::getYear()
{
	return this->year;
}

Month Date::getMonth()
{
	return this->month;
}

void Date::setDay(int day)
{
	switch (this->month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31) this->day = 1;
		else this->day = day;
		break;
	case 2:
		if (day > 28) this->day = 1;
		else this->day = day;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30) this->day = 1;
		else this->day = day;
		break;
	}
}

void Date::setMonth(Month month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}
