/********************************************************************************
** Form generated from reading UI file 'maintaskscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTASKSCREEN_H
#define UI_MAINTASKSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTaskScreen
{
public:
    QPushButton *LogoutBtn;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox_2;
    QScrollBar *verticalScrollBar;
    QGroupBox *groupBox_3;
    QScrollBar *verticalScrollBar_2;
    QLabel *label_4;
    QPushButton *SwitchUserBtn;
    QGroupBox *groupBox;
    QPushButton *QuickAddBtn;
    QPushButton *AddTaskSettingsBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *SettingsBtn;
    QToolButton *OpenCalenderBtn;

    void setupUi(QDialog *MainTaskScreen)
    {
        if (MainTaskScreen->objectName().isEmpty())
            MainTaskScreen->setObjectName("MainTaskScreen");
        MainTaskScreen->resize(944, 487);
        LogoutBtn = new QPushButton(MainTaskScreen);
        LogoutBtn->setObjectName("LogoutBtn");
        LogoutBtn->setGeometry(QRect(840, 450, 75, 24));
        calendarWidget = new QCalendarWidget(MainTaskScreen);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(600, 250, 312, 190));
        groupBox_2 = new QGroupBox(MainTaskScreen);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 30, 551, 291));
        QFont font;
        font.setPointSize(11);
        groupBox_2->setFont(font);
        verticalScrollBar = new QScrollBar(groupBox_2);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(530, 10, 16, 271));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        groupBox_3 = new QGroupBox(MainTaskScreen);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 340, 551, 131));
        groupBox_3->setFont(font);
        verticalScrollBar_2 = new QScrollBar(groupBox_3);
        verticalScrollBar_2->setObjectName("verticalScrollBar_2");
        verticalScrollBar_2->setGeometry(QRect(530, 10, 20, 121));
        verticalScrollBar_2->setOrientation(Qt::Orientation::Vertical);
        label_4 = new QLabel(MainTaskScreen);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(390, 10, 171, 16));
        label_4->setFont(font);
        SwitchUserBtn = new QPushButton(MainTaskScreen);
        SwitchUserBtn->setObjectName("SwitchUserBtn");
        SwitchUserBtn->setGeometry(QRect(600, 450, 75, 24));
        groupBox = new QGroupBox(MainTaskScreen);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(600, 30, 311, 191));
        QFont font1;
        font1.setPointSize(10);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        QuickAddBtn = new QPushButton(groupBox);
        QuickAddBtn->setObjectName("QuickAddBtn");
        QuickAddBtn->setGeometry(QRect(10, 160, 111, 24));
        AddTaskSettingsBtn = new QPushButton(groupBox);
        AddTaskSettingsBtn->setObjectName("AddTaskSettingsBtn");
        AddTaskSettingsBtn->setGeometry(QRect(170, 160, 121, 24));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 281, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout->addWidget(lineEdit_3);

        SettingsBtn = new QPushButton(MainTaskScreen);
        SettingsBtn->setObjectName("SettingsBtn");
        SettingsBtn->setGeometry(QRect(710, 450, 91, 24));
        OpenCalenderBtn = new QToolButton(MainTaskScreen);
        OpenCalenderBtn->setObjectName("OpenCalenderBtn");
        OpenCalenderBtn->setGeometry(QRect(870, 227, 41, 21));

        retranslateUi(MainTaskScreen);

        QMetaObject::connectSlotsByName(MainTaskScreen);
    } // setupUi

    void retranslateUi(QDialog *MainTaskScreen)
    {
        MainTaskScreen->setWindowTitle(QCoreApplication::translate("MainTaskScreen", "Dialog", nullptr));
        LogoutBtn->setText(QCoreApplication::translate("MainTaskScreen", "Logout", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainTaskScreen", "Task Checklist", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainTaskScreen", "Completed Tasks", nullptr));
        label_4->setText(QCoreApplication::translate("MainTaskScreen", "User:", nullptr));
        SwitchUserBtn->setText(QCoreApplication::translate("MainTaskScreen", "Switch User", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainTaskScreen", "Add Task", nullptr));
        QuickAddBtn->setText(QCoreApplication::translate("MainTaskScreen", "Quick Add", nullptr));
        AddTaskSettingsBtn->setText(QCoreApplication::translate("MainTaskScreen", "Settings", nullptr));
        label->setText(QCoreApplication::translate("MainTaskScreen", "Task Name:", nullptr));
        label_2->setText(QCoreApplication::translate("MainTaskScreen", "Description:", nullptr));
        label_3->setText(QCoreApplication::translate("MainTaskScreen", "Deadline:", nullptr));
        SettingsBtn->setText(QCoreApplication::translate("MainTaskScreen", "Settings", nullptr));
        OpenCalenderBtn->setText(QCoreApplication::translate("MainTaskScreen", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainTaskScreen: public Ui_MainTaskScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTASKSCREEN_H
