#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Timer;
}

class Timer : public QDialog
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

signals:
    void dataAvailable(const QString &data); // Signal to notify parent widget

private slots:
    void on_oneminute_clicked();
    void on_tenminutes_clicked();
    void on_thirtyminutes_clicked();
    void on_fourtyfiveminutes_clicked();
    void on_onehour_clicked();
    void on_twohours_clicked();
    void updateLCD();              // Updates the LCD display with remaining time
    void on_resetButton_clicked(); // Slot for Cancel/Reset button
    void on_okButton_clicked();    // Slot for OK button
    void resetTimer();             // Function to reset the timer

private:
    Ui::Timer *ui;
    QTimer *timer;        // Timer for the countdown
    int remainingTime;    // Remaining time in seconds
};

#endif // TIMER_H

