#ifndef INFORMATION_COURSE_H
#define INFORMATION_COURSE_H

#include <QDialog>

namespace Ui {
class Information_course;
}

class Information_course : public QDialog
{
    Q_OBJECT

public:
    explicit Information_course(QWidget *parent = 0);
    ~Information_course();

private:
    Ui::Information_course *ui;
};

#endif // INFORMATION_COURSE_H
