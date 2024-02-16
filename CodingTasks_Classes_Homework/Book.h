#pragma once
#include<string>
#include<iostream>

//book class with 3 members ( title, author and number of pages ) and 1 method (  display )
class Book
{
public:
	Book(std::string, std::string, int);
	void display() const;
private:
	std::string title;
	std::string author;
	int pages;
};

