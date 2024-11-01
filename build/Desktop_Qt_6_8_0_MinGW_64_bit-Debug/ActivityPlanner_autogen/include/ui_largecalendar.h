/********************************************************************************
** Form generated from reading UI file 'largecalendar.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LARGECALENDAR_H
#define UI_LARGECALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LargeCalendar
{
public:
    QCalendarWidget *calendarWidget;
    QPushButton *CloseBtn;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *LargeCalendar)
    {
        if (LargeCalendar->objectName().isEmpty())
            LargeCalendar->setObjectName("LargeCalendar");
        LargeCalendar->resize(868, 611);
        calendarWidget = new QCalendarWidget(LargeCalendar);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(0, 0, 871, 571));
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat::LongDayNames);
        CloseBtn = new QPushButton(LargeCalendar);
        CloseBtn->setObjectName("CloseBtn");
        CloseBtn->setGeometry(QRect(310, 580, 241, 24));
        label = new QLabel(LargeCalendar);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 300, 81, 21));
        label_2 = new QLabel(LargeCalendar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(470, 320, 49, 16));

        retranslateUi(LargeCalendar);

        QMetaObject::connectSlotsByName(LargeCalendar);
    } // setupUi

    void retranslateUi(QDialog *LargeCalendar)
    {
        LargeCalendar->setWindowTitle(QCoreApplication::translate("LargeCalendar", "Dialog", nullptr));
        CloseBtn->setText(QCoreApplication::translate("LargeCalendar", "Close", nullptr));
        label->setText(QCoreApplication::translate("LargeCalendar", "MidTerm Exam", nullptr));
        label_2->setText(QCoreApplication::translate("LargeCalendar", "2:00pm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LargeCalendar: public Ui_LargeCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LARGECALENDAR_H
