#include "headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainLayout = new QGridLayout(this);
    centralWidget = new QWidget(this);

    menueWidget = new Menue();

    //TODO: REMOVE
    menueWidget->AddGame(GameOptions("Alex"));
    menueWidget->AddGame(GameOptions("Michael"));
    menueWidget->AddGame(GameOptions("George"));
    menueWidget->AddGame(GameOptions("Good Games"));

    mainLayout->addWidget(menueWidget);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent *event){

}
