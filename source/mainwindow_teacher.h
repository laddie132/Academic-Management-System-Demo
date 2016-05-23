#ifndef MAINWINDOW_TEACHER_H
#define MAINWINDOW_TEACHER_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "include.h"
#include "environment.h"
#include "envir_widget.h"

namespace Ui {
class MainWindow_teacher;
}

class MainWindow_teacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_teacher(QWidget *parent = 0);
    ~MainWindow_teacher();

    void initActivex();       //�ؼ���Ϣ��ʼ��
    void creatAction();

    void showInfo();           //��ʾ�û���Ϣ
    void updateTable();      //�����Ϣ����
    void updateStudent();       //����ѧ���б�

    void setEnvirWidget(Envir_widget* envir_widget);
    void setUser(Teacher* user);   //���õ�ǰ��¼�û�

private slots:
    void action_login_triggered();
    void action_quit_triggered();
    void action_course_triggered();
    void action_set_grade_triggered();
    void action_about_triggered();
    void action_help_triggered();
    void action_change_pass_triggered();

    void on_comboBox_course_currentIndexChanged(int index);

    void on_cancel_btn_clicked();

    void on_confirm_btn_clicked();

private:
    Ui::MainWindow_teacher *ui;
    Envir_widget* m_envir_widget;
    QStandardItemModel* ui_course_model;
    QStandardItemModel* ui_student_model;

    Teacher* m_user = NULL;
};

#endif // MAINWINDOW_TEACHER_H
