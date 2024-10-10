#include "createaccount.h"
#include "mainwindow.h"
#include "ui_createaccount.h"
#include <QFile>
#include <QTextStream>

CreateAccount::CreateAccount(MainWindow *mainWindow,
                             QWidget *parent) // Constructor using pointer to main login window
    : QDialog(parent)
    , ui(new Ui::CreateAccount)
    , mainWindow(mainWindow) // Login window pointer
{
    ui->setupUi(this);
    ui->lineEditPassword->setEchoMode(QLineEdit::Password); //Uses censored text for password and confirm boxes
    ui->lineEditConfirm->setEchoMode(QLineEdit::Password);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_BackBtn_clicked()
{    
    hide();             // Hide create account
    mainWindow->show(); //Return to main login page
}

void CreateAccount::on_CreateAccountBtn_clicked()
{
    QString newUsername = ui->lineEditUsername->text();
    QString newPassword = ui->lineEditPassword->text();

    QString newFileName = newUsername + "Cred.txt";

    QFile file(newFileName); //Opening and writing to new user file
    if(!file.open(QIODevice::ReadWrite))
    {
        qCritical() << "Could not save new user credentials!";
        qCritical() << file.errorString();
        return;
    }
    else
    {
        QTextStream stream(&file);
        stream << newUsername << "\r\n";
        stream << newPassword << "\r\n";
        stream.flush();
        file.close();
        qDebug() << "File written";
    }

}

