#pragma once
#include "Book.h"

class Member
{
public:
	Member(std::string,int, std::string);

	std::string getName() const;
	std::string getMemberID() const;
	int getID() const;

	void setName(std::string);
	void setMemberID(std::string);
	void setAge(int);

	void display();
	void borrowBook(Book&);
	void returnBook();
private:
	std::string name;
	int age;
	std::string memberID;
	Book* borrowedBook;
};

