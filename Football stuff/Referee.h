#pragma once
#include "Player.h"

class Referee :
    public Human
{
public:
    Referee(std::string);
    void giveYellowCardToPlayer(Player*);
    void giveRedCardToPlayer(Player*);
    void callFoul();
    virtual void printInfo();
private:

};

