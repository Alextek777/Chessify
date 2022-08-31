#ifndef PLAYER_H
#define PLAYER_H

#include "Definitions.h"

class Player
{
public:
    Team team;
    QVector<Figure*> figures;

public:
    Player(Team t);
};

#endif // PLAYER_H
