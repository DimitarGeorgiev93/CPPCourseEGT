#include "Author.h"

Author::Author(std::string firstName, std::string lastName, std::string nationality)
{
	this->authorFirstName = firstName;
	this->authorLastName = lastName;
	this->authorNationality = nationality;
}

void Author::print()
{
	std::cout << "First name: " << this->authorFirstName << std::endl;
	std::cout << "Last name: " << this->authorLastName << std::endl;
	std::cout << "Nationality: " << this->authorNationality << std::endl;
}

const std::string Author::getFirstName()
{
	return this->authorFirstName;
}

const std::string Author::getLastName()
{
	return this->authorLastName;
}

const std::string Author::getNationality()
{
	return this->authorNationality;
}
