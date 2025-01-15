#include "headers/core.h"

Core::Core(QObject *parent) : QObject(parent){
        players.push_back(new Player(Team::White));
        players.push_back(new Player(Team::Black));

        currentTeam = White;

        moveHistory.resize(players.size());
}

QVector<Move> Core::getAvailableMoves(){
        AvailabeMovesFinder finder(players,curFig,currentTeam);
        return finder.find();
}

QVector<Move>  Core::getAvailableAtacks(){
        AvailabeAtacksFinder finder(players,curFig,currentTeam);
        return finder.find();
}

bool Core::moveIsAvailable(Move *curCell){
        QVector<Move> availableMoves = getAvailableMoves();
        for(auto cMove : availableMoves){
                if(curFig->x + cMove.x == curCell->x && curFig->y + cMove.y == curCell->y)
                        return true;
        }
        return false;
}

bool Core::atackIsAvailable(Move *curCell){
        QVector<Move> availableMoves = getAvailableAtacks();
        for(auto cMove : availableMoves){
                if(curFig->x + cMove.x == curCell->x && curFig->y + cMove.y == curCell->y)
                        return true;
        }
        return false;
}


void Core::moveFigure(Move *curCell){
        for(Move move : curFig->moves)
                if(atackIsAvailable(curCell)){
                        makeKill(curCell);
                        break;
                }
                else if(moveIsAvailable(curCell)){
                        makeMove(curCell);
                        break;
                }
}

void Core::makeMove(Move *curCell){
        curFig->x = curCell->x;
        curFig->y = curCell->y;
        curFig->moved = true;
        moveHistory[currentTeam].push_back(*curCell);
        std::cout << curCell;
        currentTeam = currentTeam == White ? Black : White;
}

void Core::makeKill(Move *curCell){
        makeMove(curCell);
        bool killedSuccessfull = players[currentTeam]->kill(curCell);
        if (!killedSuccessfull)
                std::cout << "WARNING: kill was not successful!\n";
        else 
                std::cout << "kill was successful!\n";      
}

void Core::currentCellChanged(Move *curCell){
        if(curFig != nullptr)
                moveFigure(curCell);
}
