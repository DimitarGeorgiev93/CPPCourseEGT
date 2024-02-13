//
// Created by Katya Daskalova on 1/19/24.
//

#ifndef UNTITLED1_BOOK_H
#define UNTITLED1_BOOK_H

#include <ostream>
#include "Auhor.h"

class Book {
public:
    //Book(string, int, string, Author);
    Book(string, int, string, Author*);
    static Book *parseBookNode(pugi::xml_node);
    static void createBookNode(pugi::xml_node&, Book);

    friend ostream &operator<<(ostream &os, const Book &book);

    string getTitle() const;
    int getYear() const;
    string getGenre() const;
    Author getAuthor() const;
    Author* getAuthorPtr();

    ~Book(); 
private:
    string title;
    int year;
    string genre;
    Author* author;
};

#endif //UNTITLED1_BOOK_H
