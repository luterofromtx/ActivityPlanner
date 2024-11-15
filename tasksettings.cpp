#include "tasksettings.h"
#include <QDebug>
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

void TaskSettings::on_SaveTaskSettingBtn_clicked(bool checked)
{
    QString taskName = ui->Taskname->text();
    QString taskDeadline = ui->DateGiven->text();
    QString taskDescription = ui->DescriptionLine->text();

    emit taskSaved(taskName, taskDeadline, taskDescription);

    accept();


}

QString TaskSettings::getTaskname() const
{
    // Return the text from the Taskname QLineEdit
    return ui->Taskname->text();
}

QString TaskSettings::getTaskDeadline() const
{
    return ui->DateGiven->text();
}

QString TaskSettings::getTaskDescription() const
{
    return ui->DescriptionLine->text();
}

void TaskSettings::on_CloseTaskSettingBtn_clicked(bool checked)
{
    // Logic for handling the close button click, if any
    qDebug() << "Close button clicked";
    close(); // Close the TaskSettings dialog
}

void TaskSettings::on_Taskname_textEdited(const QString &arg1)
{
    qDebug() << "Task name edited:" << arg1;
}

void TaskSettings::on_DateGiven_textEdited(const QString &arg1)
{
    // Logic for handling text editing in DateGiven field, if needed
    qDebug() << "Date given edited:" << arg1;
}

void TaskSettings::on_DescriptionLine_textEdited(const QString &arg1)
{
    // Logic for handling text editing in DateGiven field, if needed
    qDebug() << "Date given edited:" << arg1;
}
