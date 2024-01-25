#pragma once

#include "Team.h"
#include "Referee.h"

class Match
{
public:
	Match(Team*, Team*, Referee*, std::string);
	void printMatchInfo();
	void updateTeam1Score();
	void updateTeam2Score();
private:
	Team* team1;
	Team* team2;
	Referee* ref;
	std::pair<unsigned, unsigned> score;
	std::string date;
};

