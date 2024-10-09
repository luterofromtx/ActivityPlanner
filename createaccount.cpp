#include "createaccount.h"
#include "mainwindow.h"
#include "ui_createaccount.h"

CreateAccount::CreateAccount(MainWindow *mainWindow, QWidget *parent) // Constructor using pointer to main login window
    : QDialog(parent)
    , ui(new Ui::CreateAccount)
    , mainWindow(mainWindow) // Login window pointer
{
    ui->setupUi(this);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_BackBtn_clicked()
{
    hide(); // Hide create account
    mainWindow->show(); //Return to main login page
}

