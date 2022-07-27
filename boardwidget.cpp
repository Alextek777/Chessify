#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent){
    core = new Core();
    curCell = new Move(-1,-1);
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
    if(curCell->x < 8 && curCell->y < 8 && curCell->x >=0 && curCell->y >= 0){
        QPen pen;
        pen.setWidth(4);
        pen.setColor(QColor("#2a9d8f"));
        painter.setPen(pen);
        painter.drawRect(curCell->x*d_cell,drawArea - (curCell->y+1)*d_cell,d_cell,d_cell);
    }


}

void BoardWidget::resizeEvent(QResizeEvent *event){
    resize(width(),width());
}

void BoardWidget::mousePressEvent(QMouseEvent *event){
    int d_cell = width() / 8;
    curCell->x = event->pos().x() / d_cell;
    curCell->y = 7 - event->pos().y() / d_cell;
    qDebug() << ChessCoordinates[curCell->x] << curCell->y;
    update();
}


BoardWidget::~BoardWidget(){
    delete core;
    delete curCell;
}
