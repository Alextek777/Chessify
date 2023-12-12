#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include "availableactionsfinder.h"
#include "player.h"

class Core : public QObject{
public:
    Core(QObject *parent = 0);
    virtual ~Core() {};
public:
    QVector<Player*> players;
    QVector<QVector<Move>> moveHistory;

    Team currentTeam;
    Figure* curFig = nullptr;
    QVector<Move> getAvailableMoves();
    QVector<Move>  getAvailableAtacks();
public slots:
    void currentCellChanged(Move *curCell);
    bool moveIsAvailable(Move *curCell);
private:
    void moveFigure(Move *curCell);
};


#endif // CORE_H
