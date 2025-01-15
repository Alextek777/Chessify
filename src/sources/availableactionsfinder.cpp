#include "headers/availableactionsfinder.h"
#include <iostream>

AvailableActionsFinder::AvailableActionsFinder(QVector<Player*> &players, Figure *fig, Team currentTeam) : players(players), curFig(fig), currentTeam(currentTeam){
        enemyTeam = Team((this->currentTeam + 1) % 2);
}

QVector<Move> AvailabeMovesFinder::find(){
        switch (curFig->figType) {
        case FigureType::Bishop:
                return bishopFind();
        case FigureType::King:
                return kingFind();
        case FigureType::Knight:
                return knightFind();
        case FigureType::Pawn:
                return pawnFind();
        case FigureType::Queen:
                return queenFind();
        case FigureType::Rook:
                return rookFind();

        default:
                return QVector<Move>();  //empty moves
        }

        return QVector<Move>();
}

QVector<Move> AvailabeAtacksFinder::find(){
        switch (curFig->figType)
        {
        case FigureType::Pawn:
                return pawnFind();
        default:
                return defaultFind();
        }

        assert(true);
}

QVector<Move> AvailabeAtacksFinder::defaultFind(){
        QVector<Move> availableAtacks;
        AvailabeMovesFinder movesFinder(players, curFig, currentTeam);
        QVector<Move> availableMoves = movesFinder.find();

        Player* enemyPlayer = players[!currentTeam];

        for(auto enemyPiece : enemyPlayer->figures){
                for(auto move : availableMoves){
                        int currentX = curFig->x + move.x;
                        int currentY = curFig->y + move.y;
                        if (currentX == enemyPiece->x && currentY == enemyPiece->y)
                                availableAtacks.push_back(move);
                }
        }
        return availableAtacks;
}

QVector<Move> AvailabeAtacksFinder::pawnFind(){
        QVector<Move> availableAtacks;
        int yDirection = currentTeam == Team::White ? 1 : -1;
        std::cout <<"x : " << curFig->x << "\ty: " << curFig->y << "\n";
        Move left  = Move(-1, yDirection*1);
        Move right = Move(1, yDirection*1);
        
        for(auto fig : players[enemyTeam]->figures){
                if(fig->x == curFig->x + left.x && fig->y == curFig->y + left.y)
                        availableAtacks.push_back(left);
                else if(fig->x == curFig->x + right.x && fig->y == curFig->y + right.y)
                        availableAtacks.push_back(right);
        }
        return availableAtacks;
}

AvailabeMovesFinder::AvailabeMovesFinder(QVector<Player*> &players, Figure *fig, Team currentTeam) : AvailableActionsFinder(players, fig, currentTeam){}

AvailabeAtacksFinder::AvailabeAtacksFinder(QVector<Player*> &players, Figure *fig, Team currentTeam) : AvailableActionsFinder(players, fig, currentTeam){}

QVector<Move> AvailabeMovesFinder::kingFind(){
        QVector<Move> availableMoves;
        for(Move move : curFig->moves){
                bool moveIsAvailable = true;
                if(abs(move.x) == 2 && curFig->moved) continue;         //TODO if king moved cannot castle (doesnt check if rooks moved!!!)

                for(Figure* fig : players[currentTeam]->figures){
                        if(Figure::intersect(curFig,move,fig)){
                                moveIsAvailable = false;
                                break;
                        }
                }
                if(moveIsAvailable)
                        availableMoves.push_back(move);
        }
        return availableMoves;
}

QVector<Move> AvailabeMovesFinder::queenFind(){
        QVector<Move> availableMoves;
        for(int i=0;i<7*4;i++){
                bool moveIsAvailable = true;
                for(Figure* fig : players[currentTeam]->figures){
                        if(Figure::intersect(curFig,curFig->moves[i],fig) && !Figure::outOfRange(curFig,curFig->moves[i])){
                                moveIsAvailable = false;
                                i = (i/7 + 1)*7-1;
                                break;
                        }
                }
                if(moveIsAvailable)
                        availableMoves.push_back(curFig->moves[i]);
        }

        for(int i=7*4;i<7*8;i++){
                bool moveIsAvailable = true;
                for(Figure* fig : players[currentTeam]->figures){
                        if(Figure::intersect(curFig,curFig->moves[i],fig) && !Figure::outOfRange(curFig,curFig->moves[i])){
                                moveIsAvailable = false;
                                i = (i/7 + 1)*7-1;
                                break;
                        }
                }
                if(moveIsAvailable)
                        availableMoves.push_back(curFig->moves[i]);
        }
        return availableMoves;
}

QVector<Move> AvailabeMovesFinder::pawnFind(){
        QVector<Move> availableMoves;
        for(Move move : curFig->moves){
                if(curFig->moved && (move.y == 2 || move.y == -2)) //not include 2 steps forward move if pawn has already moved
                        return availableMoves;
                bool moveIsAvailable = true;
                for(Figure* fig : players[currentTeam]->figures + players[enemyTeam]->figures){                 
                        if(Figure::intersect(curFig,move,fig) && !Figure::outOfRange(curFig,move)){
                                return availableMoves;
                        }
                }
                availableMoves.push_back(move);
        }
        return availableMoves;
}

QVector<Move> AvailabeMovesFinder::rookFind(){
        QVector<Move> availableMoves;
        for(int i=0;i<7*4;i++){
                bool moveIsAvailable = true;
                for(Figure* fig : players[currentTeam]->figures){
                        if(Figure::intersect(curFig,curFig->moves[i],fig) && !Figure::outOfRange(curFig,curFig->moves[i])){
                                moveIsAvailable = false;
                                i = (i/7 + 1)*7-1;
                                break;
                        }
                }
                if(moveIsAvailable)
                        availableMoves.push_back(curFig->moves[i]);
        }
        return availableMoves;
}

QVector<Move> AvailabeMovesFinder::knightFind(){
        QVector<Move> availableMoves;
        for(Move move : curFig->moves){
                bool moveIsAvailable = true;
                for(Figure* fig : players[currentTeam]->figures){
                        if(Figure::intersect(curFig,move,fig) && !Figure::outOfRange(curFig,move)){
                                moveIsAvailable = false;
                                break;
                        }
                }
                if(moveIsAvailable)
                        availableMoves.push_back(move);
        }
        return availableMoves;
}

QVector<Move> AvailabeMovesFinder::bishopFind(){
        QVector<Move> availableMoves;
        for(int i=0;i<7*4;i++){
                bool moveIsAvailable = true;
                for(Figure* fig : players[currentTeam]->figures){
                        if(Figure::intersect(curFig,curFig->moves[i],fig) && !Figure::outOfRange(curFig,curFig->moves[i])){
                                moveIsAvailable = false;
                                i = (i/7 + 1)*7-1;
                                break;
                        }
                }
                if(moveIsAvailable)
                        availableMoves.push_back(curFig->moves[i]);
        }
        return availableMoves;
}
