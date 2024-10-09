#ifndef MAINTASKSCREEN_H
#define MAINTASKSCREEN_H

#include <QDialog>
#include "tasksettings.h"

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

private:
    Ui::MainTaskScreen *ui;
    MainWindow *mainWindow; // Pointer to mainwindow so you can return
    TaskSettings *taskSettings;
};

#endif // MAINTASKSCREEN_H
