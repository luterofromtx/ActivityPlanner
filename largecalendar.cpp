#include "largecalendar.h"
#include <QMessageBox>
#include "currentuser.h"
#include "task.h"
#include "ui_largecalendar.h"

LargeCalendar::LargeCalendar(QVector<Task> tasks, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LargeCalendar)
    , taskList(tasks)
{
    ui->setupUi(this);
    connect(ui->calendarWidget,
            &QCalendarWidget::clicked,
            this,
            &LargeCalendar::on_calendarWidget_activated,
            Qt::UniqueConnection);
}

LargeCalendar::~LargeCalendar()
{
    delete ui;
}

void LargeCalendar::on_CloseBtn_clicked()
{
    hide();
}

void LargeCalendar::on_calendarWidget_activated(const QDate &date)
{
    static bool processing = false;
    if (processing)
        return; // Exit if already processing

    processing = true;       // Set guard
    emit dateSelected(date); // Emit the dateSelected signal with the activated date

    QString selectedDate = date.toString("yyyy-MM-dd");
    qDebug() << "Selected date:" << selectedDate; // Debugging: Print selected date

    QString taskDetails;
    for (const Task &task : taskList) {
        qDebug() << "Checking Task with Deadline:"
                 << task.getDeadline(); // Debug each task deadline

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
