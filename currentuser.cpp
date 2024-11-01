#include "currentuser.h"

CurrentUser::CurrentUser() {}

void CurrentUser::addTask(Task newTask)
{
    openTasks.append(newTask);
}
