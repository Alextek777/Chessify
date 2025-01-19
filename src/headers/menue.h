#ifndef MENUE_H
#define MENUE_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>

struct GameOptions
{
    GameOptions(QString name){
        Name = name;
    };

    QString Name;
};

class Menue : public QWidget
{
    Q_OBJECT
    QVBoxLayout mainLayout;


    QListWidget gameList;
    QPushButton *b_startGame;

public:
    explicit Menue(QWidget *parent = nullptr);

    void AddGame(GameOptions& game);
    void AddGame(GameOptions&& game);

signals:

private slots:
    void createGame();

};




#endif // MENUE_H
