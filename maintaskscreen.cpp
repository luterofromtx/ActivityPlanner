#include "maintaskscreen.h"
#include <QDebug>
#include <QMessageBox>
#include "largecalendar.h" // Include LargeCalendar
#include "mainwindow.h"
#include "task.h"
#include "tasksettings.h"
#include "ui_maintaskscreen.h"

CurrentUser currentUser;

void UpdateUserMain(QString username, QVector<Task> openTasks, QVector<Task> closedTasks)
{
    currentUser.UpdateUser(username, openTasks, closedTasks);
}

void MainTaskScreen::UpdateMainUI()
{
    // Get open and closed tasks
    QVector<Task> openTasks = currentUser.getTasks(0);
    QVector<Task> closedTasks = currentUser.getTasks(1);

    // Display open tasks
    for (const Task &task : openTasks) {
        addTaskToChecklist(task.getTaskname(), task.getDeadline(), task.getDescription());
    }

    // Display closed tasks
    for (const Task &task : closedTasks) {
        int row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(task.getTaskname()));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(task.getDeadline()));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(task.getDescription()));
    }
}

MainTaskScreen::MainTaskScreen(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainTaskScreen)
    , mainWindow(mainWindow)
    , selectedRowForCompletion(-1)
    , selectedRowForClear(-1)
{
    ui->setupUi(this);

    // Set up tableWidget with three columns for tasks
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               << "Task Name" << "Deadline" << "Description");

    // Set up tableWidget_2 with three columns for completed tasks
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()
                                                 << "Task Name" << "Deadline" << "Description");

    // Connect buttons
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

    // Update selected row for `on_Completed_clicked` when a row is clicked in tableWidget
    connect(ui->tableWidget, &QTableWidget::itemClicked, this, [=](QTableWidgetItem *item) {
        selectedRowForCompletion = item->row();
        qDebug() << "Selected row for completion updated to:" << selectedRowForCompletion;
    });

    // Update selected row for `on_ClearCompleted_clicked` when a row is clicked in tableWidget_2
    connect(ui->tableWidget_2, &QTableWidget::itemClicked, this, [=](QTableWidgetItem *item) {
        selectedRowForClear = item->row();
        qDebug() << "Selected row for clearing updated to:" << selectedRowForClear;
    });

    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget_2->setSortingEnabled(false);
}

void MainTaskScreen::on_LogoutBtn_clicked()
{
    hide();
    mainWindow->show();
}

void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    taskSettings = new TaskSettings(this);
    connect(taskSettings,
            &TaskSettings::taskSaved,
            this,
            &MainTaskScreen::addTaskToChecklist,
            Qt::UniqueConnection);
    taskSettings->exec();
}

void MainTaskScreen::addTaskToChecklist(const QString &taskName,
                                        const QString &taskDeadline,
                                        const QString &taskDescription)
{
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,
                             0,
                             new QTableWidgetItem(taskName.isEmpty() ? "Unnamed Task" : taskName));
    ui->tableWidget->setItem(0,
                             1,
                             new QTableWidgetItem(taskDeadline.isEmpty() ? "No deadline"
                                                                         : taskDeadline));
    ui->tableWidget->setItem(0,
                             2,
                             new QTableWidgetItem(taskDescription.isEmpty() ? "No description"
                                                                            : taskDescription));
    qDebug() << "Task added to checklist: Name =" << taskName << ", Deadline =" << taskDeadline
             << ", Description =" << taskDescription;
}

void MainTaskScreen::on_QuickAddBtn_clicked()
{
    // New task value from quick add screen
    QString taskName = ui->lineEditTaskName->text();
    QString taskDeadline = ui->lineEditDeadline->text();
    QString taskDescription = ui->lineEditDesc->text();
    addTaskToChecklist(taskName, taskDeadline, taskDescription);

    // New task to add to current user
    Task newTask(taskName, taskDescription, taskDeadline);
    currentUser.addTask(newTask);

    // Clear ui text in quick add menu
    ui->lineEditTaskName->clear();
    ui->lineEditDeadline->clear();
    ui->lineEditDesc->clear();
}

