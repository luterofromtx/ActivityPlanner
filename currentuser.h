
#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <QDialog>
#include <QVector>
#include "task.h"

class CurrentUser : Task
{
public:

    CurrentUser();
    void UpdateUser(QString username1, QVector<Task> openTasks1, QVector<Task> closedTasks1);
    void addTask(Task newTask); // Add new task to openTasks
    void closeTask();
    QVector<Task> *getTasks(
        int vector);      // Access opentasks with 0 and closed tasks with 1 as vector value
    int size(int vector); // Return size of Qvector/array

private:
    QString username;
    QString password;
    QVector<Task> openTasks;
    QVector<Task> closedTasks;
};

#endif // CURRENTUSER_H
