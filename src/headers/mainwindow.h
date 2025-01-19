#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "menue.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Menue *menueWidget;

    QWidget* centralWidget;
    QGridLayout* mainLayout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
protected:
    void resizeEvent(QResizeEvent *event)override;
};
#endif // MAINWINDOW_H
