#pragma once

#include "Player.h"
#include "Trainer.h"
#include <list>

class Team
{
public:
	Team(std::string, std::string);
	std::string getTeamName();
	void printTeamMembersInfo();
	void addPlayer(Player*);
	void addTrainer(Trainer*);
	void printTeamInfo();
	void removePlayer(Player*);
	void removeTrainer();
	int getPoints();
	void updatePoints(int);
private:
	std::string teamName;
	std::string homeTown;
	std::list<Player*> teamList;
	Trainer* trainer;
	int points;

};

