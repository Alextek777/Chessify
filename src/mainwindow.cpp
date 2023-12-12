#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    board = new BoardWidget();
    board->show();
}

MainWindow::~MainWindow()
{
    if(board)
        delete board;
}

