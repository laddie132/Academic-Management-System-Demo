#ifndef INFORMATION_COURSE_H
#define INFORMATION_COURSE_H

#include <QDialog>
#include <QStandardItemModel>

#include "include.h"

namespace Ui {
class Information_course;
}

class Information_course : public QDialog
{
    Q_OBJECT

public:
    explicit Information_course(QWidget *parent = 0);
    ~Information_course();

//    void setCourse(Course* course);

    void showInfo();
    void updateStudent();

    void creatActivex();

    void addStudent(Course* course);       //从选择框获取学生并添加到课程

signals:
    void updateCourse();
    void updateConfig();

private slots:
    void on_add_btn_clicked();

    void on_cancel_btn_clicked();

    void on_comboBox_type_currentIndexChanged(int index);

    void on_update_btn_clicked();

    void on_del_btn_clicked();

    void on_select_student_btn_clicked();

    void on_cancel_student_btn_clicked();

    void on_comboBox_teacher_currentIndexChanged(const QString &arg1);

private:
    Ui::Information_course *ui;
    QStandardItemModel* ui_student_model_n;
    QStandardItemModel* ui_student_model_y;

//    Course* m_course = NULL;
};

#endif // INFORMATION_COURSE_H
