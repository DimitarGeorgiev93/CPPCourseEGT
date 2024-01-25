#pragma once
enum Month { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAI, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

class Date
{
public:
	Date(int,Month, int);
	Date();
	int getDay();
	int getYear();
	Month getMonth();
	void setDay(int);
	void setMonth(Month);
	void setYear(int);
	
private:
	int day;
	int year;
	Month month;
};

