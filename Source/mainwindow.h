#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ZorkUL.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_westButton_clicked();

    void on_northButton_clicked();

    void on_southButton_clicked();

    void on_eastButton_clicked();

    void on_teleportButton_clicked();

    void on_takeButton_clicked();

    void on_change();

    void on_win();

    void on_lose();

    void on_map();

    void on_crown();

    void on_SoD();

    void on_lineEdit_returnPressed();

private:
    ZorkUL *temp;
    Ui::MainWindow *ui;
    bool combat;
};

#endif // MAINWINDOW_H
