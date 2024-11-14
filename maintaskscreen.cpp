#include "maintaskscreen.h"
#include <QDebug>
#include <QMessageBox>
#include "largecalendar.h" // Include LargeCalendar for managing larger calendar view
#include "mainwindow.h"     // Include MainWindow for navigation purposes
#include "task.h"           // Include Task class for managing task details
#include "tasksettings.h"   // Include TaskSettings for managing task input and editing
#include "ui_maintaskscreen.h"  // Include the UI elements of MainTaskScreen

CurrentUser currentUser;  // Global instance of CurrentUser to manage user tasks

// Update user information and tasks
void UpdateUserMain(QString username, QVector<Task> openTasks, QVector<Task> closedTasks)
{
    // Assign tasks to the current user instance
    currentUser.UpdateUser(username, openTasks, closedTasks);
}

// Refresh the UI to display current tasks
void MainTaskScreen::UpdateMainUI()
{
    // Retrieve lists of open and closed tasks from currentUser
    QVector<Task> openTasks = currentUser.getTasks(0);
    QVector<Task> closedTasks = currentUser.getTasks(1);

    // Loop through each open task and display it in the main checklist
    for (const Task &task : openTasks) {
        addTaskToChecklist(task.getTaskname(), task.getDeadline(), task.getDescription());
    }

    // Loop through each closed task and display it in the completed tasks table
    for (const Task &task : closedTasks) {
        int row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(task.getTaskname()));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(task.getDeadline()));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(task.getDescription()));
    }
}

// Constructor for MainTaskScreen
MainTaskScreen::MainTaskScreen(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainTaskScreen)
    , mainWindow(mainWindow)
    , selectedRowForCompletion(-1) // Initialize with no row selected for completion
    , selectedRowForClear(-1)      // Initialize with no row selected for clearing
{
    ui->setupUi(this);

    // Set up columns for task information in both the main task table and completed task table
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");

    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");

    // Connect task completion and clear completion buttons to their respective slots
    connect(ui->Completed, &QPushButton::clicked, this, &MainTaskScreen::on_Completed_clicked, Qt::UniqueConnection);
    connect(ui->ClearCompleted, &QPushButton::clicked, this, &MainTaskScreen::on_ClearCompleted_clicked, Qt::UniqueConnection);

    // Capture row selected for completion in main task table
    connect(ui->tableWidget, &QTableWidget::itemClicked, this, [=](QTableWidgetItem *item) {
        selectedRowForCompletion = item->row();
        qDebug() << "Selected row for completion updated to:" << selectedRowForCompletion;
    });

    // Capture row selected for clearing in completed task table
    connect(ui->tableWidget_2, &QTableWidget::itemClicked, this, [=](QTableWidgetItem *item) {
        selectedRowForClear = item->row();
        qDebug() << "Selected row for clearing updated to:" << selectedRowForClear;
    });

    // Disable sorting to maintain custom order for both task tables
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget_2->setSortingEnabled(false);
}

// Slot to handle logout button click
void MainTaskScreen::on_LogoutBtn_clicked()
{
    hide();              // Hide MainTaskScreen
    mainWindow->show();  // Show MainWindow for logout navigation
}

// Slot to open the task settings window
void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    taskSettings = new TaskSettings(this);
    // Connect taskSettings to update the checklist when a task is saved
    connect(taskSettings, &TaskSettings::taskSaved, this, &MainTaskScreen::addTaskToChecklist, Qt::UniqueConnection);
    taskSettings->exec(); // Open the TaskSettings dialog as a modal
}

// Add a task to the main checklist display
void MainTaskScreen::addTaskToChecklist(const QString &taskName, const QString &taskDeadline, const QString &taskDescription)
{
    // Insert a new row at the top of the main task table
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(taskName.isEmpty() ? "Unnamed Task" : taskName));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(taskDeadline.isEmpty() ? "No deadline" : taskDeadline));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(taskDescription.isEmpty() ? "No description" : taskDescription));

    qDebug() << "Task added to checklist: Name =" << taskName << ", Deadline =" << taskDeadline << ", Description =" << taskDescription;
}

// Handle quick add task button click
void MainTaskScreen::on_QuickAddBtn_clicked()
{
    // Retrieve new task details from quick add input fields
    QString taskName = ui->lineEditTaskName->text();
    QString taskDeadline = ui->lineEditDeadline->text();
    QString taskDescription = ui->lineEditDesc->text();

    addTaskToChecklist(taskName, taskDeadline, taskDescription); // Add to checklist

    // Create new Task and add it to current user's task list
    Task newTask(taskName, taskDescription, taskDeadline);
    currentUser.addTask(newTask);

    // Clear input fields after adding the task
    ui->lineEditTaskName->clear();
    ui->lineEditDeadline->clear();
    ui->lineEditDesc->clear();
}

