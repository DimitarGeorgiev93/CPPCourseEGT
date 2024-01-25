#include "Team.h"

Team::Team(std::string teamName, std::string homeTown): points(0)
{
	this->teamName = teamName;
	this->homeTown = homeTown;
	this->trainer = nullptr;
}

std::string Team::getTeamName()
{
	return this->teamName;
}

void Team::printTeamMembersInfo()
{
	if (trainer != nullptr) {
		std::cout << "Trainer: " << trainer->getName() << std::endl;
	} else std::cout << "Trainer: no trainer yet" << std::endl;
	for (Player* player : teamList) {
		player->printInfo();
	}
}

void Team::addPlayer(Player* player)
{
	if (player != nullptr) {
		teamList.push_back(player);
		//std::cout << "Player added" << std::endl;
	}
}

void Team::addTrainer(Trainer* trainer)
{
	if (trainer != nullptr) {
		this->trainer = trainer;
	}
}

void Team::printTeamInfo()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Team name: " << this->teamName << std::endl;
	std::cout << "Home towm: " << this->homeTown<< std::endl;
	std::cout << "----------------------" << std::endl;
	printTeamMembersInfo();
}

void Team::removePlayer(Player* toBeRemoved)
{	
	if (toBeRemoved != nullptr  ) {
		for (Player* player : this->teamList) {
			if (player->getName() == toBeRemoved->getName())
			{
				teamList.remove(player);
				player = nullptr;
				return;
			}
		}
	}
}

void Team::removeTrainer()
{
	trainer == nullptr;
}

int Team::getPoints()
{
	return this->points;
}

void Team::updatePoints(int points)
{
	this->points += points;
}
