#ifndef PLAYER_H
#define PLAYER_H

#include "Definitions.h"

class Player
{
public:
    Player(Team t);

    Team team;
    QVector<Figure*> figures;
    QVector<Figure*> killedFigures;
    
    bool kill(const Move* curCell);
    Figure* findFigure(const Move* curCell);
};

#endif // PLAYER_H
