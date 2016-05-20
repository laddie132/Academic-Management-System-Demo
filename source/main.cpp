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

    //设置运行环境
    Envir envir;
    QString default_name = "admin";         //默认账户
    envir.addUserAdmin(default_name.toStdString(), default_name.toStdString(), QString::fromLocal8Bit("计算机学院").toStdString());

    Envir_widget envir_widget;

    //设置登录界面
    Login widget_login;
    widget_login.setEnvir(&envir, &envir_widget);

    //设置主界面
    MainWindow_admin widget_main_admin;
    widget_main_admin.setEnvirWidget(&envir_widget);

    MainWindow_teacher widget_main_teacher;
    widget_main_teacher.setEnvirWidget(&envir_widget);

    MainWindow_student widget_main_student;
    widget_main_student.setEnvirWidget(&envir_widget);

    //保存所有主界面指针
    envir_widget.setWidget(&widget_login, &widget_main_student, &widget_main_teacher, &widget_main_admin);

    //显示登录界面
    widget_login.show();

    return a.exec();
}
