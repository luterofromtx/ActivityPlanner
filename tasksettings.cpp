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

void TaskSettings::on_CloseTaskBtn_clicked()
{
    hide();
}

