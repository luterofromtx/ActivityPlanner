#include "tasksettings.h"
#include "ui_tasksettings.h"

TaskSettings::TaskSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TaskSettings)
{
    ui->setupUi(this);
}

TaskSettings::~TaskSettings()
{
    delete ui;
}

// Close current new task settings
void TaskSettings::on_CloseTaskBtn_clicked()
{
    hide();
}
