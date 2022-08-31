#include "core.h"

Core::Core(QObject *parent) : QObject(parent){
    players.push_back(new Player(Team::White));
    players.push_back(new Player(Team::Black));

    currentTeam = White;

    moveHistory.resize(players.size());
}

bool Core::moveIsAvailable(Move *curCell){
    QVector<Move> availableMoves = players[currentTeam]->getAvailableMoves(curFig);
    for(auto cMove : availableMoves){
        if(curFig->x + cMove.x == curCell->x && curFig->y + cMove.y == curCell->y)
            return true;
    }
    return false;
}

void Core::currentCellChanged(Move *curCell){
    if(curFig != nullptr){
        for(Move move : curFig->moves){

            if(moveIsAvailable(curCell)){
                curFig->x = curCell->x;
                curFig->y = curCell->y;
                moveHistory[currentTeam].push_back(*curCell);
                std::cout << curCell;
                currentTeam = currentTeam == White ? Black : White;
                break;
            }
        }
    }
}
