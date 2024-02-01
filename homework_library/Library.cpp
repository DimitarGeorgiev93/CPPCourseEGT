#include "Library.h"

Library::Library()
{
}

Library::Library(std::map<Book, int>& bookList)
{	
	this->bookList = bookList;
}

void Library::addBook(Book& book)
{
	if (this->bookList.find(book) == this->bookList.end()) {
		this->bookList.insert({ book,1 });
	}
	else this->bookList.find(book)->second++;
}

void Library::lookByName(std::string bookName)
{
	std::map<Book, int>::iterator iter = bookList.begin();
	while (iter != bookList.end())
	{
		Book temp = iter->first;
		if (temp.getBookName() == bookName) {
			std::cout << " -----------------------------------------------\n";
			std::cout << "Book found:..\n";
			temp.print();
			std::cout << "Quantity: " << iter->second << std::endl;
			std::cout << " -----------------------------------------------\n";
			//return true;
		}

		iter++;
	}
	//return false;
}

void Library::lookByWord(std::string word)
{
	std::map<Book, int>::iterator iter = bookList.begin();
	while (iter != bookList.end())
	{
		Book temp = iter->first;
		if (temp.getBookName().find(word) != std::string::npos) {
			std::cout << " -----------------------------------------------\n";
			std::cout << "Book found:..\n";
			temp.print();
			std::cout << "Quantity: " << iter->second << std::endl;
			std::cout << " -----------------------------------------------\n";
			//return true;
		}
		iter++;
	}
	
	//return false;
}



void Library::print()
{
	std::map<Book, int>::iterator iter = bookList.begin();
	while (iter != bookList.end())
	{	
		std::cout << " -----------------------------------------------\n";
		Book temp = iter->first;
		//iter->first.print();
		temp.print();
		std::cout <<"Quantity: " << iter->second << std::endl;
		iter++;
		std::cout << " -----------------------------------------------\n";
	}
}
