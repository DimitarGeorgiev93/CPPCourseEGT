//
// Created by Katya Daskalova on 1/19/24.
//

#ifndef UNTITLED1_AUHOR_H
#define UNTITLED1_AUHOR_H
#include <string>
#include <ostream>
#include "pugixml.h"

using namespace std;

class Author {
public:
    Author(string, string, string);
    static Author *parseAuthorNode(pugi::xml_node);
    static void createAuthorNode(pugi::xml_node&, Author);

    friend ostream &operator<<(ostream &os, const Author &author);

    string getFirstName() const;
    string getLastName() const;
    string getNationality() const;

    ~Author();
private:
    string firstName;
    string lastName;
    string nationality;
};

#endif //UNTITLED1_AUHOR_H
