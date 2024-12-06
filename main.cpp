#include <QCheckBox>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //TaskManager taskManager;
    //taskManager.show();

    /* gay shit V1
    QFile file("Perstfic.qss");


    QFile file("Cstartpage.qss");
    QFile file("Webmas.qss");
     */

    QFile file("../../Cstartpage.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    qApp->setStyleSheet(styleSheet);

    w.show();
    return a.exec();
}
