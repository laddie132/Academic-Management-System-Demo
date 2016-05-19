#ifndef MAINWINDOW_ADMIN_H
#define MAINWINDOW_ADMIN_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "environment.h"
#include "envir_widget.h"

namespace Ui {
class MainWindow_admin;
}

class MainWindow_admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_admin(QWidget *parent = 0);
    ~MainWindow_admin();

    void setEnvirWidget(Envir_widget* envir_widget);
    void setUser(Admin* user);   //设置当前登录用户

    void creatAction();

    void showTable();   //表格信息初始化

private slots:
    void action_login_triggered();
    void action_quit_triggered();
    void action_course_o_triggered();
    void action_course_e_triggered();
    void action_course_add_triggered();
    void action_student_d_triggered();
    void action_teacher_d_triggered();
    void action_admin_d_triggered();
    void action_student_add_triggered();
    void action_teachet_add_triggered();
    void action_admin_add_triggered();
    void action_start_course_triggered();
    void action_about_triggered();
    void action_help_triggered();

private:
    Ui::MainWindow_admin *ui;
    Envir_widget* m_envir_widget;
    Admin* m_user = NULL;

    QStandardItemModel* ui_course_model_o;
};

#endif // MAINWINDOW_ADMIN_H
