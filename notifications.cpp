#include "notifications.h"
#include "ui_notifications.h"

Notifications::Notifications(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Notifications)
{
    ui->setupUi(this);
}

Notifications::~Notifications()
{
    delete ui;
}

// Close settings ui
void Notifications::on_CloseBtn_clicked()
{
    hide();
}
