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

    QDir userDir("Users");
    if (!userDir.exists(newUsername)) {
        userDir.mkdir(newUsername);
        QDir dir(newUsername);
        qInfo() << "Created" << dir.absolutePath();
    } else {
        qInfo() << newUsername + " folder already exists, skipping...";
    }

    //Name new user files and add to path
    QString newUserFile = "./Users/" + newUsername + "/" + newUsername + "Cred.txt";
    QString newUserOpenTasks = "./Users/" + newUsername + "/" + newUsername + "OpenTasks.txt";
    QString newUserClosedTasks = "./Users/" + newUsername + "/" + newUsername + "ClosedTasks.txt";

    QFile file(newUserFile);
    if (!file.open(QIODevice::ReadWrite)) {
        qCritical() << newUserFile << ": Could not open file!";
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

    QFile openTasksFile(newUserOpenTasks);
    if (!openTasksFile.open(QIODevice::ReadWrite)) {
        qCritical() << newUserOpenTasks << ": Could not open file!";
        qCritical() << openTasksFile.errorString();
    } else {
        openTasksFile.close();
    }

    QFile closedTasksFile(newUserClosedTasks);
    if (!closedTasksFile.open(QIODevice::ReadWrite)) {
        qCritical() << newUserClosedTasks << ": Could not open file!";
        qCritical() << closedTasksFile.errorString();
    } else {
        openTasksFile.close();
    }

    this->hide();
    mainWindow->show(); //Go back to login screen on completing new account
}
