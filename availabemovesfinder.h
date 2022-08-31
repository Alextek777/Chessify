#ifndef AVAILABEMOVESFINDER_H
#define AVAILABEMOVESFINDER_H
#include "Definitions.h"
#include "player.h"

class AvailabeMovesFinder{
    QVector<Player*> &players;
    Figure *curFig;
    Team currentTeam;

    QVector<Move> kingFind();
    QVector<Move> queenFind();
    QVector<Move> pawnFind();
    QVector<Move> rookFind();
    QVector<Move> knightFind();
    QVector<Move> bishopFind();
public:
    explicit AvailabeMovesFinder(QVector<Player*> &players, Figure *fig, Team currentTeam);
    QVector<Move> find();
};

#endif // AVAILABEMOVESFINDER_H
