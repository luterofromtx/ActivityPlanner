#ifndef MAINTASKSCREEN_H
#define MAINTASKSCREEN_H

#include <QDialog>
#include "tasksettings.h"
#include "notifications.h"
#include "datesettings.h"
#include "largecalendar.h"

// Predefine class to avoid recursive calling/inheritance from main.cpp
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

private:
    Ui::MainTaskScreen *ui;
    MainWindow *mainWindow; // Pointer to mainwindow so you can return
    TaskSettings *taskSettings; // Pointer to add new task ui
    Notifications *notifications; // Pointer to notficiation settings ui
    DateSettings *dateSettings; // Pointer to date settings ui
    LargeCalendar *largeCalendar; // Pointer to large calendar ui

};

#endif // MAINTASKSCREEN_H
