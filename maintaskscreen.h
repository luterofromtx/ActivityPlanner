#ifndef MAINTASKSCREEN_H
#define MAINTASKSCREEN_H

#include <QDialog>
#include "currentuser.h"
#include "largecalendar.h"
#include "tasksettings.h"
#include "timer.h"

// Forward declaration of MainWindow to avoid circular dependency
class MainWindow;
class LargeCalendar;
class timer;

namespace Ui {
class MainTaskScreen;
}

class MainTaskScreen : public QDialog
{
    Q_OBJECT

public:
    explicit MainTaskScreen(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~MainTaskScreen();

    void setupUser(QString username); /*This allows you to carry the variable used at log in
                                        over to maintaskscreen.cpp and then assign it to currentUser*/
    void printCurrentUserTasks();
    // ...

private slots:
    void on_ClearCompleted_clicked();
    void on_Completed_clicked();
    void on_LogoutBtn_clicked();
    void on_AddTaskSettingsBtn_clicked();
    void on_SettingsBtn_clicked();
    void on_OpenCalenderBtn_clicked();
    void on_calendarWidget_activated(const QDate &date);
    void on_QuickAddBtn_clicked();
    void addTaskToChecklist(const QString &taskName,
                            const QString &taskDeadline,
                            const QString &taskDescription);
    void addTaskToCompleted(const QString &taskName,
                            const QString &taskDeadline,
                            const QString &taskDescription);
    void UpdateMainUI();
    void showTasksForDate(const QDate &date);

    void on_ClearAllTask_clicked();

    void on_CompleteAllTask_clicked();

    void on_OpenCalBtn_clicked();

    void on_Timer_clicked();

signals:
    void dateSelected(const QDate &date); // Signal to emit when a date is selected

private:
    Ui::MainTaskScreen *ui;
    MainWindow *mainWindow;       // Pointer to MainWindow for navigation
    TaskSettings *taskSettings;   // Pointer to TaskSettings for task input
    LargeCalendar *largeCalendar; // Pointer to LargeCalendar UI
    int selectedRowForCompletion; // Track selected row in tableWidget for completion
    int selectedRowForClear;      // Track selected row in tableWidget_2 for clearing
    QVector<Task> taskList;       // List of tasks
    Timer *myTimer = nullptr; // Pointer to the timer, initialized to nullptr


};


#endif // MAINTASKSCREEN_H
