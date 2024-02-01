#pragma once

class IntegerSet
{
public:
	IntegerSet();
	void unionOfSets(IntegerSet*);
	void intersectionOfSets( IntegerSet*);
	void insertElement(int);
	void deleteElement(int);
	void printSet();
	bool isEqual(IntegerSet*);
private:
	bool arr[100];
};

