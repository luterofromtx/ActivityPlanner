#include "maintaskscreen.h"
#include <QDebug>
#include "mainwindow.h"
#include "task.h"
#include "tasksettings.h"
#include "ui_maintaskscreen.h"

// Global `currentUser` instance that stores the current user's information
CurrentUser currentUser;  

// Updates the user's information in `currentUser` with new tasks
void UpdateUserMain(QString username, QVector<Task> openTasks, QVector<Task> closedTasks)
{
    currentUser.UpdateUser(username, openTasks, closedTasks);  // Update `currentUser` data
}

// Constructor for MainTaskScreen: sets up UI, initializes table headers and columns
MainTaskScreen::MainTaskScreen(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainTaskScreen)
    , mainWindow(mainWindow)
{
    ui->setupUi(this);  // Sets up the main UI
    // Initialize the main task table with 3 columns: Task Name, Deadline, Description
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");
}

// Logs out and returns to the main window
void MainTaskScreen::on_LogoutBtn_clicked()
{
    hide();  // Hides the task screen
    mainWindow->show();  // Shows the main window (log-in screen)
}

// Opens the TaskSettings dialog to add a new task
void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    taskSettings = new TaskSettings(this);

    // Connects the `taskSaved` signal from `TaskSettings` to `addTaskToChecklist`
    connect(taskSettings,
            &TaskSettings::taskSaved,
            this,
            &MainTaskScreen::addTaskToChecklist,
            Qt::UniqueConnection);

    // Executes the TaskSettings dialog (blocks other interactions until this closes)
    taskSettings->exec();
}

// Adds a task to the checklist table in the UI
void MainTaskScreen::addTaskToChecklist(const QString &taskName, const QString &taskDeadline, const QString &taskDescription)
{
    int rowCount = ui->tableWidget->rowCount();  // Gets the current number of rows in the table
    ui->tableWidget->insertRow(rowCount);  // Inserts a new row at the end of the table

    // Creates new table items for each task field
    QTableWidgetItem *taskNameItem = new QTableWidgetItem(taskName);
    QTableWidgetItem *taskDeadlineItem = new QTableWidgetItem(taskDeadline);
    QTableWidgetItem *taskDescriptionItem = new QTableWidgetItem(taskDescription);

    // Adds the items to the row at the respective columns
    ui->tableWidget->setItem(rowCount, 0, taskNameItem);
    ui->tableWidget->setItem(rowCount, 1, taskDeadlineItem);
    ui->tableWidget->setItem(rowCount, 2, taskDescriptionItem);

    // Aligns text to top-left in each cell for readability
    taskNameItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
    taskDeadlineItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
    taskDescriptionItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);

    // Debugging: Logs the task added to the console
    qDebug() << "Task added to checklist: Name =" << taskName << ", Deadline =" << taskDeadline
             << ", Description =" << taskDescription;
}

// Quick add button for adding a task with minimal input
void MainTaskScreen::on_QuickAddBtn_clicked()
{
    // Get task details from input fields
    QString taskName = ui->lineEditTaskName->text();
    QString taskDeadline = ui->lineEditDeadline->text();
    QString taskDescription = ui->lineEditDesc->text();

    // Displays the task details in the preview section
    ui->TaskNameT->setText(taskName);
    ui->TaskDeadlineT->setText(taskDeadline);

    // Creates a new Task and adds it to the current user's open tasks
    Task newTask(taskName, taskDescription, taskDeadline);  // New task created with user input
    currentUser.addTask(newTask);  // Adds new task to user's open tasks vector
}

// Opens notifications settings dialog
void MainTaskScreen::on_SettingsBtn_clicked()
{
    notifications = new Notifications(this);  // Creates a new Notifications dialog
    notifications->show();  // Shows the notifications dialog on top of the task screen
}

// Opens a large calendar view (specific functionality not implemented here)
void MainTaskScreen::on_OpenCalenderBtn_clicked()
{
    largeCalendar = new LargeCalendar(this);  // Creates a new LargeCalendar dialog
    largeCalendar->show();  // Shows the large calendar dialog
}

// Event that triggers when a calendar date is activated (open-ended for future logic)
void MainTaskScreen::on_calendarWidget_activated(const QDate &date)
{
    // Placeholder for interacting with calendar events
}

// Marks a task as done by clearing the temporary input fields in the UI
void MainTaskScreen::on_DoneBtnT_clicked()
{
    ui->TaskNameT->clear();  // Clears the task name field
    ui->TaskDeadlineT->clear();  // Clears the deadline field
    ui->CompletedT->setText("Completed");  // Sets a status message as "Completed"

    // Retrieves tasks from current user (specific completion logic not implemented)
    QString taskName;
    QVector<Task> *openTable = currentUser.getTasks(0);  // Open tasks
    QVector<Task> *closedTable = currentUser.getTasks(1);  // Closed tasks
}

// Placeholder function for updating task UI (currently empty)
void UpdateTaskUI()
{
    QVector<Task> openTasks;  // Vector to hold open tasks
    QVector<Task> closedTasks;  // Vector to hold closed tasks

    for (int i = 0; i < openTasks.size(); ++i) {
        // Logic to update open tasks in the UI would go here
    }
    for (int i = 0; i < closedTasks.size(); ++i) {
        // Logic to update closed tasks in the UI would go here
    }
}

// Destructor for MainTaskScreen (handles cleanup)
MainTaskScreen::~MainTaskScreen()
{
    delete ui;  // Frees up memory used by the UI components
}
