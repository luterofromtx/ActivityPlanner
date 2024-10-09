#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


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

void MainWindow::on_LoginBtn_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    // Test case login
    if(username == "test" && password == "test") {
        QMessageBox::information(this, "Login", "Logged in with debug base user");
    }
}

// Create new account button
void MainWindow::on_CreateAccountBtn_clicked()
{
    hide();
    createAccount = new CreateAccount(this);
    createAccount->show();
}

