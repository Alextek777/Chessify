#include "availableactionsfinder.h"

AvailableActionFinder::AvailableActionFinder(QVector<Player*> &players, Figure *fig, Team currentTeam)
        :players(players), curFig(fig), currentTeam(currentTeam){
        enemyTeam = Team((this->currentTeam + 1) % 2);
}

QVector<Move> AvailableActionFinder::find(){
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

AvailabeMovesFinder::AvailabeMovesFinder(QVector<Player*> &players, Figure *fig, Team currentTeam) : AvailableActionFinder(players, fig, currentTeam){
}

AvailabeAtacksFinder::AvailabeAtacksFinder(QVector<Player*> &players, Figure *fig, Team currentTeam) : AvailableActionFinder(players, fig, currentTeam){
}

QVector<Move> AvailabeMovesFinder::kingFind(){
        QVector<Move> availableMoves;
        for(Move move : curFig->moves){
                bool moveIsAvailable = true;
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
                        break;
                bool moveIsAvailable = true;
                for(Figure* fig : players[currentTeam]->figures + players[enemyTeam]->figures){
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


//--------------------------------------------------------------------------------------------AVAILABLE ATACKS FINDER ---------------------------------------------------------------

QVector<Move> AvailabeAtacksFinder::kingFind(){
        QVector<Move> availableAtacks;
        for(Move move : curFig->moves)
                for(Figure* fig : players[enemyTeam]->figures)
                        if(Figure::intersect(curFig,move,fig) && !Figure::outOfRange(curFig,move))
                                availableAtacks.push_back(move);

        return availableAtacks;
}

QVector<Move> AvailabeAtacksFinder::queenFind(){
        QVector<Move> availableMoves;
        for(int i=0;i<7*4;i++)
                for(Figure* fig : players[enemyTeam]->figures)
                        if(Figure::intersect(curFig,curFig->moves[i],fig) && !Figure::outOfRange(curFig,curFig->moves[i])){
                                availableMoves.push_back(curFig->moves[i]);
                                i = (i/7 + 1)*7-1;
                                break;
                        }

        for(int i=7*4;i<7*8;i++)
                for(Figure* fig : players[enemyTeam]->figures)
                        if(Figure::intersect(curFig,curFig->moves[i],fig) && !Figure::outOfRange(curFig,curFig->moves[i])){
                                availableMoves.push_back(curFig->moves[i]);
                                i = (i/7 + 1)*7-1;
                                break;
                        }

        return availableMoves;
}

QVector<Move> AvailabeAtacksFinder::pawnFind(){
        QVector<Move> allAtacks;
        if(currentTeam == Team::White)
                allAtacks = {Move(-1,1),Move(1,1)};
        else
                allAtacks = {Move(-1,-1),Move(1,-1)};

        QVector<Move> availableAtacks;
        for(Move move : allAtacks)
                for(Figure* fig : players[enemyTeam]->figures)
                        if(Figure::intersect(curFig,move,fig) && !Figure::outOfRange(curFig,move))
                                availableAtacks.push_back(move);

        return availableAtacks;
}

QVector<Move> AvailabeAtacksFinder::rookFind(){

}

QVector<Move> AvailabeAtacksFinder::knightFind(){

}

QVector<Move> AvailabeAtacksFinder::bishopFind(){

}
