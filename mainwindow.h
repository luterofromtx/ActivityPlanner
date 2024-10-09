#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createaccount.h"
#include "maintaskscreen.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginBtn_clicked();

    void on_CreateAccountBtn_clicked();

private:
    Ui::MainWindow *ui;
    CreateAccount *createAccount; // Pointer to createaccount ui
    MainTaskScreen *mainTaskScreen;
};
#endif // MAINWINDOW_H
