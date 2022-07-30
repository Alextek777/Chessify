#include "core.h"

Core::Core()
{    
    players.push_back(new Player(Team::White));
    players.push_back(new Player(Team::Black));
    currentTeam = White;
}

