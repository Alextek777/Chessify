#include "headers/menue.h"
#include "headers/boardwidget.h"
#include <QDebug>

Menue::Menue(QWidget *parent)
    : QWidget{parent}
{
    gameList.setParent(parent);
    b_startGame = new QPushButton("Start Game", parent);

    mainLayout.addWidget(&gameList);
    mainLayout.addWidget(b_startGame);
    setLayout(&mainLayout);


    connect(b_startGame, &QPushButton::released, this, &Menue::createGame);
}

void Menue::AddGame(GameOptions& game) {
    this->gameList.addItem(game.Name);
}

void Menue::AddGame(GameOptions&& game) {
    this->gameList.addItem(game.Name);
}

void Menue::createGame() {
    BoardWidget *newBoard = new BoardWidget();
    newBoard->show();
}
