#include "largecalendar.h"
#include <QMessageBox>
#include <QTextCharFormat>
#include <QDebug>
#include "currentuser.h"
#include "task.h"
#include "ui_largecalendar.h"

LargeCalendar::LargeCalendar(QVector<Task> tasks, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LargeCalendar)
    , taskList(tasks)
{
    ui->setupUi(this);

    // Connect the calendar widget to the clicked signal
    connect(ui->calendarWidget,
            &QCalendarWidget::clicked,
            this,
            &LargeCalendar::on_calendarWidget_activated,
            Qt::UniqueConnection);

    // Highlight dates with tasks on the calendar
    updateCalendarTaskDisplay();
}

LargeCalendar::~LargeCalendar()
{
    delete ui;
}

void LargeCalendar::on_CloseBtn_clicked()
{
    hide(); // Close the calendar dialog
}

void LargeCalendar::on_calendarWidget_activated(const QDate &date)
{
    static bool processing = false;
    if (processing)
        return; // Exit if already processing

    processing = true;       // Set guard to prevent re-entrant calls
    emit dateSelected(date); // Emit the dateSelected signal with the activated date

    QString selectedDate = date.toString("yyyy-MM-dd");
    qDebug() << "Selected date:" << selectedDate; // Debugging: Print selected date

    QString taskDetails;
    for (const Task &task : taskList) {
        qDebug() << "Checking Task with Deadline:" << task.getDeadline(); // Debug task deadlines

        if (task.getDeadline() == selectedDate) { // Match task deadline with selected date
            taskDetails += QString("Task: %1\nDescription: %2\n\n")
                               .arg(task.getTaskname())
                               .arg(task.getDescription());
        }
    }

    if (taskDetails.isEmpty()) {
        taskDetails = "No tasks for this date.";
    }

    // Display the task details in a message box
    QMessageBox::information(this, "Tasks for " + selectedDate, taskDetails);

    processing = false; // Reset guard
}

void LargeCalendar::updateCalendarTaskDisplay()
{
    // Create a QTextCharFormat to visually highlight task dates
    QTextCharFormat taskFormat;
    taskFormat.setBackground(Qt::blue); // Set blue cause BLUEE BABYYY background for task dates
    taskFormat.setForeground(Qt::black);  // Set text color to black
    taskFormat.setFontWeight(QFont::Bold);

    // Iterate through all tasks and apply the format to their dates
    for (const Task &task : taskList) {
        QDate taskDate = QDate::fromString(task.getDeadline(), "yyyy-MM-dd");
        if (taskDate.isValid()) {
            ui->calendarWidget->setDateTextFormat(taskDate, taskFormat); // Apply format to the calendar
        }
    }
}
