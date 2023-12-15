#include "Definitions.h"

Figure* Figure::create_pawn(const int start_x, const int start_y,const Team t){
    Figure *figure = new Figure(1,t);
    figure->figType = FigureType::Pawn;
    figure->x = start_x;
    figure->y = start_y;
    int teamFlag = t == Team::White ? 1 : -1;

    figure->moves = {
        Move(0,1*teamFlag),
        Move(0,2*teamFlag)};

    figure->imgPath = t == Team::White ? "./src/images/pieces/wp.png" : "./src/images/pieces/bp.png";

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
        Move(-1,1),
        Move(2,0),      //castle right
        Move(-2,0)};    //castle left

    figure->imgPath = t == Team::White ? "./src/images/pieces/wk.png" : "./src/images/pieces/bk.png";

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

    figure->imgPath = t == Team::White ? "./src/images/pieces/wr.png" : "./src/images/pieces/br.png";

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

    figure->imgPath = t == Team::White ? "./src/images/pieces/wb.png" : "./src/images/pieces/bb.png";

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

    figure->imgPath = t == Team::White ? "./src/images/pieces/wkn.png" : "./src/images/pieces/bkn.png";

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

    figure->imgPath = t == Team::White ? "./src/images/pieces/wq.png" : "./src/images/pieces/bq.png";

    return figure;
}

std::ostream& operator<<(std::ostream& os, const Move& dt)
{
    os << "[" << ChessCoordinates[dt.y] << dt.x << "]";
    return os;
}

bool Figure::intersect(Figure *fig1,Move &move, Figure *fig2){
    return (fig1->x + move.x == fig2->x && fig1->y + move.y == fig2->y);
}

bool Figure::outOfRange(Figure *fig,Move &move){
    return fig->x + move.x < 0 || fig->x + move.x >= 8 ||
            fig->y + move.y < 0 || fig->y + move.y >= 8;
}
