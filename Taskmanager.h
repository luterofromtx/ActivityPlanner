#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QCalendarWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

class TaskManager : public QMainWindow
{
    Q_OBJECT

public:
    TaskManager(QWidget *parent = nullptr);
    ~TaskManager();

private slots:
    void showTaskList();
    void addTask();

private:
    QLineEdit *taskNameInput;   // Input field for task name
    QCalendarWidget *calendar;  // Calendar for task deadlines
    QLabel *taskListLabel;      // Label to display the task list
    QPushButton *addTaskButton; // Button to add a task
};

#endif // TASKMANAGER_H
