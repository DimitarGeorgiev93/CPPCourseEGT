//
// Created by Katya Daskalova on 1/19/24.
//
#include <iostream>
#include "Library.h"

std::vector<Book*> Library::booksList;
//std::vector<Book> Library::newBooksList;
pugi::xml_document Library::doc;
//pugi::xml_document Library::newDoc;

bool Library::getDocumentFromXML(const char *fileName) {
    if (!doc.load_file(fileName)) return -1;
//    doc.print(cout);
}

void Library::deserializeLibraryData() {
    pugi::xml_node booksNode = doc.child("LibraryData").child("Books");
    for (pugi::xml_node bookNode = booksNode.child("Book"); bookNode; bookNode = bookNode.next_sibling("Book"))
    {
        // invoke Book::parseBook() to read Book node
        // the Book node data is used to create a Book object
        Book *book = Book::parseBookNode(bookNode);

        // The book object is added to the booksList
        Library::booksList.push_back(book);
    }
}

void Library::serializeLibraryData() {
    // add LibraryData node as doc child
    pugi::xml_node libraryDataNode = doc.append_child("LibraryData");

    // add Books node as LibraryData node child
    pugi::xml_node booksNode = libraryDataNode.append_child("Books");

    booksNode.set_name("Books");
    for (Book* book: Library::booksList) {
        // append Book node as Books node child
        pugi::xml_node bookNode = booksNode.append_child("Book");

        // create Book node using Book object
        Book::createBookNode(bookNode, *book);
    }
//    newDoc.print(cout);
}

void Library::addBookToNewBookList(Book* b){
    Library::booksList.push_back(b);
}

bool Library::saveDocumentToXML(const char *file) {
    if (!doc.save_file(file)) return -1;
}

void Library::clearBookList()
{
    doc.reset();
    booksList.clear();
}

void Library::deleteDynamicMembers()
{
    /*for (Book* book : booksList) {
        delete book;
        book = nullptr;
    }*/
    for (int i = 0; i < booksList.size(); i++) {
        Book* temp = booksList.at(i);
        Author* temp2 = temp->getAuthorPtr();
        booksList.at(i) = nullptr;
        delete temp;
        delete temp2;
    }


}

const std::vector<Book*> Library::getBooksList() {
    return booksList;
}

void Library::generateLibraryData() {
  /*  Author a1 ("John", "Grisham", "USA");
    Book b1("The Firm", 1991, "Thriller", a1);

    Author a2("Pablo", "Neruda", "Chile");
    Book b2("Book of Twilight", 2018, "Poems", a2);

    Author a3("Michael", "Crichton", "USA");
    Book b3("Jurassic Park", 1990, "SciFi", a3);

    Library::addBookToNewBookList(&b1);
    Library::addBookToNewBookList(&b2);
    Library::addBookToNewBookList(&b3);*/
    Library::addBookToNewBookList(new Book("The Firm", 1991, "Thriller", new Author("John", "Grisham", "USA")));
    Library::addBookToNewBookList(new Book("Book of Twilight", 2018, "Poems", new Author("Pablo", "Neruda", "Chile")));
    Library::addBookToNewBookList(new Book("Jurassic Park", 1990, "SciFi", new Author ("Michael", "Crichton", "USA")));

}