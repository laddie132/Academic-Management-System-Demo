#ifndef MAINWINDOW_STUDENT_H
#define MAINWINDOW_STUDENT_H

#include <QMainWindow>

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

    void initTable();       //表格信息初始化
    void updateTable();   //表格信息更新

    void setEnvirWidget(Envir_widget* envir_widget);
    void setUser(Student* user);   //设置当前登录用户

private:
    Ui::MainWindow_student *ui;
    Envir_widget* m_envir_widget;
    Student* m_user = NULL;
};

#endif // MAINWINDOW_STUDENT_H
