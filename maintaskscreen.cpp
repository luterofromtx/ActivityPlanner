#include "maintaskscreen.h"
#include <QDebug>
#include <QFile>
#include <QLineEdit>          // For handling QLineEdit input
#include <QMessageBox>        // For displaying validation warnings
#include <QRegularExpression> // For modern regex handling
#include "currentuser.h"
#include "largecalendar.h"
#include "mainwindow.h"
#include "task.h"
#include "tasksettings.h"
#include "ui_maintaskscreen.h"

CurrentUser currentUser; // Global instance of CurrentUser to manage user tasks

//When user logs in, use username typed in to set to current user
void MainTaskScreen::setupUser(QString username)
{
    currentUser.setUsername(username);
}

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

    //Print the username next to UserLabel that says "User: "
    ui->UserLabel->setText("User: " + currentUser.getUsername());

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
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               << "Task Name" << "Deadline" << "Description");


    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()
                                                 << "Task Name" << "Deadline" << "Description");

    // Connect task completion and clear completion buttons to their respective slots
    connect(ui->Completed,
            &QPushButton::clicked,
            this,
            &MainTaskScreen::on_Completed_clicked,
            Qt::UniqueConnection);
    connect(ui->ClearCompleted,
            &QPushButton::clicked,
            this,
            &MainTaskScreen::on_ClearCompleted_clicked,
            Qt::UniqueConnection);

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

void MainTaskScreen::printCurrentUserTasks() //Appends values to QVector<Task> openTasks to then be printed
{
    qDebug() << "Access this right now";
    QString openTasksFile = "./Users/" + currentUser.getUsername() + "/" + currentUser.getUsername()
                            + "OpenTasks.txt";
    QFile file(openTasksFile);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Open Tasks file could not be opened.";
    } else {
        Task newTask;
        QTextStream Stream(&file);
        while (!Stream.atEnd()) {
            QString LineData = Stream.readLine();
            QStringList Data = LineData.split(",");
            newTask.setName(Data[0]);
            newTask.setDescription(Data[1]);
            newTask.setDeadline(Data[2]);
            currentUser.addTask(newTask);
        }
    }
    file.close();

    QString closedTasksFile = "./Users/" + currentUser.getUsername() + "/"
                              + currentUser.getUsername() + "ClosedTasks.txt";
    file.setFileName(closedTasksFile);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Open Tasks file could not be opened.";
    } else {
        Task newTask;
        QTextStream Stream(&file);
        while (!Stream.atEnd()) {
            QString LineData = Stream.readLine();
            QStringList Data = LineData.split(",");
            newTask.setName(Data[0]);
            newTask.setDescription(Data[1]);
            newTask.setDeadline(Data[2]);
            currentUser.newCloseTask(newTask);
        }
    }
    file.close();

    // Filled task vectors for currentUser
    QVector<Task> gay;
    QVector<Task> open = currentUser.getTasks(0);
    QVector<Task> closed = currentUser.getTasks(1);

    // Fill openTasks
    for (int i = 0; i < open.size(); ++i) {
        gay.append(open[i]);
    }

    // Fill closedTasks
    for (int i = 0; i < closed.size(); ++i) {
        gay.append(closed[i]);
    }

    // Print open tasks
    for (int i = 0; i < gay.size(); i++) {
        qDebug() << gay[i].getTaskname() << "  " << gay[i].getDescription() << "  "
                 << gay[i].getDeadline();
    }

    // Update mainTaskScreenUI
    UpdateMainUI();
}

