#include "maintaskscreen.h"
#include "mainwindow.h"
#include "ui_maintaskscreen.h"
#include "currentuser.h"

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

// Logout User button
void MainTaskScreen::on_LogoutBtn_clicked()
{
    // Log user out and return to main login page (currently only hides ui and doesnt logout)
    hide();
    mainWindow->show();
}

// Open Add new task page button
void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    // Open add new task ui
    taskSettings = new TaskSettings(this);
    taskSettings->show();
}

// Open settings/notification center
void MainTaskScreen::on_SettingsBtn_clicked()
{
    // Show notification settings ui (Update this to save and load user settings)
    // Currently only opens fresh page of settings
    notifications = new Notifications(this);
    notifications->show();
}

// Specific Date double clicked
void MainTaskScreen::on_calendarWidget_activated(const QDate &date)
{
    // Open settings for selected date
    dateSettings = new DateSettings(this);
    dateSettings->show();
}

// Open big calendar button
void MainTaskScreen::on_OpenCalenderBtn_clicked()
{
    largeCalendar = new LargeCalendar(this);
    largeCalendar->show();
}

// Quick add new task button
void MainTaskScreen::on_QuickAddBtn_clicked()
{
    // Get Basic info for quick add
    QString taskName = ui->lineEditTaskName->text();
    QString taskDesc = ui->lineEditDesc->text();
    QString taskDeadline = ui->lineEditDeadline->text();

    Task newtask(taskName, taskDesc, taskDeadline); // Construct new task with basic given info and put in temp user
    CurrentUser tempUser;
    tempUser.addTask(newtask);

    // Temp labels

    ui->TaskNameT->setText(taskName);
    ui->TaskDeadlineT->setText(taskDeadline);
    ui->DoneBtnT->setFixedSize(151, 24);

}


// Temp Done button for task
void MainTaskScreen::on_DoneBtnT_clicked()
{
    ui->TaskNameT->setText("");
    ui->TaskDeadlineT->setText(" ");
    ui->DoneBtnT->setFixedSize(0, 0);

    ui->TaskDeadlineT2->setText(ui->lineEditDeadline->text());
    ui->TaskNameT2->setText(ui->lineEditTaskName->text());
    ui->CompletedT->setText("Completed");
}

