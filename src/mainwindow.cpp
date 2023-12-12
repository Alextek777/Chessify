#include "mainwindow.h"
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //std::unique_ptr<BoardWidget> board(new BoardWidget());
    board = new BoardWidget();
    board->show();
}

MainWindow::~MainWindow()
{
    if(board)
        delete board;
}

