#include "Book.h"

Book::Book(std::string title , std::string author, std::string ISBN)
{
	setTitle(title);
	setAuthor(author);
	setISBN(ISBN);
}

void Book::setTitle(std::string title)
{
	this->title = title;
}

void Book::setAuthor(std::string author)
{
	this->author = author;
}

void Book::setISBN(std::string ISBN)
{
	this->ISBN = ISBN;
}

std::string Book::getTitle() const
{
	return this->title;
}

std::string Book::getAuthor() const
{
	return this->author;
}

std::string Book::getISBN() const
{
	return this->ISBN;
}

void Book::display()
{
	std::cout << "Book title: " << this->title << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "ISBN: " << this->ISBN << std::endl;
	std::cout << std::endl;
}
