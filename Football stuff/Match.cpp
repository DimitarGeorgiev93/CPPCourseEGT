#include "Match.h"

Match::Match(Team* team1, Team* team2, Referee* ref, std::string date)
{
	this->team1 = team1;
	this->team2 = team2;
	this->ref = ref;
	this->date = date;
	score.first = 0;
	score.second = 0;
}

void Match::printMatchInfo()
{
	std::cout << "-------------------------" << std::endl;
	std::cout << team1->getTeamName() << " vs " << team2->getTeamName() << std::endl;
	std::cout << score.first << " : " << score.second << std::endl;
	std::cout << "Referee: " << ref->getName() << std::endl;
	std::cout << "Date: " << this->date << std::endl;
}

void Match::updateTeam1Score()
{
	score.first++;
}

void Match::updateTeam2Score()
{
	score.second++;
}


