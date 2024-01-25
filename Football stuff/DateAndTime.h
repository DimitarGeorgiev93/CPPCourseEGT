#pragma once
#include "Date.h"


class DateAndTime : public Date
{
public:
	DateAndTime();
	void setDate();
private:
	int hour;
	int min;
};

