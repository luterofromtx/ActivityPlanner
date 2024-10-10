#include "datesettings.h"
#include "ui_datesettings.h"

DateSettings::DateSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DateSettings)
{
    ui->setupUi(this);
}

DateSettings::~DateSettings()
{
    delete ui;
}

// Close Date Settings
void DateSettings::on_CloseBtn_clicked()
{
    hide();
}

// Add new task button
void DateSettings::on_AddTaskBtn_clicked()
{
    // Show add new task ui
    taskSettings = new TaskSettings(this);
    taskSettings->show();
}

