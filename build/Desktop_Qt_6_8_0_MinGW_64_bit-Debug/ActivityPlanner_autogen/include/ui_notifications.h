/********************************************************************************
** Form generated from reading UI file 'notifications.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATIONS_H
#define UI_NOTIFICATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notifications
{
public:
    QPushButton *CloseBtn;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    void setupUi(QDialog *Notifications)
    {
        if (Notifications->objectName().isEmpty())
            Notifications->setObjectName("Notifications");
        Notifications->resize(833, 604);
        CloseBtn = new QPushButton(Notifications);
        CloseBtn->setObjectName("CloseBtn");
        CloseBtn->setGeometry(QRect(600, 540, 131, 24));
        groupBox = new QGroupBox(Notifications);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 761, 491));
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(30, 50, 331, 61));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(false);
        font1.setItalic(false);
        checkBox->setFont(font1);
        checkBox->setAutoFillBackground(false);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 360, 221, 31));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 250, 598, 82));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(30, 160, 291, 80));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_2 = new QCheckBox(widget1);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(widget1);
        checkBox_3->setObjectName("checkBox_3");

        verticalLayout->addWidget(checkBox_3);


        retranslateUi(Notifications);

        QMetaObject::connectSlotsByName(Notifications);
    } // setupUi

    void retranslateUi(QDialog *Notifications)
    {
        Notifications->setWindowTitle(QCoreApplication::translate("Notifications", "Dialog", nullptr));
        CloseBtn->setText(QCoreApplication::translate("Notifications", "Close", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Notifications", "Notification Settings", nullptr));
        checkBox->setText(QCoreApplication::translate("Notifications", "Enable Notifications", nullptr));
        label_2->setText(QCoreApplication::translate("Notifications", "TimeZone:", nullptr));
        label->setText(QCoreApplication::translate("Notifications", "Notification Frequency:", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Notifications", "Desktop Notifications", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Notifications", "Banner Notifications", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notifications: public Ui_Notifications {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATIONS_H
