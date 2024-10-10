/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

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

class Ui_CreateAccount
{
public:
    QGroupBox *groupBox;
    QPushButton *BackBtn;
    QPushButton *CreateAccountBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEditUsername;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QLabel *label_3;
    QLineEdit *lineEditConfirm;

    void setupUi(QDialog *CreateAccount)
    {
        if (CreateAccount->objectName().isEmpty())
            CreateAccount->setObjectName("CreateAccount");
        CreateAccount->resize(553, 432);
        groupBox = new QGroupBox(CreateAccount);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(90, 40, 381, 311));
        BackBtn = new QPushButton(groupBox);
        BackBtn->setObjectName("BackBtn");
        BackBtn->setGeometry(QRect(30, 260, 75, 24));
        CreateAccountBtn = new QPushButton(groupBox);
        CreateAccountBtn->setObjectName("CreateAccountBtn");
        CreateAccountBtn->setGeometry(QRect(214, 260, 121, 24));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 50, 261, 146));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName("lineEditUsername");

        verticalLayout->addWidget(lineEditUsername);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        verticalLayout->addWidget(lineEditPassword);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEditConfirm = new QLineEdit(layoutWidget);
        lineEditConfirm->setObjectName("lineEditConfirm");

        verticalLayout->addWidget(lineEditConfirm);


        retranslateUi(CreateAccount);

        QMetaObject::connectSlotsByName(CreateAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateAccount)
    {
        CreateAccount->setWindowTitle(QCoreApplication::translate("CreateAccount", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CreateAccount", "Create Account", nullptr));
        BackBtn->setText(QCoreApplication::translate("CreateAccount", "Back", nullptr));
        CreateAccountBtn->setText(QCoreApplication::translate("CreateAccount", "Create Account", nullptr));
        label->setText(QCoreApplication::translate("CreateAccount", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("CreateAccount", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("CreateAccount", "Confirm Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAccount: public Ui_CreateAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
