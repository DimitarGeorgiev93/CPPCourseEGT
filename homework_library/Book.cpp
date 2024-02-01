#include "Book.h"
#include "Author.h"

bool Book::operator==(const Book& book) const noexcept
{
	// logic here
	return this->bookName == book.bookName; // for example
}

bool Book::operator<(const Book& book) const noexcept
{
	// logic here
	return this->bookName < book.bookName; // for example
}

bool Book::operator>(const Book& book) const noexcept
{
		return this->bookName > book.bookName;
}

Book::Book(Author* author, std::string bookName, Genre genre , unsigned publishYear)//:author(author)
{	
	this->bookName = bookName;
	this->author = author;
	this->genre = genre;
	this->publishYear = publishYear;
}

const std::string Book::getBookName()
{
	return this->bookName;
}


const std::string Book::getAuthorName()
{
	return this->author->getFirstName() + this->author->getLastName();
}

const Genre Book::getGenre()
{
	return this->genre;
}

const unsigned Book::getPublishYear()
{
	return this->publishYear;
}

void Book::print() {
	std::cout << "Book name: " << this->bookName << std::endl;
	std::cout << "Author:" <<  std::endl;
	author->print();
	std::cout << "Genre: ";
	switch (genre) {
	case 1:
		std::cout << "Classic" << std::endl;
		break;
	case 2:
		std::cout << "ForKids" << std::endl;
		break;
	case 3:
		std::cout << "Fantasy" << std::endl;
		break;
	case 4:
		std::cout << "Biography" << std::endl;
		break;
	case 5:
		std::cout << "Romance" << std::endl;
		break;
	case 6:
		std::cout << "Historical" << std::endl;
		break;
	}
	std::cout << "Publish year: " << this->publishYear << std::endl;
}