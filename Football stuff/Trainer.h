#pragma once
#include "Human.h"

class Team;

class Trainer :
    public Human
{
public:
    Trainer(std::string, Team*);
private:
    Team* team;
};

