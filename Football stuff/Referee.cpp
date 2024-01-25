#include "Referee.h"

Referee::Referee(std::string name):Human(name)
{
}

void Referee::giveYellowCardToPlayer(Player* player)
{
	if (player!=nullptr) {
		player->receiveYellowCard();
	}
}

void Referee::giveRedCardToPlayer(Player* player)
{
	if (player != nullptr) {
		player->receiveRedCard();
	}
}

void Referee::printInfo()
{	
	Human::printInfo();
	std::cout << "Position: Referee" << std::endl;
}
