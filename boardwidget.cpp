#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent){
    core = new Core();
    curCell = new Move(-1,-1);

    connect(this,&BoardWidget::currentCellChanged,core,&Core::currentCellChanged);
}


void BoardWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    int drawArea = width();
    int d_cell = drawArea / 8;

    //Grid
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i + j) % 2 == 0)
                painter.fillRect(d_cell*j,d_cell*i,d_cell,d_cell, QBrush(QColor(Qt::white)));
            else
                painter.fillRect(d_cell*j,d_cell*i,d_cell,d_cell, QBrush(QColor(Qt::gray)));
        }
    }

    //pieces
    for(int i=0;i<core->players.size();i++)
        for(Figure* fig : core->players[i]->figures){
            QPixmap p(fig->imgPath);
            p = p.scaled(d_cell,d_cell,Qt::KeepAspectRatio);
            painter.drawPixmap(fig->x*d_cell,drawArea - (fig->y + 1)*d_cell,p.width(),p.height(),p);
        }

    //selected cell
    if(core->curFig != nullptr){
        int padding = d_cell / 14;
        QPen pen;
        pen.setWidth(2);
        pen.setColor(QColor("#2a9d8f"));
        painter.setPen(pen);
        painter.drawRect(curCell->x*d_cell + padding,drawArea - (curCell->y+1)*d_cell + padding,d_cell - 2*padding,d_cell - 2*padding);
        pen.setColor(QColor("#e9c46a"));
        painter.setPen(pen);

        QVector<Move> availableMoves = core->players[core->currentTeam]->getAvailableMoves(core->curFig);
        for(Move move : availableMoves)
            painter.drawRoundedRect((curCell->x + move.x)*d_cell + padding,drawArea - (curCell->y+1 + move.y)*d_cell + padding,
                                    d_cell - 2*padding,d_cell - 2*padding, 6, 6);
    }

}

void BoardWidget::resizeEvent(QResizeEvent *event){
    resize(width(),width());
}

void BoardWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        int d_cell = width() / 8;
        curCell->x = event->pos().x() / d_cell;
        curCell->y = 7 - event->pos().y() / d_cell;
        emit currentCellChanged(curCell);
        core->curFig = nullptr;
        if(curCell->x < 8 && curCell->y < 8 && curCell->x >=0 && curCell->y >= 0){
            for(Figure* fig : core->players[core->currentTeam]->figures){
                if(fig->x == curCell->x && fig->y == curCell->y){
                    core->curFig = fig;
                    break;
                }
            }
        }
    }

    update();
}


BoardWidget::~BoardWidget(){
    delete core;
    delete curCell;
}