// Open notifications settings dialog
void MainTaskScreen::on_SettingsBtn_clicked()
{
    notifications = new Notifications(this);
    notifications->show();
}

// Handle clearing a selected completed task
void MainTaskScreen::on_ClearCompleted_clicked()
{
    if (selectedRowForClear == -1) {
        qDebug() << "No completed task selected to clear.";
        return;
    }

    // Remove selected row from the completed tasks table
    ui->tableWidget_2->removeRow(selectedRowForClear);
    qDebug() << "Cleared row " << selectedRowForClear << " from completed tasks.";

    // Reset the selected row for clearing
    selectedRowForClear = -1;
}

// Mark a task as completed and move it to completed tasks table
void MainTaskScreen::on_Completed_clicked()
{
    if (selectedRowForCompletion == -1) {
        qDebug() << "No task selected to mark as complete.";
        return;
    }

    // Retrieve task details from selected row
    QTableWidgetItem *taskNameItem = ui->tableWidget->item(selectedRowForCompletion, 0);
    QTableWidgetItem *taskDeadlineItem = ui->tableWidget->item(selectedRowForCompletion, 1);
    QTableWidgetItem *taskDescriptionItem = ui->tableWidget->item(selectedRowForCompletion, 2);

    if (!taskNameItem || taskNameItem->text().isEmpty()) {
        qDebug() << "Task Name is required to mark a task as complete. Task not moved.";
        return;
    }

    QString taskName = taskNameItem->text();
    QString taskDeadline = taskDeadlineItem && !taskDeadlineItem->text().isEmpty() ? taskDeadlineItem->text() : "No deadline";
    QString taskDescription = taskDescriptionItem && !taskDescriptionItem->text().isEmpty() ? taskDescriptionItem->text() : "No description";

    // Move task from open to completed for current user
    currentUser.closeTask(taskName);

    // Add task details to completed tasks table
    ui->tableWidget_2->insertRow(0);
    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem(taskName));
    ui->tableWidget_2->setItem(0, 1, new QTableWidgetItem(taskDeadline));
    ui->tableWidget_2->setItem(0, 2, new QTableWidgetItem(taskDescription));

    qDebug() << "Task moved to completed: Name =" << taskName << ", Deadline =" << taskDeadline << ", Description =" << taskDescription;

    // Remove the task from open tasks table
    ui->tableWidget->removeRow(selectedRowForCompletion);

    // Reset selection after marking as complete
    selectedRowForCompletion = -1;
}

// Display tasks on a specific date selected in the calendar
void MainTaskScreen::on_calendarWidget_activated(const QDate &date)
{
    static bool processing = false;
    if (processing)
        return; // Avoid repeated calls while processing

    processing = true; // Set guard to prevent multiple triggers

    QString selectedDate = date.toString("yyyy-MM-dd");
    qDebug() << "Selected date:" << selectedDate;

    // Retrieve all open tasks
    QVector<Task> tasks = currentUser.getTasks(0);

    // Gather tasks that match the selected date
    QString taskDetails;
    for (const Task &task : tasks) {
        if (task.getDeadline() == selectedDate) {
            taskDetails += QString("Task: %1\nDescription: %2\n\n").arg(task.getTaskname()).arg(task.getDescription());
        }
    }

    if (taskDetails.isEmpty()) {
        taskDetails = "No tasks for this date.";
    }

    // Show tasks for the selected date
    QMessageBox::information(this, "Tasks for " + selectedDate, taskDetails);
    processing = false; // Reset guard
}

// Slot to display tasks for a date selected in LargeCalendar
void MainTaskScreen::showTasksForDate(const QDate &date)
{
    QString selectedDate = date.toString("yyyy-MM-dd");
    QVector<Task> tasks = currentUser.getTasks(0);

    QString taskDetails;
    for (const Task &task : tasks) {
        if (task.getDeadline() == selectedDate) {
            taskDetails += QString("Task: %1\nDescription: %2\n\n").arg(task.getTaskname()).arg(task.getDescription());
        }
    }
    if (taskDetails.isEmpty()) {
        taskDetails = "No tasks for this date.";
    }
}

// Slot to open LargeCalendar and connect date selection to showTasksForDate
void MainTaskScreen::on_OpenCalendarBtn_clicked()
{
    QVector<Task> tasks = currentUser.getTasks(0);  // Grab open tasks for display
    largeCalendar = new LargeCalendar(tasks, this); // Initialize LargeCalendar with tasks

    // Connect LargeCalendar's date selection to showTasksForDate
    connect(largeCalendar, &LargeCalendar::dateSelected, this, &MainTaskScreen::showTasksForDate);

    largeCalendar->show(); // Display the LargeCalendar
}

// Destructor for MainTaskScreen
MainTaskScreen::~MainTaskScreen()
{
    delete ui;           // Clean up UI elements
    delete largeCalendar; // Ensure LargeCalendar is deleted
}

