#pragma once
#include "Human.h"
class User :
    public Human
{
public:
    User(std::string, std::string);
    std::string getPassword();
    void setPassword(std::string);
private:
    std::string password;
};

