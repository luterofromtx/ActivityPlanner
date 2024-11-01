#ifndef MAINTASKSCREEN_H
#define MAINTASKSCREEN_H

#include <QDialog>
#include "tasksettings.h"
#include "largecalendar.h"
#include "notifications.h"

// Forward declaration of MainWindow to avoid circular dependency
class MainWindow;

namespace Ui {
class MainTaskScreen;
}

class MainTaskScreen : public QDialog
{
    Q_OBJECT

public:
    explicit MainTaskScreen(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~MainTaskScreen();

private slots:
    void on_LogoutBtn_clicked();
    void on_AddTaskSettingsBtn_clicked();
    void on_SettingsBtn_clicked();
    void on_calendarWidget_activated(const QDate &date);
    void on_OpenCalenderBtn_clicked();
    void on_QuickAddBtn_clicked();
    void on_DoneBtnT_clicked();
    void addTaskToChecklist(const QString &taskName, const QString &taskDeadline, const QString &taskDescription);


private:
    Ui::MainTaskScreen *ui;
    MainWindow *mainWindow;       // Pointer to MainWindow for navigation
    TaskSettings *taskSettings;   // Pointer to TaskSettings for task input
    Notifications *notifications; // Pointer to Notifications settings UI
    LargeCalendar *largeCalendar; // Pointer to LargeCalendar UI
};

#endif // MAINTASKSCREEN_H
