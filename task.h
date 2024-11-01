#ifndef TASK_H
#define TASK_H

#include <QString>

class Task
{
public:
    // Constructors
    Task();
    Task(const QString &name, const QString &desc, const QString &deadline);

    // Getter methods
    QString getTaskname() const;
    QString getDescription() const; // Fix: Place const after method signature
    QString getDeadline() const;

    // Setter methods (public if you need to modify the task from outside)
    void setName(const QString &name);
    void setDescription(const QString &desc);
    void setDeadline(const QString &deadline);

private:
    // Data members
    QString taskname;
    QString description;
    QString deadline; // Keep as QString for flexibility
    bool timer = false;
    bool completed = false;
    int timerTime = 0;
};

#endif // TASK_H
