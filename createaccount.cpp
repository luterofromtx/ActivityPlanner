#include "createaccount.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_createaccount.h"

CreateAccount::CreateAccount(MainWindow *mainWindow,
                             QWidget *parent) // Constructor using pointer to main login window
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
    // Cancel create account and return to main login
    hide();
    mainWindow->show();
}

void CreateAccount::on_CreateAccountBtn_clicked()
{
    QString newUsername = ui->lineEditUsername->text();
    QString newPassword = ui->lineEditPassword->text();
    QString newPasswordConfirm = ui->lineEditConfirm->text();

    if (newPassword != newPasswordConfirm) {
        QMessageBox::critical(this, "Error", "Passwords do not match.");
        return;
    }

    //Create user directory to store user file in if not exists
    QDir root;
    if (!root.exists("Users")) {
        root.mkdir("Users");
        QDir dir("Users");
        qInfo() << "Created" << dir.absolutePath();
    } else {
        qInfo() << "Users folder already exists, skipping...";
    }
    //Name new user file after username and save to path
    QString newUserFile = "./Users/" + newUsername + "Cred.txt";

    QFile file(newUserFile);
    if (!file.open(QIODevice::ReadWrite)) {
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
    } else {
        QTextStream stream(&file);
        stream << newUsername << "\r\n";
        stream << newPassword;

        file.flush();
        file.close();
        qDebug() << "Account created, file saved.";
        QMessageBox::about(this, "Activity Planner", "Account created successfully!");
    }
    this->hide();
    mainWindow->show(); //Go back to login screen on completing new account
}
