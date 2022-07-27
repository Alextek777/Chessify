#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPicture>
#include <QDebug>
#include <QMouseEvent>

#include "core.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
private:
    Core *core;
    Move *curCell;

public:
    explicit BoardWidget(QWidget *parent = nullptr);
    ~BoardWidget();
protected:
    void paintEvent(QPaintEvent *event)override;
    void resizeEvent(QResizeEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
signals:

};

#endif // BOARDWIDGET_H
