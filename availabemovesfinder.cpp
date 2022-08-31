#include "availabemovesfinder.h"


AvailabeMovesFinder::AvailabeMovesFinder(QVector<Player*> &players, Figure *fig) : players(players), fig(fig){
}

QVector<Move> AvailabeMovesFinder::find(){
    switch (fig->figType) {
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

}

QVector<Move> AvailabeMovesFinder::queenFind(){

}

QVector<Move> AvailabeMovesFinder::pawnFind(){

}

QVector<Move> AvailabeMovesFinder::rookFind(){

}

QVector<Move> AvailabeMovesFinder::knightFind(){

}

QVector<Move> AvailabeMovesFinder::bishopFind(){

}
