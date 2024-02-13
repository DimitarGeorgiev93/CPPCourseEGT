#include <iostream>
#include <fstream>
#include "json.h"
#include "Library.h"

using namespace std;
using json = nlohmann::json;

void parseJson() {
    std::ifstream file("library.json");

    json Doc = json::parse(file);

    auto books = Doc["Books"];
    for (const auto & book : books) {
//        cout << book << endl;
        string title = book["title"];
        int year = book["year"];
        string genre = book["genre"];
//        cout << title << endl;
//        cout << year << endl;
//        cout << genre << endl;
        auto author = book["Author"];
//        cout << author << endl;
        string firstName = author["firstName"];
        string lastName = author["lastName"];
        string nationality = author["nationality"];
//        cout << firstName << endl;
//        cout << lastName << endl;
//        cout << nationality << endl;
    }
}

int main() {
//    parseJson();

    cout << "\nDeserializing library data (load_file_input.xml).....Started\n\n";
    Library::getDocumentFromXML("load_file_input.xml");
    Library::deserializeLibraryData();
    for (const auto b: Library::getBooksList()) {
        cout << *b << endl;
    }
    cout << "\nDeserializing library data (load_file_input.xml).....Done\n\n";
    Library::clearBookList();
    cout << "\nSerializing library data (save_file_output.xml)...... Started\n";
    Library::generateLibraryData();
    Library::serializeLibraryData();
    for (const auto b : Library::getBooksList()) {
        cout << *b << endl;
    }
    Library::saveDocumentToXML("load_file_input.xml");
    cout << "\nSerializing library data (save_file_output.xml)...... Done\n\n";
    Library::deleteDynamicMembers();

    return 0;
}

// original contents in load_file_input.xml
//< ? xml version = "1.0" encoding = "utf-8" standalone = "no" ? >
//<LibraryData FormatVersion = "1">
//<Books>
//<Book title = "Harry Potter" year = "2001" genre = "Fantasy">
//<Author firstName = "Joanne" lastName = "Rowling" nationality = "UK" / >
//< / Book>
//<Book title = "Small Gods" year = "1992" genre = "Fantasy">
//<Author firstName = "Terry" lastName = "Pratchett" nationality = "UK" / >
//< / Book>
//<Book title = "It" year = "1986" genre = "Horror">
//<Author firstName = "Stephen" lastName = "King" nationality = "USA" / >
//< / Book>
//< / Books>
//< / LibraryData>
