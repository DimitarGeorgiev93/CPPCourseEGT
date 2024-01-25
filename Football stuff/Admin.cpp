#include "Admin.h"

Admin::Admin(std::string name, std::string pass): User(name,pass)
{
}

void Admin::addTeam(Team* team)
{
	if (team != nullptr) {
		this->teams.push_back(team);
	}
}

void Admin::removeTeam(Team* team)
{
	if (team != nullptr) {
		for (int i = 0; i < this->teams.size(); i++) {
			if (team->getTeamName() == this->teams[i]->getTeamName()) {
				this->teams.erase(this->teams.begin()+i);
			}
		}
	}
}

void Admin::updateTeam(Team* team)
{
	if (team != nullptr) {
		for (int i = 0; i < this->teams.size(); i++) {
			if (team->getTeamName() == this->teams.at(i)->getTeamName()) {
				this->teams.at(i) = team;
			}
		}
	}
}

void Admin::printTeams()
{
	std::cout << "Current teams : \n";
	for (Team* team : teams) {
		std::cout << team->getTeamName() << std::endl;
	}
}

std::vector<Team*> Admin::getTeams()
{
	return this->teams;
}
