#include "main.h"
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    //ZorkUL temp;
    //temp.play();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
