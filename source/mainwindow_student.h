#ifndef MAINWINDOW_STUDENT_H
#define MAINWINDOW_STUDENT_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "include.h"
#include "environment.h"
#include "envir_widget.h"

namespace Ui {
class MainWindow_student;
}

class MainWindow_student : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_student(QWidget *parent = 0);
    ~MainWindow_student();

    void initActivex();       //�ؼ���Ϣ��ʼ��
    void creatAction();

    void showInfo();           //��ʾ�û���Ϣ
    void updateTable();        //�����Ϣ��ʼ��

    void setEnvirWidget(Envir_widget* envir_widget);
    void setUser(Student* user);   //���õ�ǰ��¼�û�

private slots:
    void action_login_triggered();
    void action_quit_triggered();
    void action_course_o_triggered();
    void action_course_e_triggered();
    void action_start_course_triggered();
    void action_about_triggered();
    void action_help_triggered();
    void action_change_pass_triggered();

    void add_course_slots();
    void delete_course_slots();

private:
    Ui::MainWindow_student *ui;
    Envir_widget* m_envir_widget;
    QStandardItemModel* ui_course_model_o;
    QStandardItemModel* ui_course_model_e;
    QStandardItemModel* ui_course_model_s;

    Student* m_user = NULL;
};

#endif // MAINWINDOW_STUDENT_H
