#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class FitVew;
class QGraphicsScene;
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //for Graphic View Framework
    FitView *view;
    QGraphicsScene *scene;

    QSystemTrayIcon *systray;
};

#endif // MAINWINDOW_H
