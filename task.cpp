#include "task.h"

Task::Task() {}

Task::Task(const QString &name, const QString &desc, const QString &deadline)
    : taskname(name)
    , description(desc)
    , deadline(deadline)
{}

QString Task::getTaskname() const
{
    return taskname;
}

QString Task::getDescription() const
{
    return description;
}

QString Task::getDeadline() const
{
    return deadline;
}

void Task::setName(const QString &name)
{
    taskname = name;
}

void Task::setDescription(const QString &desc)
{
    description = desc;
}

void Task::setDeadline(const QString &deadline)
{
    this->deadline = deadline;
}
