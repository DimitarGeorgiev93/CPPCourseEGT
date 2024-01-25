#pragma once
#include "User.h"
#include "Team.h"
#include <vector>

class Admin :
    public User
{
public:
    Admin(std::string, std::string);
    void addTeam(Team*);
    void removeTeam(Team*);
    void updateTeam(Team*);
    void printTeams();
    std::vector<Team*> getTeams();
private:
    std::vector<Team*> teams;
};

