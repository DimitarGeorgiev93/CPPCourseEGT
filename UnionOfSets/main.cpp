

#include <iostream>
#include "IntegerSet.h"

int main()
{
	IntegerSet s1;
	s1.insertElement(2);
	s1.insertElement(5);
	s1.insertElement(10);
	s1.insertElement(25);
	s1.printSet();
	std::cout << std::endl;

	IntegerSet s2;
	s2.insertElement(20);
	s2.insertElement(55);
	s2.insertElement(87);
	s2.insertElement(16);

	s2.printSet();
	std::cout << std::endl;
	s1.unionOfSets(&s2);
	s1.printSet();

	IntegerSet s3;
	s3.insertElement(10);
	s1.intersectionOfSets(&s3);

	s1.printSet();

	std::cout << s1.isEqual(&s2);

}

