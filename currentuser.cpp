#include "currentuser.h"

CurrentUser::CurrentUser() {}

void CurrentUser::addTask(Task newTask)
{
    openTasks.append(newTask);
}

void CurrentUser::UpdateUser(QString username1, QVector<Task> openTasks1, QVector<Task> closedTasks1)
{
    username = username1;
    openTasks = openTasks1;
    closedTasks = closedTasks1;
}

QVector<Task>* CurrentUser::getTasks(int taskType) {
    if (taskType == 0) {
        return &openTasks;  // Assuming openTasks is a QVector<Task> member of CurrentUser
    } else if (taskType == 1) {
        return &closedTasks;  // Assuming closedTasks is also a QVector<Task> member
    }
    return nullptr;  // Return nullptr if taskType doesn't match expected values
}
