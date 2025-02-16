#include "currentuser.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
CurrentUser::CurrentUser() {}

// Add new task to user open tasks
void CurrentUser::addTask(Task newTask)
{
    openTasks.append(newTask);
    //printTable(openTasks);
}

// Add new task to completed task table
void CurrentUser::newCloseTask(Task newTask)
{
    closedTasks.append(newTask);
}

// Print all task names from vector
void CurrentUser::printTable(QVector<Task> taskTable)
{
    // Debug to print opentasks list
    for (int i = 0; i < taskTable.size(); ++i) {
        qDebug() << taskTable[i].getTaskname();
    }
}

// Complete task and move to closed tasks
void CurrentUser::closeTask(QString newTask)
{
    int taskToMove = findTask(openTasks, newTask);
    if (taskToMove != -1) { // Check if task exists
        // Add completed task to closed tasks list
        Task tempTask = openTasks[taskToMove];
        closedTasks.append(tempTask);

        // Create temp table to fill with opentasks without completed task
        QVector<Task> tempTable;
        int newTableIndex = 0;
        for (int i = 0; i < openTasks.size(); ++i) { // loop through all open tasks
            if (i != taskToMove) {
                tempTable.append(tempTask); // Fill new table with all but deleted value
            }
        }
        openTasks = tempTable; // Set open tasks table to table without deleted task
    }

    // Debug print for vectors
    qDebug() << "Open Tasks: ";
    printTable(openTasks);
    qDebug() << "Closed Tasks: ";
    printTable(closedTasks);
}

// Return index of task name from vecotr
int CurrentUser::findTask(QVector<Task> taskTable, QString taskToFind)
{
    bool hasReturned = false; // Check if value exists in table
    for (int i = 0; i < taskTable.size(); ++i) {
        QString taskInTable = taskTable[i].getTaskname(); // Task name from current table
        if (taskInTable == taskToFind) {                  // Name found in table return the index
            hasReturned = true;
            return i;
        }
    }
    if (hasReturned == false) { // Task name not found
        return -1;
    }
}

void CurrentUser::UpdateUser(QString username1, QVector<Task> openTasks1, QVector<Task> closedTasks1)
{
    username = username1;
    openTasks = openTasks1;
    closedTasks = closedTasks1;
}

QString CurrentUser::getUsername()
{
    return username;
}

void CurrentUser::setUsername(QString currentUsername)
{
    username = currentUsername;
}

void CurrentUser::clearOpenTasks()
{
    openTasks.clear();
}

void CurrentUser::clearClosedTasks()
{
    closedTasks.clear();
}

QVector<Task> CurrentUser::getTasks(int taskType)
{
    if (taskType == 0) {
        return openTasks; // Assuming openTasks is a QVector<Task> member of CurrentUser
    } else if (taskType == 1) {
        return closedTasks; // Assuming closedTasks is also a QVector<Task> member
    } else {
        return openTasks; // Return nullptr if taskType doesn't match expected values
    }
}
