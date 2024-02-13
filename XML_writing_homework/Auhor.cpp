#include <string>
#include <iostream>
#include "Auhor.h"

using namespace std;
//
// Created by Katya Daskalova on 1/19/24.
//


Author *Author::parseAuthorNode(pugi::xml_node author) {
    // read attributes values from Author node
    string firstName = author.attribute("firstName").value();
    string lastName = author.attribute("lastName").value();
    string nationality = author.attribute("nationality").value();

    // create Author object
    return new Author(firstName, lastName, nationality);
}

void Author::createAuthorNode(pugi::xml_node &authorNode, Author author) {
    // add attributes to Author node
    authorNode.append_attribute("firstName") = author.getFirstName().data();
    authorNode.append_attribute("lastName") = author.getLastName().data();
    authorNode.append_attribute("nationality") = author.getNationality().data();
}

Author::Author(string firstName, string lastName, string nationality) : firstName(firstName), lastName(lastName),
                                                                     nationality(nationality) {}

string Author::getFirstName() const {
    return firstName;
}

string Author::getLastName() const {
    return lastName;
}

string Author::getNationality() const {
    return nationality;
}

Author::~Author()
{   
    std::cout << "deleting " << this->getFirstName() <<std::endl;
}



ostream &operator<<(ostream &os, const Author &author) {
    os << "firstName: " << author.firstName << " lastName: " << author.lastName << " nationality: "
       << author.nationality;
    return os;
}
