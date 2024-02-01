#pragma once
#include<string>
#include <iostream>
#include "Author.h"

enum Genre { Classic  = 1 , ForKids , Fantasy, Biography, Romance, Historical };

class Book
{

public:
	bool operator==(const Book& book) const noexcept;
	bool operator<(const Book& book) const noexcept;
	bool operator>(const Book& book) const noexcept;
	Book(Author*, std::string, Genre ,unsigned);
	const std::string getBookName();
	const std::string getAuthorName();
	const Genre getGenre();
	const unsigned getPublishYear();
	void print();

private:
	Author* author;
	std::string bookName;
	Genre genre;
	unsigned publishYear;
};

