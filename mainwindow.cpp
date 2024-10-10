#include "mainwindow.h"
#include <QMessageBox>
#include "./ui_mainwindow.h"

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

    // Test case login
    if (username == "test" && password == "test") {
        QMessageBox::information(this, "Login", "Logged in with debug base user");
        hide();
        mainTaskScreen = new MainTaskScreen(this);
        mainTaskScreen->show();
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

