#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H

#include <QDialog>

// Predefine class to avoid recursive calling/inheritance from main.cpp
class MainWindow;

namespace Ui {
class ForgotPassword;
}

class ForgotPassword : public QDialog
{
    Q_OBJECT

public:
    explicit ForgotPassword(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~ForgotPassword();

private slots:
    void on_CancelBtn_clicked();

private:
    Ui::ForgotPassword *ui;
    MainWindow *mainWindow; // Pointer to return to main login page
};

#endif // FORGOTPASSWORD_H
