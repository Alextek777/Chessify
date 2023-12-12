#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainLayout = new QGridLayout(this);
    board = new BoardWidget();
    centralWidget = new QWidget(this);

    mainLayout->addWidget(board, 0, 0);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    if(board)
        delete board;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    resize(width(),width());
}
