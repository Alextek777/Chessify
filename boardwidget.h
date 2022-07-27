#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPicture>

#include "core.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
private:
    Core *core;

public:
    explicit BoardWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event)override;
    void resizeEvent(QResizeEvent *event)override;
signals:

};

#endif // BOARDWIDGET_H
