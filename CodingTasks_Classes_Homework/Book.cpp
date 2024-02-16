#include "Book.h"


// constructor
Book::Book(std::string title, std::string author, int pages) : title(title), author(author), pages( pages)
{
}

//display function
void Book::display() const
{
	std::cout << "Title: " << this->title << " Author: " << this->author << " Pages: " << this->pages << std::endl;
}
