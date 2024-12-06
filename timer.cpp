#include "timer.h"
#include "ui_timer.h"

Timer::Timer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Timer)
    , timer(new QTimer(this))
    , remainingTime(0)
{
    ui->setupUi(this);

    // Connect the QTimer's timeout signal to the updateLCD function
    connect(timer, &QTimer::timeout, this, &Timer::updateLCD);

    // Connect Reset and OK buttons to their respective slots
    connect(ui->cancelbutton, &QPushButton::clicked, this, &Timer::on_resetButton_clicked);
    connect(ui->okbutton, &QPushButton::clicked, this, &Timer::on_okButton_clicked);
}

Timer::~Timer()
{
    delete ui;
}

// Function to reset the timer
void Timer::resetTimer()
{
    remainingTime = 0;              // Reset remaining time to zero
    ui->lcdNumber->display("00:00"); // Display "00:00" on the LCD
    timer->stop();                  // Stop the timer if it's running
}

// Slot for Reset (Cancel) button
void Timer::on_resetButton_clicked()
{
    resetTimer(); // Reset the timer
    emit dataAvailable("Timer reset to 00:00!"); // Notify parent about the reset
}

// Slot for OK button
void Timer::on_okButton_clicked()
{
    emit dataAvailable("Timer confirmed with OK button");
    accept(); // Close the dialog with QDialog::Accepted
}

// Slot for 1-minute timer button
void Timer::on_oneminute_clicked()
{
    remainingTime = 60; // 1 minute = 60 seconds
    emit dataAvailable("1-minute timer started");
    timer->start(1000); // Start the timer with a 1-second interval
    updateLCD();        // Immediately update the LCD display
}

// Slot for 10-minute timer button
void Timer::on_tenminutes_clicked()
{
    remainingTime = 600; // 10 minutes = 600 seconds
    emit dataAvailable("10-minute timer started");
    timer->start(1000);
    updateLCD();
}

// Slot for 30-minute timer button
void Timer::on_thirtyminutes_clicked()
{
    remainingTime = 1800; // 30 minutes = 1800 seconds
    emit dataAvailable("30-minute timer started");
    timer->start(1000);
    updateLCD();
}

// Slot for 45-minute timer button
void Timer::on_fourtyfiveminutes_clicked()
{
    remainingTime = 2700; // 45 minutes = 2700 seconds
    emit dataAvailable("45-minute timer started");
    timer->start(1000);
    updateLCD();
}

// Slot for 1-hour timer button
void Timer::on_onehour_clicked()
{
    remainingTime = 3600; // 1 hour = 3600 seconds
    emit dataAvailable("1-hour timer started");
    timer->start(1000);
    updateLCD();
}

// Slot for 2-hour timer button
void Timer::on_twohours_clicked()
{
    remainingTime = 7200; // 2 hours = 7200 seconds
    emit dataAvailable("2-hour timer started");
    timer->start(1000);
    updateLCD();
}

// Function to update the LCD display
void Timer::updateLCD()
{
    if (remainingTime <= 0) {
        timer->stop(); // Stop the timer when countdown reaches 0
        ui->lcdNumber->display("00:00"); // Display "00:00" on the LCD
        emit dataAvailable("Timer completed!"); // Notify the parent widget
        return;
    }

    // Convert remaining time to minutes and seconds
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;

    // Display the time in MM:SS format on the LCD
    ui->lcdNumber->display(QString("%1:%2")
                               .arg(minutes, 2, 10, QChar('0'))
                               .arg(seconds, 2, 10, QChar('0')));

    remainingTime--; // Decrement the remaining time by 1 second
}
