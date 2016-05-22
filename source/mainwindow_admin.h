#ifndef MAINWINDOW_ADMIN_H
#define MAINWINDOW_ADMIN_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "environment.h"
#include "envir_widget.h"
#include "information_course.h"
#include "information_user.h"

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
    void setUser(Admin* user);   //���õ�ǰ��¼�û�

    void creatAction();

    void showInfo();         //��ʾ�û���Ϣ
    void initTable();       //�����Ϣ��ʼ��
    void updateTable();    //�����Ϣ����

private slots:
    void action_login_triggered();
    void action_quit_triggered();
    void action_course_o_triggered();
    void action_course_e_triggered();
    void action_course_add_triggered();
    void action_student_d_triggered();
    void action_teacher_d_triggered();
    void action_admin_d_triggered();
    void action_user_add_triggered();
    void action_start_course_triggered();
    void action_about_triggered();
    void action_help_triggered();

    void updateTable_slots();
    void update_course_slots();
    void update_user_slots();

private:
    Ui::MainWindow_admin *ui;
    Envir_widget* m_envir_widget;
    Admin* m_user = NULL;

    QStandardItemModel* ui_course_model_o;
    QStandardItemModel* ui_course_model_e;
    QStandardItemModel* ui_student_model;
    QStandardItemModel* ui_teacher_model;
    QStandardItemModel* ui_admin_model;

    Information_course* m_info_course_widget;
    Information_user* m_info_user_widget;
};

#endif // MAINWINDOW_ADMIN_H
