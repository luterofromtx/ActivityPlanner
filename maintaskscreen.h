#ifndef MAINTASKSCREEN_H
#define MAINTASKSCREEN_H

#include <QDialog>
#include "currentuser.h"
#include "largecalendar.h"
#include "notifications.h"
#include "tasksettings.h"


// Forward declaration of MainWindow to avoid circular dependency
class MainWindow;
class LargeCalendar;

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
    void on_ClearCompleted_clicked();
    void on_Completed_clicked();
    void on_LogoutBtn_clicked();
    void on_AddTaskSettingsBtn_clicked();
    void on_SettingsBtn_clicked();
    void on_OpenCalenderBtn_clicked();
    void on_QuickAddBtn_clicked();
    void addTaskToChecklist(const QString &taskName,
                            const QString &taskDeadline,
                            const QString &taskDescription);
    void UpdateMainUI();
    void showTasksForDate(const QDate &date);



private:
    Ui::MainTaskScreen *ui;
    MainWindow *mainWindow;       // Pointer to MainWindow for navigation
    TaskSettings *taskSettings;   // Pointer to TaskSettings for task input
    Notifications *notifications; // Pointer to Notifications settings UI
    LargeCalendar *largeCalendar; // Pointer to LargeCalendar UI
    int selectedRowForCompletion; // Track selected row in tableWidget for completion
    int selectedRowForClear;      // Track selected row in tableWidget_2 for clearing
};

#endif // MAINTASKSCREEN_H

