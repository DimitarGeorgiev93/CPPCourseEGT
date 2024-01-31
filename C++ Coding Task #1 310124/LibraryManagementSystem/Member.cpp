#include "Member.h"

Member::Member(std::string name, int age, std::string memberID)
{
    setName(name);
    setAge(age);
    setMemberID(memberID);
    borrowedBook = nullptr;
}

std::string Member::getName() const
{
    return this->name;
}

std::string Member::getMemberID() const
{
    return this->memberID;
}

int Member::getID() const
{
    return this->age;
}

void Member::setName(std::string name)
{
    this->name = name;
}

void Member::setMemberID(std::string memberID)
{
    this->memberID = memberID;
}

void Member::setAge(int age)
{
    this->age = age;
}

void Member::display()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Member ID: " << this->memberID << std::endl;
    if (this->borrowedBook == nullptr) {
        std::cout << "Borrowed book: N/A " << std::endl;
    }
    else {
        std::cout << "Borrowed book: " << this->borrowedBook->getTitle() << std::endl;
    }
    std::cout << std::endl;
}

void Member::borrowBook(Book& book)
{
    if (this->borrowedBook == nullptr) {
        this->borrowedBook = &book;
        std::cout << "Member " << this->memberID << " is now borrowing " << this->borrowedBook->getTitle() << std::endl;
    }
    else {
        std::cout << this->memberID << " is already boorowng " << this->borrowedBook->getTitle()<< std::endl;
    }
    std::cout << std::endl;
}

void Member::returnBook()
{
    if (this->borrowedBook != nullptr) {
        std::cout << "Member " << this->memberID<<" returned " << this->borrowedBook->getTitle() << std::endl;
        this->borrowedBook = nullptr;
    }
    else {
        std::cout << this->memberID << " is not borrowing any book at this moment."<< std::endl;
    }
    std::cout << std::endl;
}
