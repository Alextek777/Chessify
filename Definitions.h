#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <QVector>
#include <ostream>
#include <QStringList>


enum Team{
    White = 0,
    Black
};

enum FigureType{
    King, Queen, Pawn, Rook, Knight, Bishop
};

static QList<char> ChessCoordinates = {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H'
};

struct Move{
    Move(int x_current, int y_current): x(x_current), y(y_current){}
    int x;
    int y;
    friend std::ostream& operator<<(std::ostream& os, const Move& dt);
};

class Figure{
public:
    Figure(int val = 1, Team t = Team::White) : value(val), team(t){};
    int value;
    FigureType figType;
    Team team;
    QVector<Move> moves;
    bool moved = false;
    int x;
    int y;
    QString imgPath;

public:
    static Figure* create_pawn(const int start_x, const int start_y,const Team t);
    static Figure* create_king(const int start_x, const int start_y,const Team t);
    static Figure* create_queen(const int start_x, const int start_y,const Team t);
    static Figure* create_rook(const int start_x, const int start_y,const Team t);
    static Figure* create_bishop(const int start_x, const int start_y,const Team t);
    static Figure* create_knight(const int start_x, const int start_y,const Team t);
};




#endif // DEFINITIONS_H
