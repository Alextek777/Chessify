#include "core.h"

Core::Core(QObject *parent) : QObject(parent){
    players.push_back(new Player(Team::White));
    players.push_back(new Player(Team::Black));

    currentTeam = White;

    moveHistory.resize(players.size());
}



void Core::currentCellChanged(Move *curCell){
    if(curFig != nullptr){
        for(Move move : curFig->moves){
            if(curFig->x + move.x == curCell->x && curFig->y + move.y == curCell->y){
                curFig->x = curCell->x;
                curFig->y = curCell->y;
                moveHistory[currentTeam].push_back(*curCell);
                currentTeam = currentTeam == White ? Black : White;
                break;
            }
        }
    }
}
