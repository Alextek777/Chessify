#ifndef AVAILABLEACTIONSFINDER_H
#define AVAILABLEACTIONSFINDER_H
#include "Definitions.h"
#include "player.h"

//Abstract Action Factory
class AvailableActionFinder{
protected:
        QVector<Player*> &players;
        Figure *curFig;
        Team currentTeam;
        Team enemyTeam;

        virtual QVector<Move> kingFind() = 0;
        virtual QVector<Move> queenFind() = 0;
        virtual QVector<Move> pawnFind() = 0;
        virtual QVector<Move> rookFind() = 0;
        virtual QVector<Move> knightFind() = 0;
        virtual QVector<Move> bishopFind() = 0;

public:
        explicit AvailableActionFinder(QVector<Player*> &players, Figure *fig, Team currentTeam);
        QVector<Move> find();
};


class AvailabeMovesFinder : public AvailableActionFinder{
protected:
        QVector<Move> kingFind()override;
        QVector<Move> queenFind()override;
        QVector<Move> pawnFind()override;
        QVector<Move> rookFind()override;
        QVector<Move> knightFind()override;
        QVector<Move> bishopFind()override;
public:
        explicit AvailabeMovesFinder(QVector<Player*> &players, Figure *fig, Team currentTeam);
};

class AvailabeAtacksFinder : public AvailableActionFinder{
protected:
        QVector<Move> kingFind()override;
        QVector<Move> queenFind()override;
        QVector<Move> pawnFind()override;
        QVector<Move> rookFind()override;
        QVector<Move> knightFind()override;
        QVector<Move> bishopFind()override;
public:
        explicit AvailabeAtacksFinder(QVector<Player*> &players, Figure *fig, Team currentTeam);
};

#endif // AVAILABLEACTIONSFINDER_H