// Slot to handle logout button click
void MainTaskScreen::on_LogoutBtn_clicked() //Write to the current user's OpenTasks file when logging out
{
    qDebug() << "Logout button clicked.";
    QString openTasksFile = "./Users/" + currentUser.getUsername() + "/" + currentUser.getUsername()
                            + "OpenTasks.txt"; //This is the path to the file being written
    QFile file(openTasksFile);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Open Tasks file could not be opened.";
    } else {
        qDebug() << openTasksFile << " opened successfully.";

        //Empty the file first so updated list can be added without duplicating tasks
        file.resize(0);
        qDebug() << openTasksFile << " emptied successfully.";

        //Now add stuff to it
        QVector<Task> currentOpenTasks = currentUser.getTasks(
            0); //Accesses private member openTasks publicly through new vector currentOpenTasks
        QTextStream stream(&file);
        for (int i = 0; i < currentOpenTasks.size(); i++) {
            //from i=0 til there are no more tasks, write these at i's current value
            //each task is written separated by a comma, then at the end a new line
            stream << currentOpenTasks[i].getTaskname() << ",";
            qDebug() << "Writing taskname for currentOpenTasks[" << i << "]";
            stream << currentOpenTasks[i].getDescription() << ",";
            qDebug() << "Writing description for currentOpenTasks[" << i << "]";
            stream << currentOpenTasks[i].getDeadline() << "\n";
            qDebug() << "Writing deadline for currentOpenTasks[" << i << "]";
        }
    }
    file.flush(); //Save contents to the file
    file.close(); //Close it to free up resources and keep file from being written accidentally later on

    /*These two lines below clear the task vectors for currentUser, so that
     * on logging out the vectors also clear. This solves the problem
     * of the current table being printed again on top of it being saved as well,
     * causing the table to exponentially grow after every time you log out */
    currentUser.clearOpenTasks();
    currentUser.clearClosedTasks();
    hide();             // Hide MainTaskScreen
    mainWindow->show(); // Show MainWindow for logout navigation
}

// Slot to open the task settings window
void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    taskSettings = new TaskSettings(this);
    // Connect taskSettings to update the checklist when a task is saved
    connect(taskSettings,
            &TaskSettings::taskSaved,
            this,
            &MainTaskScreen::addTaskToChecklist,
            Qt::UniqueConnection);
    taskSettings->exec(); // Open the TaskSettings dialog as a modal
}

// Add a task to the main checklist display
void MainTaskScreen::addTaskToChecklist(const QString &taskName,
                                        const QString &taskDeadline,
                                        const QString &taskDescription)
{
    // Insert a new row at the top of the main task table
    ui->tableWidget->insertRow(0);

    // Create QTableWidgetItem instances for each column
    QTableWidgetItem *nameItem = new QTableWidgetItem(taskName.isEmpty() ? "Unnamed Task"
                                                                         : taskName);
    QTableWidgetItem *deadlineItem = new QTableWidgetItem(taskDeadline.isEmpty() ? "No deadline"
                                                                                 : taskDeadline);
    QTableWidgetItem *descriptionItem = new QTableWidgetItem(
        taskDescription.isEmpty() ? "No description" : taskDescription);

    // Set the items to be non-editable
    nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
    deadlineItem->setFlags(deadlineItem->flags() & ~Qt::ItemIsEditable);
    descriptionItem->setFlags(descriptionItem->flags() & ~Qt::ItemIsEditable);

    // Add items to the table widget at row 0
    ui->tableWidget->setItem(0, 0, nameItem);
    ui->tableWidget->setItem(0, 1, deadlineItem);
    ui->tableWidget->setItem(0, 2, descriptionItem);

    // Debug output
    qDebug() << "Task added to checklist: Name =" << taskName << ", Deadline =" << taskDeadline
             << ", Description =" << taskDescription;
}

// Handle quick add task button click
void MainTaskScreen::on_QuickAddBtn_clicked()
{
    // Retrieve new task details from quick add input fields
    QString taskName = ui->lineEditTaskName->text();
    QString taskDeadline = ui->lineEditDeadline->text();
    QString taskDescription = ui->lineEditDesc->text();

    QRegularExpression dateRegex("^\\d{4}-\\d{2}-\\d{2}$");
    QRegularExpressionMatch match = dateRegex.match(taskDeadline);
    if (!match.hasMatch()) {
        QMessageBox::warning(
            this,
            "Invalid Date Format",
            "Please enter the date in the format [The YEAR (YYYY) 4 digits- The MONTH (MM) 2 "
            "digits - The DAY (DD) (2 digits)]. Please include the dashes");
        return; // Stop processing if the date format is invalid
    }

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
    QString taskDeadline = taskDeadlineItem && !taskDeadlineItem->text().isEmpty()
                               ? taskDeadlineItem->text()
                               : "No deadline";
    QString taskDescription = taskDescriptionItem && !taskDescriptionItem->text().isEmpty()
                                  ? taskDescriptionItem->text()
                                  : "No description";

    // Move task from open to completed for current user
    currentUser.closeTask(taskName);

    // Add task details to completed tasks table
    ui->tableWidget_2->insertRow(0);
    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem(taskName));
    ui->tableWidget_2->setItem(0, 1, new QTableWidgetItem(taskDeadline));
    ui->tableWidget_2->setItem(0, 2, new QTableWidgetItem(taskDescription));

    qDebug() << "Task moved to completed: Name =" << taskName << ", Deadline =" << taskDeadline
             << ", Description =" << taskDescription;

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
            taskDetails += QString("Task: %1\nDescription: %2\n\n")
                               .arg(task.getTaskname())
                               .arg(task.getDescription());
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
            taskDetails += QString("Task: %1\nDescription: %2\n\n")
                               .arg(task.getTaskname())
                               .arg(task.getDescription());
        }
    }
    if (taskDetails.isEmpty()) {
        taskDetails = "No tasks for this date.";
    }
}

