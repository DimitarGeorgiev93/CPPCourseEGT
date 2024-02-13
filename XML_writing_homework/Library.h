//
// Created by Katya Daskalova on 1/19/24.
//

#ifndef UNTITLED1_LIBRARY_H
#define UNTITLED1_LIBRARY_H
#include  <vector>
#include <ostream>
#include "Book.h"

class Library {
public:
    static void deserializeLibraryData();
    static void serializeLibraryData();

    static bool getDocumentFromXML(const char *);
    static bool saveDocumentToXML(const char *);

    static void clearBookList();

    static void deleteDynamicMembers();

    static const std::vector<Book*> getBooksList();
    static void addBookToNewBookList(Book*);

    static void generateLibraryData();
private:
    // ToDo: Try to use only one vector and doc for both tasks (serializing and deserializing).
    //  Don't forget to empty the vector and doc when switching between tasks
    static std::vector<Book*> booksList;  // when reading books from XML
    //static std::vector<Book> newBooksList;  // when saving books in XML
    static pugi::xml_document doc;  // when reading from XML
    //static pugi::xml_document newDoc;  // when saving in XML
};

#endif //UNTITLED1_LIBRARY_H
