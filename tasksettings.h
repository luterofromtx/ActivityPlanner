#ifndef TASKSETTINGS_H
#define TASKSETTINGS_H

#include <QDebug> // Include for debugging
#include <QDialog>
#include <QString>

namespace Ui {
class TaskSettings;
}

class TaskSettings : public QDialog
{
    Q_OBJECT

public:
    explicit TaskSettings(QWidget *parent = nullptr);
    ~TaskSettings();

    // Getter methods to retrieve user input
    QString getTaskname() const;
    QString getTaskDeadline() const;
    QString getTaskDescription() const;
signals:
    void taskSaved(const QString &taskName,
                   const QString &taskDeadline,
                   const QString &taskDescription);

private slots:
    void on_SaveTaskSettingBtn_clicked(bool checked);
    void on_CloseTaskSettingBtn_clicked(bool checked);
    void on_Taskname_textEdited(const QString &arg1);
    void on_DateGiven_textEdited(const QString &arg1);
    void on_DescriptionLine_textEdited(const QString &arg1);
    void on_TimercheckBox_clicked(bool checked);

private:
    Ui::TaskSettings *ui;
};

#endif // TASKSETTINGS_H
