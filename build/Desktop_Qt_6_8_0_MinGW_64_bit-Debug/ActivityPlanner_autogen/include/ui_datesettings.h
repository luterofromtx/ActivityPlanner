/********************************************************************************
** Form generated from reading UI file 'datesettings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATESETTINGS_H
#define UI_DATESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateSettings
{
public:
    QGroupBox *groupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ClearAllBtn;
    QPushButton *AddTaskBtn;
    QPushButton *CloseBtn;

    void setupUi(QDialog *DateSettings)
    {
        if (DateSettings->objectName().isEmpty())
            DateSettings->setObjectName("DateSettings");
        DateSettings->resize(747, 594);
        groupBox = new QGroupBox(DateSettings);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 20, 691, 551));
        QFont font;
        font.setPointSize(13);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 60, 641, 421));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 639, 419));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(620, 40, 16, 391));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        listWidget = new QListWidget(scrollAreaWidgetContents);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 40, 601, 391));
        listWidget->setGridSize(QSize(5, 5));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 141, 21));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 10, 111, 21));
        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName("line");
        line->setGeometry(QRect(320, 40, 20, 391));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(483, 40, 20, 391));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 30, 211, 21));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 510, 631, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ClearAllBtn = new QPushButton(widget);
        ClearAllBtn->setObjectName("ClearAllBtn");

        horizontalLayout->addWidget(ClearAllBtn);

        AddTaskBtn = new QPushButton(widget);
        AddTaskBtn->setObjectName("AddTaskBtn");

        horizontalLayout->addWidget(AddTaskBtn);

        CloseBtn = new QPushButton(widget);
        CloseBtn->setObjectName("CloseBtn");

        horizontalLayout->addWidget(CloseBtn);


        retranslateUi(DateSettings);

        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(DateSettings);
    } // setupUi

    void retranslateUi(QDialog *DateSettings)
    {
        DateSettings->setWindowTitle(QCoreApplication::translate("DateSettings", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DateSettings", "Date Settings", nullptr));
        label->setText(QCoreApplication::translate("DateSettings", "Task", nullptr));
        label_2->setText(QCoreApplication::translate("DateSettings", "Deadline", nullptr));
        label_3->setText(QCoreApplication::translate("DateSettings", "Date: ", nullptr));
        ClearAllBtn->setText(QCoreApplication::translate("DateSettings", "Clear All Tasks", nullptr));
        AddTaskBtn->setText(QCoreApplication::translate("DateSettings", "Add New Task", nullptr));
        CloseBtn->setText(QCoreApplication::translate("DateSettings", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateSettings: public Ui_DateSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATESETTINGS_H
