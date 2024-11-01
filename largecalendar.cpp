
#include "largecalendar.h"
#include "ui_largecalendar.h"
#include "tasksettings.h"

LargeCalendar::LargeCalendar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LargeCalendar)
{
    ui->setupUi(this);
}

LargeCalendar::~LargeCalendar()
{
    delete ui;
}

// Close large calendar UI
void LargeCalendar::on_CloseBtn_clicked()
{
    hide();
}

// Open settings for double clicked date
void LargeCalendar::on_calendarWidget_activated(const QDate &date)
{

}
