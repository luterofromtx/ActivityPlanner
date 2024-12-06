#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Timer;
}

class Timer : public QDialog
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

signals:
    void dataAvailable(const QString &data); // Signal to send data back to MainTaskScreen

private slots:
    void on_oneminute_clicked();
    void on_tenminutes_clicked();
    void on_thirtyminutes_clicked();
    void on_fourtyfiveminutes_clicked();
    void on_onehour_clicked();
    void on_twohours_clicked();

private:
    Ui::Timer *ui;
};

#endif // TIMER_H