// Slot to open LargeCalendar and connect date selection to showTasksForDate
void MainTaskScreen::on_OpenCalenderBtn_clicked()
{
    QVector<Task> tasks = currentUser.getTasks(0);  // Grab open tasks for display
    largeCalendar = new LargeCalendar(tasks, this); // Initialize LargeCalendar with tasks

    // Connect LargeCalendar's date selection to showTasksForDate
    connect(largeCalendar, &LargeCalendar::dateSelected, this, &MainTaskScreen::showTasksForDate);

    largeCalendar->show(); // Display the LargeCalendar
}

void MainTaskScreen::on_ClearAllTask_clicked()
{
    ui->tableWidget_2->setRowCount(0);
}

// Destructor for MainTaskScreen
MainTaskScreen::~MainTaskScreen()
{
    delete ui;            // Clean up UI elements
    delete largeCalendar; // Ensure LargeCalendar is deleted
}

void MainTaskScreen::on_CompleteAllTask_clicked()
{
    int totalRows = ui->tableWidget->rowCount(); // get number of rows

    if (totalRows == 0) {
        qDebug() << "No tasks to complete."; //no row to select complete.. Task list is empty
        return;
    }

    // Iterate over the rows from top to bottom to maintain the correct order
    for (int i = 0; i < totalRows; ++i) {
        // Always process the first row (0) since rows shift up after removal
        QTableWidgetItem *taskNameItem = ui->tableWidget->item(0, 0);
        QTableWidgetItem *taskDeadlineItem = ui->tableWidget->item(0, 1);
        QTableWidgetItem *taskDescriptionItem = ui->tableWidget->item(0, 2);

        if (!taskNameItem || taskNameItem->text().isEmpty()) {
            continue; // Skip if no task name or empty row
        }

        QString taskName = taskNameItem->text();
        QString taskDeadline = taskDeadlineItem ? taskDeadlineItem->text() : "No deadline";
        QString taskDescription = taskDescriptionItem ? taskDescriptionItem->text()
                                                      : "No description";

        // Insert the task at the top of the completed tasks table
        ui->tableWidget_2->insertRow(0);
        ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem(taskName));
        ui->tableWidget_2->setItem(0, 1, new QTableWidgetItem(taskDeadline));
        ui->tableWidget_2->setItem(0, 2, new QTableWidgetItem(taskDescription));

        qDebug() << "Task completed: Name =" << taskName << ", Deadline =" << taskDeadline
                 << ", Description =" << taskDescription;

        // Update currentUser to reflect that the task is completed
        currentUser.closeTask(taskName);

        // Remove the task from the main task table
        ui->tableWidget->removeRow(0);
    }

    qDebug() << "All tasks have been moved to the completed tasks table.";
}

void MainTaskScreen::on_OpenCalBtn_clicked()
{
    QVector<Task> tasks = currentUser.getTasks(0);  // Grab open tasks for display
    largeCalendar = new LargeCalendar(tasks, this); // Initialize LargeCalendar with tasks

    // Connect LargeCalendar's date selection to showTasksForDate
    connect(largeCalendar, &LargeCalendar::dateSelected, this, &MainTaskScreen::showTasksForDate);

    largeCalendar->show(); // Display the LargeCalendar
}

