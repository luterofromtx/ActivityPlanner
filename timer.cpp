#include "timer.h"
#include "ui_timer.h"

Timer::Timer(QWidget *parent)
    : QDialog(parent) // Change QWidget to QDialog
    , ui(new Ui::Timer)
{
    ui->setupUi(this);
}

Timer::~Timer()
{
    delete ui;
}

// Slot for 1-minute timer button click
void Timer::on_oneminute_clicked()
{
    emit dataAvailable("1-minute timer started"); // Emit signal with relevant data
    accept(); // Close the dialog
}

// Slot for 10-minute timer button click
void Timer::on_tenminutes_clicked()
{
    emit dataAvailable("10-minute timer started"); // Emit signal with relevant data
    accept(); // Close the dialog
}

// Slot for 30-minute timer button click
void Timer::on_thirtyminutes_clicked()
{
    emit dataAvailable("30-minute timer started"); // Emit signal with relevant data
    accept(); // Close the dialog
}

// Slot for 45-minute timer button click
void Timer::on_fourtyfiveminutes_clicked()
{
    emit dataAvailable("45-minute timer started"); // Emit signal with relevant data
    accept(); // Close the dialog
}

// Slot for 1-hour timer button click
void Timer::on_onehour_clicked()
{
    emit dataAvailable("1-hour timer started"); // Emit signal with relevant data
    accept(); // Close the dialog
}

// Slot for 2-hour timer button click
void Timer::on_twohours_clicked()
{
    emit dataAvailable("2-hour timer started"); // Emit signal with relevant data
    accept(); // Close the dialog
}
