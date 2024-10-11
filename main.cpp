#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //TaskManager taskManager;
    //taskManager.show();
    w.show();
    //Design for saving all on exit here
    return a.exec();
}
