#include "Player.h"
#include "Team.h"

Player::Player( std::string name, Team* team) : Human(name)
{
	this->team = team;
	this->yellowCard = false;
	this->redCard = false;
	this->goalsScored = 0;
}

void Player::printInfo()
{
	Human::printInfo();
	std::cout << "Plays in: " << this->team->getTeamName() << std::endl;
	std::cout << "Goals scored: " << this->goalsScored << std::endl;
}

void Player::receiveYellowCard()
{
	if (this->yellowCard == true) {
		this->receiveRedCard();
	}
	else {
		this->yellowCard = true;
	}
}

void Player::receiveRedCard()
{
	this->redCard = true;
}

void Player::scoreGoal()
{
	this->goalsScored++;
}
