#ifndef INFORMATION_COURSE_H
#define INFORMATION_COURSE_H

#include <QDialog>
#include "include.h"
#include "user.h"

namespace Ui {
class Information_course;
}

class Information_course : public QDialog
{
    Q_OBJECT

public:
    explicit Information_course(QWidget *parent = 0);
    ~Information_course();

    void setUser(Admin* admin);

signals:
    void addCourse();

private slots:
    void on_confirm_btn_clicked();

    void on_cancel_btn_clicked();

    void on_comboBox_type_currentIndexChanged(int index);

private:
    Ui::Information_course *ui;
    Admin* m_user;
};

#endif // INFORMATION_COURSE_H
