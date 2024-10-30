#include "task.h"

Task::Task() {}


// Constructor for quick add
Task::Task(QString name, QString desc, QString dead) {
    taskname = name;
    description = desc;
    deadline = dead;

}

QString Task::GetName() {
    return taskname;
}

QString Task::GetDescription() {
    return description;
}

QString Task::GetDeadline() {
    return deadline;
}
