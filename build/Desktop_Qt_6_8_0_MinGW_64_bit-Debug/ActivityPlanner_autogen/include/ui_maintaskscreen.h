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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTableWidget>
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
    QTableWidget *tableWidget;
    QPushButton *DoneBtnT;
    QGroupBox *groupBox_3;
    QScrollBar *verticalScrollBar_2;
    QTableWidget *tableWidget_2;
    QLabel *label_4;
    QPushButton *SwitchUserBtn;
    QGroupBox *groupBox;
    QPushButton *QuickAddBtn;
    QPushButton *AddTaskSettingsBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEditTaskName;
    QLabel *label_2;
    QLineEdit *lineEditDesc;
    QLabel *label_3;
    QLineEdit *lineEditDeadline;
    QPushButton *SettingsBtn;
    QToolButton *OpenCalenderBtn;
    QPushButton *Completed;
    QPushButton *ClearCompleted;

    void setupUi(QDialog *MainTaskScreen)
    {
        if (MainTaskScreen->objectName().isEmpty())
            MainTaskScreen->setObjectName("MainTaskScreen");
        MainTaskScreen->resize(704, 487);
        LogoutBtn = new QPushButton(MainTaskScreen);
        LogoutBtn->setObjectName("LogoutBtn");
        LogoutBtn->setGeometry(QRect(840, 450, 75, 24));
        calendarWidget = new QCalendarWidget(MainTaskScreen);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(600, 250, 312, 190));
        groupBox_2 = new QGroupBox(MainTaskScreen);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 30, 571, 281));
        QFont font;
        font.setPointSize(11);
        groupBox_2->setFont(font);
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 30, 541, 241));
        tableWidget->setMinimumSize(QSize(541, 0));
        tableWidget->setRowCount(10);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(42);
        tableWidget->horizontalHeader()->setDefaultSectionSize(170);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(46);
        DoneBtnT = new QPushButton(groupBox_2);
        DoneBtnT->setObjectName("DoneBtnT");
        DoneBtnT->setEnabled(true);
        DoneBtnT->setGeometry(QRect(365, 107, 0, 0));
        groupBox_3 = new QGroupBox(MainTaskScreen);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 330, 551, 131));
        groupBox_3->setFont(font);
        verticalScrollBar_2 = new QScrollBar(groupBox_3);
        verticalScrollBar_2->setObjectName("verticalScrollBar_2");
        verticalScrollBar_2->setGeometry(QRect(530, 10, 20, 121));
        verticalScrollBar_2->setOrientation(Qt::Orientation::Vertical);
        tableWidget_2 = new QTableWidget(groupBox_3);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(10, 20, 511, 101));
        tableWidget_2->setRowCount(3);
        tableWidget_2->setColumnCount(3);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(169);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(33);
        label_4 = new QLabel(MainTaskScreen);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(400, 10, 51, 20));
        label_4->setFont(font);
        SwitchUserBtn = new QPushButton(MainTaskScreen);
        SwitchUserBtn->setObjectName("SwitchUserBtn");
        SwitchUserBtn->setGeometry(QRect(600, 450, 75, 24));
        groupBox = new QGroupBox(MainTaskScreen);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(600, 10, 311, 211));
        QFont font1;
        font1.setPointSize(10);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        QuickAddBtn = new QPushButton(groupBox);
        QuickAddBtn->setObjectName("QuickAddBtn");
        QuickAddBtn->setGeometry(QRect(10, 180, 111, 24));
        AddTaskSettingsBtn = new QPushButton(groupBox);
        AddTaskSettingsBtn->setObjectName("AddTaskSettingsBtn");
        AddTaskSettingsBtn->setGeometry(QRect(170, 180, 121, 24));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 281, 152));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEditTaskName = new QLineEdit(layoutWidget);
        lineEditTaskName->setObjectName("lineEditTaskName");

        verticalLayout->addWidget(lineEditTaskName);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEditDesc = new QLineEdit(layoutWidget);
        lineEditDesc->setObjectName("lineEditDesc");

        verticalLayout->addWidget(lineEditDesc);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEditDeadline = new QLineEdit(layoutWidget);
        lineEditDeadline->setObjectName("lineEditDeadline");

        verticalLayout->addWidget(lineEditDeadline);

        SettingsBtn = new QPushButton(MainTaskScreen);
        SettingsBtn->setObjectName("SettingsBtn");
        SettingsBtn->setGeometry(QRect(710, 450, 91, 24));
        OpenCalenderBtn = new QToolButton(MainTaskScreen);
        OpenCalenderBtn->setObjectName("OpenCalenderBtn");
        OpenCalenderBtn->setGeometry(QRect(870, 227, 41, 21));
        Completed = new QPushButton(MainTaskScreen);
        Completed->setObjectName("Completed");
        Completed->setGeometry(QRect(250, 315, 71, 21));
        ClearCompleted = new QPushButton(MainTaskScreen);
        ClearCompleted->setObjectName("ClearCompleted");
        ClearCompleted->setGeometry(QRect(260, 467, 56, 21));

        retranslateUi(MainTaskScreen);

        QMetaObject::connectSlotsByName(MainTaskScreen);
    } // setupUi

    void retranslateUi(QDialog *MainTaskScreen)
    {
        MainTaskScreen->setWindowTitle(QCoreApplication::translate("MainTaskScreen", "Dialog", nullptr));
        LogoutBtn->setText(QCoreApplication::translate("MainTaskScreen", "Logout", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainTaskScreen", "Task Checklist", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainTaskScreen", "Task", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainTaskScreen", "Dealine", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainTaskScreen", "Description", nullptr));
        DoneBtnT->setText(QCoreApplication::translate("MainTaskScreen", "Done", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainTaskScreen", "Completed Tasks", nullptr));
        label_4->setText(QCoreApplication::translate("MainTaskScreen", "User:", nullptr));
        SwitchUserBtn->setText(QCoreApplication::translate("MainTaskScreen", "Switch User", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainTaskScreen", "Add Task", nullptr));
        QuickAddBtn->setText(QCoreApplication::translate("MainTaskScreen", "Quick Add", nullptr));
        AddTaskSettingsBtn->setText(QCoreApplication::translate("MainTaskScreen", "Settings", nullptr));
        label->setText(QCoreApplication::translate("MainTaskScreen", "Task Name:", nullptr));
        label_2->setText(QCoreApplication::translate("MainTaskScreen", "Description:", nullptr));
        label_3->setText(QCoreApplication::translate("MainTaskScreen", "Deadline: MM/DD/YYYY", nullptr));
        SettingsBtn->setText(QCoreApplication::translate("MainTaskScreen", "Settings", nullptr));
        OpenCalenderBtn->setText(QCoreApplication::translate("MainTaskScreen", "...", nullptr));
        Completed->setText(QCoreApplication::translate("MainTaskScreen", "Complete", nullptr));
        ClearCompleted->setText(QCoreApplication::translate("MainTaskScreen", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainTaskScreen: public Ui_MainTaskScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTASKSCREEN_H
