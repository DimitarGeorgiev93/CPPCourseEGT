#include "IntegerSet.h"
#include <iostream>

IntegerSet::IntegerSet()
{
	for (int i = 0; i < 100; i++)
	{
		arr[i] = false;
		//std::cout << arr[i] << " ";
	}

}

void IntegerSet::unionOfSets( IntegerSet* set2)
{
	for (int i = 0; i < 100; i++) {
		if (this->arr[i] == true || set2->arr[i] == true)
			this->arr[i] = true;
	}
}

void IntegerSet::intersectionOfSets( IntegerSet* set2)
{
	for (int i = 0; i < 100; i++) {
		if (this->arr[i] == true && set2->arr[i] == true)
			this->arr[i] = true;
		else this->arr[i] = false;
	}
}

void IntegerSet::insertElement(int a)
{
	if (arr[a] == false) arr[a] = true;
}

void IntegerSet::deleteElement(int a)
{
	if (arr[a] == true) arr[a] = false;
}

void IntegerSet::printSet()
{
	for(bool var : this->arr)
	{
		std::cout << var << " ";
	}
	std::cout << std::endl;
}

bool IntegerSet::isEqual(IntegerSet* set2)
{
	for (int i = 0; i < 100; i++) {
		if (this->arr[i] != set2->arr[i])
			return false;
	}
	return true;
}
