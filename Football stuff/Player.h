#pragma once
#include "Human.h"
//#include "Team.h"
//using forward declaration to remove circle of including,
//  and use including in .cpp files. Specifically, forward declaration means: (in Topics.h)

class Team;

class Player : public Human
{
public:
	Player(std::string, Team* team);
	virtual void printInfo();
	void receiveYellowCard();
	void receiveRedCard();
	void scoreGoal();
private:
	Team* team;
	bool yellowCard;
	bool redCard;
	unsigned goalsScored;
};

