#include "availabemovesfinder.h"


AvailabeMovesFinder::AvailabeMovesFinder(QVector<Player*> &players, Figure *fig, Team currentTeam)
    :players(players), curFig(fig), currentTeam(currentTeam){
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
}

QVector<Move> AvailabeMovesFinder::kingFind(){
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
        if(curFig->moved && move.y == 2)
            break;
        bool moveIsAvailable = true;
        for(Figure* fig : players[0]->figures + players[1]->figures){
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
