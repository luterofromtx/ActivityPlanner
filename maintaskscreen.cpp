#include "maintaskscreen.h"
#include <QDebug>
#include "mainwindow.h"
#include "task.h"
#include "tasksettings.h"
#include "ui_maintaskscreen.h"

CurrentUser currentUser;

void UpdateUserMain(QString username, QVector<Task> openTasks, QVector<Task> closedTasks)
{
    currentUser.UpdateUser(username, openTasks, closedTasks);
}

MainTaskScreen::MainTaskScreen(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainTaskScreen)
    , mainWindow(mainWindow)
    , selectedRowForCompletion(-1) // Initialize selected row as -1 (none selected)
    , selectedRowForClear(-1)      // Initialize selected row for clear as -1
{
    ui->setupUi(this);

    // Set up tableWidget with three columns for tasks
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");

    // Set up tableWidget_2 with three columns for completed tasks
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Task Name" << "Deadline" << "Description");

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
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(taskName.isEmpty() ? "Unnamed Task" : taskName));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(taskDeadline.isEmpty() ? "No deadline" : taskDeadline));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(taskDescription.isEmpty() ? "No description" : taskDescription));
    qDebug() << "Task added to checklist: Name =" << taskName << ", Deadline =" << taskDeadline << ", Description =" << taskDescription;
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
    QString taskDeadline = taskDeadlineItem && !taskDeadlineItem->text().isEmpty() ? taskDeadlineItem->text() : "No deadline";
    QString taskDescription = taskDescriptionItem && !taskDescriptionItem->text().isEmpty() ? taskDescriptionItem->text() : "No description";

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
    // Calendar interaction logic (keep this if you need it for other purposes)
}

void MainTaskScreen::on_OpenCalenderBtn_clicked()
{
    largeCalendar = new LargeCalendar(this);
    largeCalendar->show();
}

void UpdateTaskUI()
{
    QVector<Task> openTasks;
    for (int i = 0; i < openTasks.size(); ++i) {
    }
    QVector<Task> closedTasks;
    for (int i = 0; i < closedTasks.size(); ++i) {
    }
}

MainTaskScreen::~MainTaskScreen()
{
    delete ui;
}
