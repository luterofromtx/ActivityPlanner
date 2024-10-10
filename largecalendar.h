#ifndef LARGECALENDAR_H
#define LARGECALENDAR_H

#include <QDialog>
#include "datesettings.h"

namespace Ui {
class LargeCalendar;
}

class LargeCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit LargeCalendar(QWidget *parent = nullptr);
    ~LargeCalendar();

private slots:
    void on_CloseBtn_clicked();

    void on_calendarWidget_activated(const QDate &date);

private:
    Ui::LargeCalendar *ui;
    DateSettings *dateSettings; // Pointer for date settings ui
};

#endif // LARGECALENDAR_H
