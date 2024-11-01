#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>

// Predefine class to avoid recursive calling/inheritance from main.cpp
class MainWindow;

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(
        MainWindow *mainWindow,
        QWidget *parent = nullptr); //Constructor with pointer to mainwindow so you can return
    ~CreateAccount();

private slots:
    void on_BackBtn_clicked(); // Back Btn

    void on_CreateAccountBtn_clicked();

private:
    Ui::CreateAccount *ui;
    MainWindow *mainWindow; // Pointer to mainwindow so you can return
};

#endif // CREATEACCOUNT_H
