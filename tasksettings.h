#ifndef TASKSETTINGS_H
#define TASKSETTINGS_H

#include <QDialog>

namespace Ui {
class TaskSettings;
}

class TaskSettings : public QDialog
{
    Q_OBJECT

public:
    explicit TaskSettings(QWidget *parent = nullptr);
    ~TaskSettings();

private slots:
    void on_CloseTaskBtn_clicked();

private:
    Ui::TaskSettings *ui;
};

#endif // TASKSETTINGS_H
