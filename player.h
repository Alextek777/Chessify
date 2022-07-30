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
    QVector<Move> getAvailableMoves(Figure *fig)const;
};

#endif // PLAYER_H
