#include "maintaskscreen.h"
#include "mainwindow.h"
#include "ui_maintaskscreen.h"

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
    hide();             // Hide create account
    mainWindow->show(); //Return to main login page
}

void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    taskSettings = new TaskSettings(this); // Open create account page
    taskSettings->show();
}
