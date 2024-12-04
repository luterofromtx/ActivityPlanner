#include "mainwindow.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QCheckBox>
#include "./ui_mainwindow.h"
#include "maintaskscreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CheckIfRemembered(); //Place remembered username in ui->LineEditUsername if one exists
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
    QString usernameFile = "./Users/" + username + "/" + username + "Cred.txt";
    QFile userFile(usernameFile);

    //Check if any account has been made
    QDir root;
    if (!root.exists("Users")) { //If 'Users' folder does not exist, meaning no users exist
        QMessageBox::critical(this, "Error", "Please create an account first.");
        return;
    } else if(!userFile.exists()) { //If the user's file does not exist, meaning no existing user with username attempted
        QMessageBox::critical(this, "Error", "Invalid credentials. Please try again.");
        return;
    } else if(!userFile.open(QIODevice::ReadOnly)){ //If user's file is valid but cannot be opened
        QMessageBox::critical(this,
                              "Error",
                              "Sorry, this user file got too weird so it did not open.");
        return;
    } else {
        QTextStream stream(&userFile); //Parsing file
        while (!stream.atEnd()) {
            usernameCompare = stream.readLine(); //if username typed matches first line of user file
             passwordCompare = stream.readLine();
        }
        if (usernameCompare == username
            && passwordCompare == password) //If the credentials ARE valid
        {
            QMessageBox::about(this, "Activity Planner", "Login successful!");
            //Hide login screen and show main task screen
            userFile.close();
            successfulLoginUsername = username; //defined in MainWindow.h

            if(ui->RememberMeCheck->isChecked()) //If the user checked "Remember Me"
            {
                RememberUser();
            } else {                            //If the user left "Remember Me" unchecked
                ForgetUser();
            }

            this->hide();
            MainTaskScreen *taskScreen = new MainTaskScreen(this);
            taskScreen->show();

            taskScreen->setupUser(usernameCompare);
            taskScreen->printCurrentUserTasks();

        } else {
            QMessageBox::critical(this, "Error", "Invalid login. Please try again.");
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

//"Remember Me" Checkbox Function
void MainWindow::RememberUser()
{
    QString rememberUserFile = "./Users/RememberMe.txt";
    QFile file(rememberUserFile);

    if(!file.open(QIODevice::ReadWrite)) { //RememberMe.txt could not be opened
        qCritical() << rememberUserFile << ": User too forgettable!";
        qCritical() << file.errorString();
    } else {
        QTextStream stream(&file);
        stream << ui->lineEditUsername->text();
        file.flush();
        file.close();
    }
}

//"Remember Me" Checkbox Function if UNCHECKED when logging in
void MainWindow::ForgetUser()
{
    QString rememberUserFile = "./Users/RememberMe.txt";
    QFile file(rememberUserFile);

    if(!file.open(QIODevice::ReadWrite)) { //RememberMe.txt could not be opened
        qCritical() << rememberUserFile << ": User too forgettable!";
        qCritical() << file.errorString();
    } else {
        file.resize(0);
        file.flush();
        file.close();
    }
}

//Check if user wanted to be remembered during last login
void MainWindow::CheckIfRemembered()
{
    QString rememberUserFile = "./Users/RememberMe.txt";
    QFile file(rememberUserFile);

    if(!file.open(QIODevice::ReadOnly)) { //RememberMe.txt could not be opened
        qCritical() << rememberUserFile << ": User too forgettable!";
        qCritical() << file.errorString();
    } else if(file.size()==0) {
        qDebug() << "No user was remembered. Starting with empty text fields";
    } else {
        QTextStream stream(&file);
        QString RememberedUsername = stream.readLine();
        file.close();

        ui->lineEditUsername->setText(RememberedUsername); //Places the username stored in RememberMe.txt in ui->LineEditUsername

        //Make sure "Remember Me" is still checked if there is a remembered user
        if(!ui->RememberMeCheck->isChecked())
        {
            ui->RememberMeCheck->setChecked(true);
        }
    }
}
