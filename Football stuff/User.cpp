#include "User.h"

User::User(std::string name, std::string password): Human(name)
{
	this->password = password;
}

std::string User::getPassword()
{
	return this->password;
}

void User::setPassword(std::string password)
{
	this->password = password;
}
