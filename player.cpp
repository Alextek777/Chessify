#include "player.h"

Player::Player(Team t) : team(t)
{
    for(int i=0;i<8;i++)
        figures.push_back(Figure::create_pawn(i,2 + 5  * t, t));

    figures.push_back(Figure::create_king(4,1 + 7 * t, t));
    figures.push_back(Figure::create_queen(3,1 + 7 * t, t));

    figures.push_back(Figure::create_rook(0,1 + 7 * t, t));
    figures.push_back(Figure::create_rook(7,1 + 7 * t, t));

    figures.push_back(Figure::create_knight(1,1 + 7 * t, t));
    figures.push_back(Figure::create_knight(6,1 + 7 * t, t));

    figures.push_back(Figure::create_bishop(2,1 + 7 * t, t));
    figures.push_back(Figure::create_bishop(5,1 + 7 * t, t));
}
