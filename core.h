#ifndef CORE_H
#define CORE_H

#include "player.h"

class Core
{
public:
    QVector<Player*> players;

    Team currentTeam;
    Figure* curFig = nullptr;
public:
    Core();
};

#endif // CORE_H
