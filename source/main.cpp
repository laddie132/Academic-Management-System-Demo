#include "include.h"
#include "environment.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Envir envir();
    MainWindow w;
    w.show();

    return a.exec();
}
