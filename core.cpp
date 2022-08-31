#include "core.h"

Core::Core(QObject *parent) : QObject(parent){
    players.push_back(new Player(Team::White));
    players.push_back(new Player(Team::Black));

    currentTeam = White;

    moveHistory.resize(players.size());
}

QVector<Move> Core::getAvailableMoves()const{
    QVector<Move> availableMoves;

    for(Move move : curFig->moves){
        bool moveIsAvailable = true;
        for(Figure* fig : players[currentTeam]->figures){
            if(curFig->x + move.x == fig->x && curFig->y + move.y == fig->y){
                moveIsAvailable = false;
                break;
            }
        }
        if(moveIsAvailable)
            availableMoves.push_back(move);
    }

    return availableMoves;
}


bool Core::moveIsAvailable(Move *curCell){
    QVector<Move> availableMoves = getAvailableMoves();
    for(auto cMove : availableMoves){
        if(curFig->x + cMove.x == curCell->x && curFig->y + cMove.y == curCell->y)
            return true;
    }
    return false;
}

void Core::moveFigure(Move *curCell){
    for(Move move : curFig->moves)
        if(moveIsAvailable(curCell)){
            curFig->x = curCell->x;
            curFig->y = curCell->y;
            curFig->moved = true;
            moveHistory[currentTeam].push_back(*curCell);
            std::cout << curCell;
            currentTeam = currentTeam == White ? Black : White;
            break;
        }
}

void Core::currentCellChanged(Move *curCell){
    if(curFig != nullptr)
        moveFigure(curCell);
}
