#ifndef MAINWINDOW_TEACHER_H
#define MAINWINDOW_TEACHER_H

#include <QMainWindow>

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

    void showInfo();           //��ʾ�û���Ϣ
    void initActivex();       //�ؼ���Ϣ��ʼ��
    void updateTable();      //�����Ϣ����

    void setEnvirWidget(Envir_widget* envir_widget);
    void setUser(Teacher* user);   //���õ�ǰ��¼�û�

private slots:
    void action_about_triggered();

private:
    Ui::MainWindow_teacher *ui;
    Envir_widget* m_envir_widget;
    QStandardItemModel* ui_info_course;

    Teacher* m_user = NULL;
};

#endif // MAINWINDOW_TEACHER_H
