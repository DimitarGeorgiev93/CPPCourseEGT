#pragma once
#include "Book.h"
#include<map>

class Library
{
public:
	Library();
	Library(std::map<Book,int>&);
	void addBook(Book&);
	void lookByName(std::string);
	void lookByWord(std::string);
	void print();
private:
	std::map<Book, int> bookList;
};

