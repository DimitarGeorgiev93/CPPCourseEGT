

#include <iostream>

#include "Referee.h"
#include "Team.h"
#include "Match.h"
#include "Admin.h"

int main()
{
    Team team("Levski", "Sofia");
    Team team2("Botev Plovdiv", "Plovdiv");
    Team team3("Levski", "Vraca");
    Player player("Hristo Stoichkov", &team);
    Player player2("Ivan Tachev", &team);
    Player player3("Pencho Barmana", &team);
    Player player4("Pesho Imeto", &team);
    Player player5("Kiro slepia", &team);
    Player player6("Misho Shamara", &team);
    Referee ref("Barmana kiro");
    //player.printInfo();
    team.addPlayer(&player);
    team.addPlayer(&player2);
    team.addPlayer(&player3);
    team.addPlayer(&player4);
    team.addPlayer(&player5);
    team.addPlayer(&player6);


    team.printTeamInfo();
    team.removePlayer(&player5);
    team.printTeamInfo();
    ref.printInfo();

    Match match1(&team, &team2,&ref, "Tomorrow");
    Admin admin("Pesho", "kireto");
    match1.printMatchInfo();
    admin.addTeam(&team);
    admin.addTeam(&team2);
    match1.updateTeam1Score();
    match1.printMatchInfo();
   // admin.printTeams();
   // admin.removeTeam(&team2);
   // admin.updateTeam(&team3);
   // admin.printTeams();

    /*for (Team* t : admin.getTeams() ){
        t->printTeamInfo();
    }*/
}

