//
// Created by Katya Daskalova on 1/19/24.
//

#include <iostream>
#include "Book.h"

Book *Book::parseBookNode(pugi::xml_node book) {
    // read attributes values from Book node
    string title = book.attribute("title").value();
    int year = book.attribute("year").as_int();
    string genre = book.attribute("genre").value();

    // invoke Author::parseAuthor() to read Author node
    // the Author node data is used to create an Author object
    Author *author = Author::parseAuthorNode(book.child("Author"));

    // create Book object
    return new Book(title, year, genre, author);
}

void Book::createBookNode(pugi::xml_node &bookNode, Book book) {
    // add attributes to Book node
    bookNode.append_attribute("title") = book.getTitle().data();
    bookNode.append_attribute("year") = book.getYear();
    bookNode.append_attribute("genre") = book.getGenre().data();

    // append Author node as Book node child
    pugi::xml_node authorNode = bookNode.append_child("Author");

    // create Author node using Author object
    Author::createAuthorNode(authorNode, book.getAuthor());
}

//Book::Book(string title, int year, string genre, Author author) : title(title), year(year), genre(genre),
//                                                                       author(author) {}

Book::Book(string title, int year, string genre, Author* author) : title(title), year(year), genre(genre),
                                                                  author(author) {}

string Book::getTitle() const {
    return title;
}

int Book::getYear() const {
    return year;
}

string Book::getGenre() const {
    return genre;
}

Author Book::getAuthor() const {
    return *author;
}

Author* Book::getAuthorPtr()
{
    return author;
}


Book::~Book()
{
    std::cout << "deleting " << this->getTitle() << std::endl;
}

ostream &operator<<(ostream &os, const Book &book) {
    os << "title: " << book.title << " year: " << book.year << " genre: " << book.genre << " author: " << *book.author;
    return os;
}
