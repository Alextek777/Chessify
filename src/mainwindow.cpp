#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    BoardWidget* board = new BoardWidget();
    board->show();
}

MainWindow::~MainWindow()
{

}

