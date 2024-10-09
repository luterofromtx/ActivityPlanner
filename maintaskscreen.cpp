#include "maintaskscreen.h"
#include "ui_maintaskscreen.h"
#include "mainwindow.h"

MainTaskScreen::MainTaskScreen(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainTaskScreen)
    , mainWindow(mainWindow)
{
    ui->setupUi(this);
}

MainTaskScreen::~MainTaskScreen()
{
    delete ui;
}

void MainTaskScreen::on_LogoutBtn_clicked()
{
    hide(); // Hide create account
    mainWindow->show(); //Return to main login page
}

