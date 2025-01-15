#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boardwidget.h"
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    BoardWidget *board;

    QWidget* centralWidget;
    QGridLayout* mainLayout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
protected:
    void resizeEvent(QResizeEvent *event)override;
};
#endif // MAINWINDOW_H
