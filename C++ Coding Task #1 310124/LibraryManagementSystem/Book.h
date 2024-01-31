#pragma once
#include<string>
#include<iostream>

class Book
{
public:
	Book(std::string, std::string, std::string);

	void setTitle(std::string);
	void setAuthor(std::string);
	void setISBN(std::string);

	std::string getTitle() const;
	std::string getAuthor() const;
	std::string getISBN() const;

	void display();

private:
	std::string title;
	std::string author;
	std::string ISBN;
};

