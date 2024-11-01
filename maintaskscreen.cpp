#include "maintaskscreen.h"
#include <QDebug>
#include "mainwindow.h"
#include "task.h"
#include "tasksettings.h"
#include "ui_maintaskscreen.h"

CurrentUser currentUser;

void UpdateUserMain(QString username, QVector<Task> openTasks, QVector<Task> closedTasks) {
    currentUser.UpdateUser(username, openTasks, closedTasks);
}

MainTaskScreen::MainTaskScreen(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainTaskScreen)
    , mainWindow(mainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               << "Task Name" << "Deadline" << "Description");
}

void MainTaskScreen::on_LogoutBtn_clicked()
{
    hide();
    mainWindow->show();
}
void MainTaskScreen::on_AddTaskSettingsBtn_clicked()
{
    taskSettings = new TaskSettings(this);

    // Connect the signal emitted when the task is saved to the slot that adds it to the checklist
    connect(taskSettings,
            &TaskSettings::taskSaved,
            this,
            &MainTaskScreen::addTaskToChecklist,
            Qt::UniqueConnection);

    // Show the TaskSettings dialog
    taskSettings->exec(); // This will handle showing the dialog and checking the result
}

void MainTaskScreen::addTaskToChecklist(const QString &taskName, const QString &taskDeadline, const QString &taskDescription)
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);

    QTableWidgetItem *taskNameItem = new QTableWidgetItem(taskName);
    QTableWidgetItem *taskDeadlineItem = new QTableWidgetItem(taskDeadline);
    QTableWidgetItem *taskDescriptionItem = new QTableWidgetItem(taskDescription);

    ui->tableWidget->setItem(rowCount, 0, taskNameItem);
    ui->tableWidget->setItem(rowCount, 1, taskDeadlineItem);
    ui->tableWidget->setItem(rowCount, 2, taskDescriptionItem);

    // Optional: Align the text and enable text wrapping
    taskNameItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
    taskDeadlineItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
    taskDescriptionItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);

    qDebug() << "Task added to checklist: Name =" << taskName << ", Deadline =" << taskDeadline
             << ", Description =" << taskDescription;
}

void MainTaskScreen::on_SettingsBtn_clicked()
{
    notifications = new Notifications(this);
    notifications->show();
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


void UpdateTaskUI() {

    QVector<Task> openTasks;
    for (int i=0;i<openTasks.size();++i) {


    }
    QVector<Task> closedTasks;
    for(int i=0;i<closedTasks.size();++i) {


    }

}

void MainTaskScreen::on_QuickAddBtn_clicked()
{
    // Test case
    QString taskName = ui->lineEditTaskName->text();
    QString taskDesc = ui->lineEditDesc->text();
    QString taskDeadline = ui->lineEditDeadline->text();

    // Display quick-added task details
    ui->TaskNameT->setText(taskName);
    ui->TaskDeadlineT->setText(taskDeadline);
    // -----------------------

    Task newTask(taskName, taskDesc, taskDeadline); // New open task
    currentUser.addTask(newTask); // Add task to current user open task vector


}

void MainTaskScreen::on_DoneBtnT_clicked()
{
    ui->TaskNameT->clear();
    ui->TaskDeadlineT->clear();
    ui->CompletedT->setText("Completed");

    QString taskName;
    QVector<Task> *openTable = currentUser.getTasks(0);






}
MainTaskScreen::~MainTaskScreen()
{
    delete ui;
}
