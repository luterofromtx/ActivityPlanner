#include "mainwindow.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "./ui_mainwindow.h"
#include "maintaskscreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Login button
void MainWindow::on_LoginBtn_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString usernameCompare;
    QString passwordCompare;

    //Check if any account has been made
    QDir root;
    if (!root.exists("Users")) {
        QMessageBox::critical(this, "Error", "Please create an account first.");
        return;
    } else {
        qInfo() << "Users folder already exists, skipping...";
        QString usernameFile = "./Users/" + username + "/" + username + "Cred.txt";
        //Locate file if exists
        QFile userFile(usernameFile);
        if (!userFile.exists()) {
            QMessageBox::critical(this, "Error", "Invalid credentials. Please try again.");
        } else {
            if (!userFile.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this,
                                      "Error",
                                      "Sorry, this user file got too weird so it did not open.");
            } else {
                QTextStream stream(&userFile); //Parsing file
                while (!stream.atEnd()) {
                    usernameCompare = stream.readLine();
                    passwordCompare = stream.readLine();
                }
                if (usernameCompare == username
                    && passwordCompare == password) //Testing login validity
                {
                    QMessageBox::about(this, "Activity Planner", "Login successful!");
                    //Hide login screen and show main task screen
                    userFile.close();
                    successfulLoginUsername = username; //defined in MainWindow.h
                    this->hide();
                    MainTaskScreen *taskScreen = new MainTaskScreen(this);
                    taskScreen->show();

                } else {
                    QMessageBox::critical(this, "Error", "Invalid login. Please try again.");
                }
            }
        }
    }
}

// Create new account button
void MainWindow::on_CreateAccountBtn_clicked()
{
    // Hide login window and open create account ui
    hide();
    createAccount = new CreateAccount(this);
    createAccount->show();
}

// Forgot Password button
void MainWindow::on_ForgotPasswordBtn_clicked()
{
    // Hide login window and open forgot password ui
    hide();
    forgotPassword = new ForgotPassword(this);
    forgotPassword->show();
}
