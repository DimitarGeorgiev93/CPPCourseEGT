#pragma once

#include <vector>
#include <iostream>
#include "Match.h"

class MatchSchedule
{
public:
	MatchSchedule();
private:
	std::vector<Match*> schedule;
};

