/********************************************************************************
** Form generated from reading UI file 'tasksettings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSETTINGS_H
#define UI_TASKSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskSettings
{
public:
    QGroupBox *groupBox;
    QPushButton *SaveTaskSettingBtn;
    QPushButton *CloseTaskSettingBtn;
    QLabel *label_3;
    QCheckBox *TimercheckBox;
    QLineEdit *TimerCountDown;
    QLineEdit *DescriptionLine;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Task;
    QLineEdit *Taskname;
    QLabel *label_2;
    QLineEdit *DateGiven;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QDialog *TaskSettings)
    {
        if (TaskSettings->objectName().isEmpty())
            TaskSettings->setObjectName("TaskSettings");
        TaskSettings->resize(730, 482);
        groupBox = new QGroupBox(TaskSettings);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 0, 571, 381));
        QFont font;
        font.setPointSize(15);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SaveTaskSettingBtn = new QPushButton(groupBox);
        SaveTaskSettingBtn->setObjectName("SaveTaskSettingBtn");
        SaveTaskSettingBtn->setGeometry(QRect(440, 330, 75, 24));
        QFont font1;
        font1.setPointSize(9);
        SaveTaskSettingBtn->setFont(font1);
        CloseTaskSettingBtn = new QPushButton(groupBox);
        CloseTaskSettingBtn->setObjectName("CloseTaskSettingBtn");
        CloseTaskSettingBtn->setGeometry(QRect(60, 330, 75, 24));
        CloseTaskSettingBtn->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 280, 51, 16));
        TimercheckBox = new QCheckBox(groupBox);
        TimercheckBox->setObjectName("TimercheckBox");
        TimercheckBox->setGeometry(QRect(30, 280, 151, 20));
        TimerCountDown = new QLineEdit(groupBox);
        TimerCountDown->setObjectName("TimerCountDown");
        TimerCountDown->setGeometry(QRect(310, 280, 113, 22));
        DescriptionLine = new QLineEdit(groupBox);
        DescriptionLine->setObjectName("DescriptionLine");
        DescriptionLine->setGeometry(QRect(10, 170, 531, 81));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 30, 271, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Task = new QLabel(layoutWidget);
        Task->setObjectName("Task");

        verticalLayout->addWidget(Task);

        Taskname = new QLineEdit(layoutWidget);
        Taskname->setObjectName("Taskname");

        verticalLayout->addWidget(Taskname);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        DateGiven = new QLineEdit(layoutWidget);
        DateGiven->setObjectName("DateGiven");

        verticalLayout->addWidget(DateGiven);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 260, 71, 16));

        retranslateUi(TaskSettings);

        QMetaObject::connectSlotsByName(TaskSettings);
    } // setupUi

    void retranslateUi(QDialog *TaskSettings)
    {
        TaskSettings->setWindowTitle(QCoreApplication::translate("TaskSettings", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TaskSettings", "Task Settings", nullptr));
        SaveTaskSettingBtn->setText(QCoreApplication::translate("TaskSettings", "Save", nullptr));
        CloseTaskSettingBtn->setText(QCoreApplication::translate("TaskSettings", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("TaskSettings", "Time:", nullptr));
        TimercheckBox->setText(QCoreApplication::translate("TaskSettings", "Enable Timer", nullptr));
        Task->setText(QCoreApplication::translate("TaskSettings", "Task:", nullptr));
        Taskname->setText(QString());
        label_2->setText(QCoreApplication::translate("TaskSettings", "Date: YYYY-MM-DD", nullptr));
        label_4->setText(QCoreApplication::translate("TaskSettings", "Description:", nullptr));
        label->setText(QCoreApplication::translate("TaskSettings", "\"00:00:00\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskSettings: public Ui_TaskSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSETTINGS_H
