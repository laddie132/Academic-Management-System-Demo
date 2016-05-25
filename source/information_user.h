#ifndef INFORMATION_USER_H
#define INFORMATION_USER_H

#include <QDialog>
#include <QStandardItemModel>
#include "user.h"

namespace Ui {
class Information_user;
}

class Information_user : public QDialog
{
    Q_OBJECT

public:
    explicit Information_user(QWidget *parent = 0);
    ~Information_user();

    void setUser_admin(Admin* admin);
    void setUser(User* user);

    void showInfo();
    void updateCourse();

    void creatActivex();

    void addCourse(User* user);       //将所选择课程添加到学生
    void deleteCourse();              //先删除课程再更新课程

signals:
    void updateUser();

private slots:
    void on_cancel_btn_clicked();

    void on_comboBox_user_type_currentIndexChanged(int index);

    void on_add_btn_clicked();

    void on_update_btn_clicked();

    void on_del_btn_clicked();

    void on_select_course_btn_clicked();

    void on_cancel_course_btn_clicked();

private:
    Ui::Information_user *ui;
    QStandardItemModel* ui_course_model_n;
    QStandardItemModel* ui_course_model_y;

    Admin* m_admin = NULL;
    User* m_user = NULL;

    std::set<Course*> prepare_delete;
};

#endif // INFORMATION_USER_H
