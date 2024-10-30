#ifndef TASK_H
#define TASK_H

#include <QDialog>

class Task
{
public:
    Task();
    Task(QString name, QString desc, QString deadline);
    QString GetName();
    QString GetDescription();
    QString GetDeadline();
    void SetName();
    void SetDescription();
    void SetDeadline();

private:
    QString taskname;
    QString deadline; // Temp QString until can be converted to int
    QString description;
    bool timer;
    bool completed;
    int timerTime;

};

#endif // TASK_H
