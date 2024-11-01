/********************************************************************************
** Form generated from reading UI file 'forgotpassword.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTPASSWORD_H
#define UI_FORGOTPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgotPassword
{
public:
    QGroupBox *groupBox;
    QPushButton *CancelBtn;
    QPushButton *ConfirmBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelConfirmPass;
    QLineEdit *lineEditConfirmPass;

    void setupUi(QDialog *ForgotPassword)
    {
        if (ForgotPassword->objectName().isEmpty())
            ForgotPassword->setObjectName("ForgotPassword");
        ForgotPassword->resize(618, 479);
        groupBox = new QGroupBox(ForgotPassword);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 60, 361, 321));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        CancelBtn = new QPushButton(groupBox);
        CancelBtn->setObjectName("CancelBtn");
        CancelBtn->setGeometry(QRect(30, 270, 75, 24));
        ConfirmBtn = new QPushButton(groupBox);
        ConfirmBtn->setObjectName("ConfirmBtn");
        ConfirmBtn->setGeometry(QRect(260, 270, 75, 24));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 40, 321, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelUsername = new QLabel(layoutWidget);
        labelUsername->setObjectName("labelUsername");

        verticalLayout->addWidget(labelUsername);

        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName("lineEditUsername");

        verticalLayout->addWidget(lineEditUsername);

        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName("labelPassword");

        verticalLayout->addWidget(labelPassword);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        verticalLayout->addWidget(lineEditPassword);

        labelConfirmPass = new QLabel(layoutWidget);
        labelConfirmPass->setObjectName("labelConfirmPass");

        verticalLayout->addWidget(labelConfirmPass);

        lineEditConfirmPass = new QLineEdit(layoutWidget);
        lineEditConfirmPass->setObjectName("lineEditConfirmPass");

        verticalLayout->addWidget(lineEditConfirmPass);


        retranslateUi(ForgotPassword);

        QMetaObject::connectSlotsByName(ForgotPassword);
    } // setupUi

    void retranslateUi(QDialog *ForgotPassword)
    {
        ForgotPassword->setWindowTitle(QCoreApplication::translate("ForgotPassword", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ForgotPassword", "Reset Password", nullptr));
        CancelBtn->setText(QCoreApplication::translate("ForgotPassword", "Cancel", nullptr));
        ConfirmBtn->setText(QCoreApplication::translate("ForgotPassword", "Confirm", nullptr));
        labelUsername->setText(QCoreApplication::translate("ForgotPassword", "Username:", nullptr));
        labelPassword->setText(QCoreApplication::translate("ForgotPassword", "New Password:", nullptr));
        labelConfirmPass->setText(QCoreApplication::translate("ForgotPassword", "Confirm Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgotPassword: public Ui_ForgotPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASSWORD_H
