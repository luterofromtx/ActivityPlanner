#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <QDialog>

namespace Ui {
class Notifications;
}

class Notifications : public QDialog
{
    Q_OBJECT

public:
    explicit Notifications(QWidget *parent = nullptr);
    ~Notifications();

private slots:
    void on_CloseBtn_clicked();

private:
    Ui::Notifications *ui;
};

#endif // NOTIFICATIONS_H
