#include "taskmanager.h"

TaskManager::TaskManager(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the main layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create input for task name
    taskNameInput = new QLineEdit(this);
    taskNameInput->setPlaceholderText("Enter task name");
    layout->addWidget(taskNameInput);

    // Create a calendar widget for selecting the task deadline
    calendar = new QCalendarWidget(this);
    layout->addWidget(calendar);

    // Create a button to add the task
    addTaskButton = new QPushButton("Add Task", this);
    connect(addTaskButton, &QPushButton::clicked, this, &TaskManager::addTask);
    layout->addWidget(addTaskButton);

    // Create a label to display the task list
    taskListLabel = new QLabel("No tasks available.", this);
    layout->addWidget(taskListLabel);

    // Set the main layout
    setCentralWidget(centralWidget);
}

TaskManager::~TaskManager() {}

void TaskManager::addTask()
{
    QString taskName = taskNameInput->text();
    QString deadline = calendar->selectedDate().toString("yyyy-MM-dd");

    if (!taskName.isEmpty()) {
        // Append task name and deadline to the task list label
        QString currentTasks = taskListLabel->text();
        if (currentTasks == "No tasks available.") {
            currentTasks.clear();
        }
        currentTasks += taskName + " - Due: " + deadline + "\n";
        taskListLabel->setText(currentTasks);

        // Clear the input field after adding
        taskNameInput->clear();
    }
}
