#include "player.h"

Player::Player(Team t) : team(t)
{
    for(int i=0;i<8;i++)
        figures.push_back(Figure::create_pawn(i,1 + 5  * t, t));

    figures.push_back(Figure::create_king(4,0 + 7 * t, t));
    figures.push_back(Figure::create_queen(3,0 + 7 * t, t));

    figures.push_back(Figure::create_rook(0,0 + 7 * t, t));
    figures.push_back(Figure::create_rook(7,0 + 7 * t, t));

    figures.push_back(Figure::create_knight(1,0 + 7 * t, t));
    figures.push_back(Figure::create_knight(6,0 + 7 * t, t));

    figures.push_back(Figure::create_bishop(2,0 + 7 * t, t));
    figures.push_back(Figure::create_bishop(5,0 + 7 * t, t));
}


QVector<Move> Player::getAvailableMoves(Figure *fig)const{
    QVector<Move> availableMoves;
    for(Move move : fig->moves){
        bool moveIsAvailable = true;
        for(Figure* curFig : figures){
            if(fig->x + move.x == curFig->x && fig->y + move.y == curFig->y){
                moveIsAvailable = false;
                break;
            }
        }
        if(moveIsAvailable)
            availableMoves.push_back(move);
    }
    return availableMoves;
}