void MainTaskScreen::on_SettingsBtn_clicked()
{
    notifications = new Notifications(this);
    notifications->show();
}

void MainTaskScreen::on_ClearCompleted_clicked()
{
    if (selectedRowForClear == -1) {
        qDebug() << "No completed task selected to clear.";
        return;
    }

    ui->tableWidget_2->removeRow(selectedRowForClear);
    qDebug() << "Cleared row " << selectedRowForClear << " from completed tasks (tableWidget_2).";

    // Reset selection
    selectedRowForClear = -1;
}

void MainTaskScreen::on_Completed_clicked()
{
    if (selectedRowForCompletion == -1) {
        qDebug() << "No task selected to mark as complete.";
        return;
    }

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

    currentUser.closeTask(taskName); // Move open task into closed task for current user

    ui->tableWidget_2->insertRow(0);
    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem(taskName));
    ui->tableWidget_2->setItem(0, 1, new QTableWidgetItem(taskDeadline));
    ui->tableWidget_2->setItem(0, 2, new QTableWidgetItem(taskDescription));

    qDebug() << "Task moved to completed table: Name =" << taskName
             << ", Deadline =" << taskDeadline << ", Description =" << taskDescription;

    ui->tableWidget->removeRow(selectedRowForCompletion);

    // Reset selection
    selectedRowForCompletion = -1;
}

void MainTaskScreen::on_calendarWidget_activated(const QDate &date)
{
    static bool processing = false;
    if (processing)
        return; // Exit if already processing

    processing = true; // Set guard

    QString selectedDate = date.toString("yyyy-MM-dd");
    qDebug() << "Selected date:" << selectedDate; // Debugging: Print selected date

    // Retrieve tasks from currentUser
    QVector<Task> taskList = currentUser.getTasks(0); // Ensure tasks are available here

    QString taskDetails;
    for (const Task &task : taskList) {
        qDebug() << "Checking Task with Deadline:" << task.getDeadline(); // Debug each task deadline

        if (task.getDeadline() == selectedDate) { // Match task deadline with selected date
            taskDetails += QString("Task: %1\nDescription: %2\n\n")
                               .arg(task.getTaskname())
                               .arg(task.getDescription());
        }
    }

    if (taskDetails.isEmpty()) {
        taskDetails = "No tasks for this date.";
    }

    QMessageBox::information(this, "Tasks for " + selectedDate, taskDetails);

    processing = false; // Reset guard
}


void MainTaskScreen::showTasksForDate(const QDate &date)
{
    QString selectedDate = date.toString("yyyy-MM-dd"); // Format date as "YYYY-MM-DD"

    // Fetch open tasks from currentUser
    QVector<Task> tasks = currentUser.getTasks(0); // 0 for open tasks

    QString taskDetails;
    for (const Task &task : tasks) {
        if (task.getDeadline() == selectedDate) { // Match task deadline with selected date
            taskDetails += QString("Task: %1\nDescription: %2\n\n")
                               .arg(task.getTaskname())
                               .arg(task.getDescription());
        }
    }
    if (taskDetails.isEmpty()) {
        taskDetails = "No tasks for this date.";
    }
}

void MainTaskScreen::on_OpenCalenderBtn_clicked()
{
    QVector<Task> tasks = currentUser.getTasks(0);  // Retrieve open tasks
    largeCalendar = new LargeCalendar(tasks, this); // Pass tasks and parent widget

    // Connect the dateSelected signal to showTasksForDate slot
    connect(largeCalendar, &LargeCalendar::dateSelected, this, &MainTaskScreen::showTasksForDate);

    largeCalendar->show();
}

MainTaskScreen::~MainTaskScreen()
{
    delete ui;
    delete largeCalendar; // Ensure cleanup
}
