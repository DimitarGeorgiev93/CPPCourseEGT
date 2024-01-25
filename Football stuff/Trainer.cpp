#include "Trainer.h"
#include "Team.h"

Trainer::Trainer(std::string name, Team* team): Human(name)
{
	this->team = team;
}
