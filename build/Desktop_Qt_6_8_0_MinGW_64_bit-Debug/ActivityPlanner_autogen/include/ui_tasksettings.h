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
    QPushButton *SaveTaskBtn;
    QPushButton *CloseTaskBtn;
    QLabel *label_3;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_4;

    void setupUi(QDialog *TaskSettings)
    {
        if (TaskSettings->objectName().isEmpty())
            TaskSettings->setObjectName("TaskSettings");
        TaskSettings->resize(730, 482);
        groupBox = new QGroupBox(TaskSettings);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 30, 571, 381));
        QFont font;
        font.setPointSize(15);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SaveTaskBtn = new QPushButton(groupBox);
        SaveTaskBtn->setObjectName("SaveTaskBtn");
        SaveTaskBtn->setGeometry(QRect(440, 330, 75, 24));
        QFont font1;
        font1.setPointSize(9);
        SaveTaskBtn->setFont(font1);
        CloseTaskBtn = new QPushButton(groupBox);
        CloseTaskBtn->setObjectName("CloseTaskBtn");
        CloseTaskBtn->setGeometry(QRect(60, 330, 75, 24));
        CloseTaskBtn->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 280, 51, 21));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(30, 280, 151, 20));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(310, 280, 113, 22));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 180, 531, 81));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 30, 271, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);


        retranslateUi(TaskSettings);

        QMetaObject::connectSlotsByName(TaskSettings);
    } // setupUi

    void retranslateUi(QDialog *TaskSettings)
    {
        TaskSettings->setWindowTitle(QCoreApplication::translate("TaskSettings", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TaskSettings", "Task Settings", nullptr));
        SaveTaskBtn->setText(QCoreApplication::translate("TaskSettings", "Save", nullptr));
        CloseTaskBtn->setText(QCoreApplication::translate("TaskSettings", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("TaskSettings", "Time:", nullptr));
        checkBox->setText(QCoreApplication::translate("TaskSettings", "Enable Timer", nullptr));
        label->setText(QCoreApplication::translate("TaskSettings", "Task:", nullptr));
        label_2->setText(QCoreApplication::translate("TaskSettings", "Date:", nullptr));
        label_4->setText(QCoreApplication::translate("TaskSettings", "Description:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskSettings: public Ui_TaskSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSETTINGS_H
