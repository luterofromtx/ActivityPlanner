#include "forgotpassword.h"
#include "mainwindow.h"
#include "ui_forgotpassword.h"

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
