#include "Definitions.h"

Figure* Figure::create_pawn(const int start_x, const int start_y,const Team t){
    Figure *figure = new Figure(1,t);
    figure->figType = FigureType::Pawn;
    figure->x = start_x;
    figure->y = start_y;

    figure->moves = {
        Move(0,1),
        Move(0,2)};

    return figure;
}

Figure* Figure::create_king(const int start_x, const int start_y,const Team t){
    Figure *figure = new Figure(1,t);
    figure->figType = FigureType::King;
    figure->x = start_x;
    figure->y = start_y;

    figure->moves = {
        Move(0,1),
        Move(1,1),
        Move(1,0),
        Move(1,-1),
        Move(0,-1),
        Move(-1,-1),
        Move(-1,0),
        Move(-1,1)};

    return figure;
}

Figure* Figure::create_rook(const int start_x, const int start_y,const Team t){
    Figure *figure = new Figure(4,t);
    figure->figType = FigureType::Rook;
    figure->x = start_x;
    figure->y = start_y;

    for(int i=1;i<8;i++) //up
        figure->moves.push_back(Move(0,i));

    for(int i=1;i<8;i++) //right
        figure->moves.push_back(Move(i,0));

    for(int i=1;i<8;i++) //down
        figure->moves.push_back(Move(0,-i));

    for(int i=1;i<8;i++) //left
        figure->moves.push_back(Move(-i,0));

    return figure;
}

Figure* Figure::create_bishop(const int start_x, const int start_y,const Team t){
    Figure *figure = new Figure(4,t);
    figure->figType = FigureType::Bishop;
    figure->x = start_x;
    figure->y = start_y;

    for(int i=1;i<8;i++) //up right
        figure->moves.push_back(Move(i,i));

    for(int i=1;i<8;i++) //down right
        figure->moves.push_back(Move(i,-i));

    for(int i=1;i<8;i++) //down left
        figure->moves.push_back(Move(-i,-i));

    for(int i=1;i<8;i++) //up left
        figure->moves.push_back(Move(-i,i));

    return figure;
}

Figure* Figure::create_knight(const int start_x, const int start_y,const Team t){
    Figure *figure = new Figure(4,t);
    figure->figType = FigureType::Knight;
    figure->x = start_x;
    figure->y = start_y;

    figure->moves.push_back(Move(-1,2));
    figure->moves.push_back(Move(1,2));
    figure->moves.push_back(Move(2,1));
    figure->moves.push_back(Move(2,-1));
    figure->moves.push_back(Move(1,-2));
    figure->moves.push_back(Move(-1,-2));
    figure->moves.push_back(Move(-2,-1));
    figure->moves.push_back(Move(-2,1));

    return figure;
}

Figure* Figure::create_queen(const int start_x, const int start_y,const Team t){
    Figure *figure = new Figure(4,t);
    figure->figType = FigureType::Queen;
    figure->x = start_x;
    figure->y = start_y;

    for(int i=1;i<8;i++) //up
        figure->moves.push_back(Move(0,i));

    for(int i=1;i<8;i++) //right
        figure->moves.push_back(Move(i,0));

    for(int i=1;i<8;i++) //down
        figure->moves.push_back(Move(0,-i));

    for(int i=1;i<8;i++) //left
        figure->moves.push_back(Move(-i,0));

    //--------------------------------------

    for(int i=1;i<8;i++) //up right
        figure->moves.push_back(Move(i,i));

    for(int i=1;i<8;i++) //down right
        figure->moves.push_back(Move(i,-i));

    for(int i=1;i<8;i++) //down left
        figure->moves.push_back(Move(-i,-i));

    for(int i=1;i<8;i++) //up left
        figure->moves.push_back(Move(-i,i));

    //--------------------------------------

    return figure;
}
