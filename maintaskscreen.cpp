#include "maintaskscreen.h"
#include <QDebug>
#include "mainwindow.h"
#include "task.h"
#include "tasksettings.h"
#include "ui_maintaskscreen.h"

// Global object for storing current user details
CurrentUser currentUser;

// Updates current user’s main info with open and closed tasks
void UpdateUserMain(QString username, QVector<Task> openTasks, QVector<Task> closedTasks)
{
    // Updates user data in `currentUser`
    currentUser.UpdateUser(username, openTasks, closedTasks);
}

// Constructor for MainTaskScreen, setting up UI and connections
MainTaskScreen::MainTaskScreen(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainTaskScreen)
    , mainWindow(mainWindow)
    , selectedRowForCompletion(-1) // Initialize as -1 to mean "no row selected"
    , selectedRowForClear(-1)      // Same for clear row
{
    ui->setupUi(this);

    // Set up the task table (tableWidget) with 3 columns
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");

    // Set up completed task table (tableWidget_2) with 3 columns
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");

    // Connect Completed button click to `on_Completed_clicked` function
    connect(ui->Completed, &QPushButton::clicked, this, &MainTaskScreen::on_Completed_clicked, Qt::UniqueConnection);

    // Connect ClearCompleted button click to `on_ClearCompleted_clicked` function
    connect(ui->ClearCompleted, &QPushButton::clicked, this, &MainTaskScreen::on_ClearCompleted_clicked, Qt::UniqueConnection);

    // Track selected row in tableWidget (tasks) when a row is clicked
    connect(ui->tableWidget, &QTableWidget::itemClicked, this, [=](QTableWidgetItem *item) {
        selectedRowForCompletion = item->row(); // Store selected row for completion action
        qDebug() << "Selected row for completion updated to:" << selectedRowForCompletion;
    });

    // Track selected row in tableWidget_2 (completed tasks) when a row is clicked
    connect(ui->tableWidget_2, &QTableWidget::itemClicked, this, [=](QTableWidgetItem *item) {
        selectedRowForClear = item->row(); // Store selected row for clearing action
        qDebug() << "Selected row for clearing updated to:" << selectedRowForClear;
    });

    // Disable sorting to keep rows in manual order
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget_2->setSortingEnabled(false);
}

// Handles logout button click to close the screen and show main window
void MainTaskScreen::on_LogoutBtn_clicked()
{
    hide(); // Hide current screen
    mainWindow->show(); // Show main window
}

// Handles AddTask button to open TaskSettings dialog for adding new tasks
void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    taskSettings = new TaskSettings(this);
    // When task is saved, call `addTaskToChecklist`
    connect(taskSettings, &TaskSettings::taskSaved, this, &MainTaskScreen::addTaskToChecklist, Qt::UniqueConnection);
    taskSettings->exec(); // Open task settings dialog
}

// Adds task details to tableWidget (task list) at the top
void MainTaskScreen::addTaskToChecklist(const QString &taskName, const QString &taskDeadline, const QString &taskDescription)
{
    ui->tableWidget->insertRow(0); // Add new row at the top
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(taskName.isEmpty() ? "Unnamed Task" : taskName));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(taskDeadline.isEmpty() ? "No deadline" : taskDeadline));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(taskDescription.isEmpty() ? "No description" : taskDescription));
    qDebug() << "Task added to checklist: Name =" << taskName << ", Deadline =" << taskDeadline << ", Description =" << taskDescription;
}

// Adds a quick task from input fields and clears inputs after adding
void MainTaskScreen::on_QuickAddBtn_clicked()
{
    QString taskName = ui->lineEditTaskName->text();
    QString taskDeadline = ui->lineEditDeadline->text();
    QString taskDescription = ui->lineEditDesc->text();
    addTaskToChecklist(taskName, taskDeadline, taskDescription); // Add task
    // Clear input fields for new entries
    ui->lineEditTaskName->clear();
    ui->lineEditDeadline->clear();
    ui->lineEditDesc->clear();
}

// Opens settings dialog for notifications
void MainTaskScreen::on_SettingsBtn_clicked()
{
    notifications = new Notifications(this);
    notifications->show(); // Show notifications settings
}

// Clears the selected row in completed tasks (tableWidget_2)
void MainTaskScreen::on_ClearCompleted_clicked()
{
    if (selectedRowForClear == -1) {
        qDebug() << "No completed task selected to clear.";
        return;
    }
    // Remove the selected row from completed tasks
    ui->tableWidget_2->removeRow(selectedRowForClear);
    qDebug() << "Cleared row " << selectedRowForClear << " from completed tasks (tableWidget_2).";
    selectedRowForClear = -1; // Reset selection
}

// Moves a selected task to the completed list (tableWidget_2) and removes from main task list
void MainTaskScreen::on_Completed_clicked()
{
    if (selectedRowForCompletion == -1) {
        qDebug() << "No task selected to mark as complete.";
        return;
    }
    // Get task details from selected row in tableWidget
    QTableWidgetItem *taskNameItem = ui->tableWidget->item(selectedRowForCompletion, 0);
    QTableWidgetItem *taskDeadlineItem = ui->tableWidget->item(selectedRowForCompletion, 1);
    QTableWidgetItem *taskDescriptionItem = ui->tableWidget->item(selectedRowForCompletion, 2);

    // Check if task name exists, otherwise don't move it
    if (!taskNameItem || taskNameItem->text().isEmpty()) {
        qDebug() << "Task Name is required to mark a task as complete. Task not moved.";
        return;
    }

    // Get values from selected row with default text if empty
    QString taskName = taskNameItem->text();
    QString taskDeadline = taskDeadlineItem && !taskDeadlineItem->text().isEmpty() ? taskDeadlineItem->text() : "No deadline";
    QString taskDescription = taskDescriptionItem && !taskDescriptionItem->text().isEmpty() ? taskDescriptionItem->text() : "No description";

    // Insert the task at the top of completed tasks (tableWidget_2)
    ui->tableWidget_2->insertRow(0);
    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem(taskName));
    ui->tableWidget_2->setItem(0, 1, new QTableWidgetItem(taskDeadline));
    ui->tableWidget_2->setItem(0, 2, new QTableWidgetItem(taskDescription));
    qDebug() << "Task moved to completed table: Name =" << taskName << ", Deadline =" << taskDeadline << ", Description =" << taskDescription;

    // Remove the task from the main task list and reset selection
    ui->tableWidget->removeRow(selectedRowForCompletion);
    selectedRowForCompletion = -1;
}

// Function triggered when a date is selected on the calendar widget
void MainTaskScreen::on_calendarWidget_activated(const QDate &date)
{
    // Interaction code if any for calendar
}

// Opens the large calendar dialog
void MainTaskScreen::on_OpenCalenderBtn_clicked()
{
    largeCalendar = new LargeCalendar(this);
    largeCalendar->show();
}

// Function to handle updates to task UI (not used here)
void UpdateTaskUI()
{
    QVector<Task> openTasks;
    for (int i = 0; i < openTasks.size(); ++i) {}
    QVector<Task> closedTasks;
    for (int i = 0; i < closedTasks.size(); ++i) {}
}

// Destructor for MainTaskScreen, called when the screen is closed
MainTaskScreen::~MainTaskScreen()
{
    delete ui;
}

