#include "currentuser.h"

CurrentUser::CurrentUser() {}

void CurrentUser::addTask(Task newTask)
{
    openTasks.append(newTask);
}

void CurrentUser::UpdateUser(QString username1, QVector<Task> openTasks1, QVector<Task> closedTasks1) {

    username = username1;
    openTasks = openTasks1;
    closedTasks = closedTasks1;


}
