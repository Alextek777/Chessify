#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boardwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    BoardWidget *board;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
