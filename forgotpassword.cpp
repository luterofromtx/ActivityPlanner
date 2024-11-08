#include "forgotpassword.h"
#include "mainwindow.h"
#include "ui_forgotpassword.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
ForgotPassword::ForgotPassword(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ForgotPassword)
    , mainWindow(mainWindow)
{
    ui->setupUi(this);
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}

// Cancel password reset button
void ForgotPassword::on_CancelBtn_clicked()
{
    // Cancel forgot password, close window and open login ui
    hide();
    mainWindow->show();
}

void ForgotPassword::on_ConfirmBtn_clicked()
{
    QString username =  ui->lineEditUsername->text();
    QString newPassword =  ui->lineEditPassword->text();
    QString confirmNewPassword =  ui->lineEditConfirmPass->text();
    QString userFile = "./Users/" + username + "/" + username + "Cred.txt";

    //Run proper checks first
    QDir root;
    if (!root.exists("Users")) {
        QMessageBox::critical(this, "Error", "Please create an account first.");
        return;
    } else if(newPassword!=confirmNewPassword) {
        QMessageBox::critical(this, "Error", "Passwords do not match.");
        return;
    }
    QDir user;
    if(!user.exists(username)) {
        QMessageBox::critical(this, "Error", "Username specified does not exist.");
        return;
    }

    //Write to the file
    QFile file(userFile);
    if(!file.open(QIODevice::ReadWrite)) {
        qCritical() << username << ": Could not open file!";
        qCritical() << file.errorString();
    } else {
        QTextStream stream(&file);
        stream << username << "\r\n";
        stream << newPassword;

        file.flush();
        file.close();
        qDebug() << "Password updated, file saved successfully.";
        QMessageBox::about(this, "Activity Planner", "Password changed successfully!");
    }

    this->hide();
    mainWindow->show();
}

