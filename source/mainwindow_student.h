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

    void initActivex();       //控件信息初始化

    void showInfo();           //显示用户信息
    void updateTable();        //表格信息初始化

    void setEnvirWidget(Envir_widget* envir_widget);
    void setUser(Student* user);   //设置当前登录用户

private slots:
    void action_about_triggered();

private:
    Ui::MainWindow_student *ui;
    Envir_widget* m_envir_widget;
    QStandardItemModel* ui_course_model_o;
    QStandardItemModel* ui_course_model_e;
    QStandardItemModel* ui_course_model_s;

    Student* m_user = NULL;
};

#endif // MAINWINDOW_STUDENT_H
