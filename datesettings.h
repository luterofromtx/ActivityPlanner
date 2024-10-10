#ifndef DATESETTINGS_H
#define DATESETTINGS_H

#include <QDialog>
#include "tasksettings.h"

namespace Ui {
class DateSettings;
}

class DateSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DateSettings(QWidget *parent = nullptr);
    ~DateSettings();

private slots:
    void on_CloseBtn_clicked();

    void on_AddTaskBtn_clicked();

private:
    Ui::DateSettings *ui;
    TaskSettings *taskSettings; // Pointer for adding new task ui
};

#endif // DATESETTINGS_H
