#ifndef AVAILABLEACTIONSFINDER_H
#define AVAILABLEACTIONSFINDER_H
#include "Definitions.h"
#include "player.h"

class AvailableActionsFinder {
protected:
        QVector<Player*> &players;
        Figure *curFig;
        Team currentTeam;
        Team enemyTeam;

        explicit AvailableActionsFinder(QVector<Player*> &players, Figure *fig, Team currentTeam);
};

class AvailabeMovesFinder : public AvailableActionsFinder {
protected:
        QVector<Move> kingFind();
        QVector<Move> queenFind();
        QVector<Move> pawnFind();
        QVector<Move> rookFind();
        QVector<Move> knightFind();
        QVector<Move> bishopFind();

public:
        QVector<Move> find();
        explicit AvailabeMovesFinder(QVector<Player*> &players, Figure *fig, Team currentTeam);
};

class AvailabeAtacksFinder : public AvailableActionsFinder {
public:
        QVector<Move> find();

        QVector<Move> defaultFind();
        QVector<Move> pawnFind();

        explicit AvailabeAtacksFinder(QVector<Player*> &players, Figure *fig, Team currentTeam);
};

#endif // AVAILABLEACTIONSFINDER_H
