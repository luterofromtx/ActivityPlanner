#ifndef LARGECALENDAR_H
#define LARGECALENDAR_H

#include <QDate>
#include <QDialog>
#include <QVector>
#include "task.h"

namespace Ui {
class LargeCalendar;
}

class LargeCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit LargeCalendar(QVector<Task> tasks,
                           QWidget *parent = nullptr); // Constructor that takes tasks and parent
    ~LargeCalendar();

signals:
    void dateSelected(const QDate &date); // Signal to emit when a date is selected

private slots:
    void on_CloseBtn_clicked();
    void on_calendarWidget_activated(const QDate &date);

private:
    Ui::LargeCalendar *ui;
    QVector<Task> taskList; // List of tasks
};

#endif // LARGECALENDAR_H
