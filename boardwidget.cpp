#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent){
    core = new Core();

}


void BoardWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    int drawArea = width() * 1;
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
//    //Latters / numbers
//    painter.fillRect(drawArea,0,width()-drawArea,height(),QBrush(QColor(Qt::black)));
//    painter.fillRect(0,drawArea,width(),height()-drawArea,QBrush(QColor(Qt::black)));


    //pieces
    for(int i=0;i<core->players.size();i++)
        for(Figure* fig : core->players[i]->figures){
            QPixmap p(fig->imgPath);
            p = p.scaled(d_cell,d_cell,Qt::KeepAspectRatio);
            painter.drawPixmap(fig->x*d_cell,drawArea - fig->y*d_cell,p.width(),p.height(),p);
        }



}

void BoardWidget::resizeEvent(QResizeEvent *event){
    resize(width(),width());
}
