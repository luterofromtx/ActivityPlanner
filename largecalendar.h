#ifndef LARGECALENDAR_H
#define LARGECALENDAR_H

#include <QDate>
#include <QDialog>
#include <QVector>
#include <QTextCharFormat>
#include "task.h"

namespace Ui {
class LargeCalendar;
}

class LargeCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit LargeCalendar(QVector<Task> tasks, QWidget *parent = nullptr);
    ~LargeCalendar();

signals:
    void dateSelected(const QDate &date);

private slots:
    void on_CloseBtn_clicked();
    void on_calendarWidget_activated(const QDate &date);

private:
    Ui::LargeCalendar *ui;    // Pointer to the UI object that handles the UI LargeCalendar

    QVector<Task> taskList;    // List of Task objects, representing tasks and their deadlines


    void updateCalendarTaskDisplay();     // Updates the calendar to  highlight dates

};

#endif // LARGECALENDAR_H
