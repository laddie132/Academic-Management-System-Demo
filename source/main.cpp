#include <QDialog>
#include <QDebug>
#include <QApplication>
#include <QTextCodec>
#include <QCryptographicHash>

#include "login.h"
#include "user.h"
#include "include.h"
#include "environment.h"
#include "envir_widget.h"
#include "mainwindow_admin.h"
#include "mainwindow_student.h"
#include "mainwindow_teacher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));

    //�������л���
    Envir envir;
    QString default_name = "admin";         //Ĭ���˻�
    envir.addUserAdmin(default_name.toStdString(), default_name.toStdString(), QString::fromLocal8Bit("�����ѧԺ").toStdString());

    Envir_widget envir_widget;

    //���õ�¼����
    Login widget_login;
    widget_login.setEnvir(&envir, &envir_widget);

    //����������
    MainWindow_admin widget_main_admin;
    widget_main_admin.setEnvirWidget(&envir_widget);

    MainWindow_teacher widget_main_teacher;
    widget_main_teacher.setEnvirWidget(&envir_widget);

    MainWindow_student widget_main_student;
    widget_main_student.setEnvirWidget(&envir_widget);

    //��������������ָ��
    envir_widget.setWidget(&widget_login, &widget_main_student, &widget_main_teacher, &widget_main_admin);

    //��ʾ��¼����
    widget_login.show();

    return a.exec();
}
