/**
 * Name: main.cpp
 * User: L.Laddie
 * Function: 主函数入口
 */

#include <QDialog>
#include <QDebug>
#include <QApplication>
#include <QTextCodec>
#include <QMessageBox>
#include <QCryptographicHash>

#include "login.h"
#include "user.h"
#include "config.h"
#include "include.h"
#include "environment.h"
#include "envir_widget.h"
#include "mainwindow_admin.h"
#include "mainwindow_student.h"
#include "mainwindow_teacher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/image/icon.ico"));

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

    //设置运行环境
    Envir envir;

    //设置配置文件
    Config_file config;
    config.setEnvir(&envir);

    //设置界面环境
    Envir_widget envir_widget;
    envir_widget.setConfigFile(&config);

    //设置登录界面
    Login widget_login;
    widget_login.setEnvir(&envir, &envir_widget);

    //设置主界面
    MainWindow_admin widget_main_admin(&envir_widget);
    MainWindow_teacher widget_main_teacher(&envir_widget);
    MainWindow_student widget_main_student(&envir_widget);

    //保存所有主界面指针
    envir_widget.setWidget(&widget_login, &widget_main_student, &widget_main_teacher, &widget_main_admin);

    //读取配置文件
    try{
        config.readConfig();
    }
    catch(std::runtime_error &e){
        QMessageBox::warning(&widget_main_admin, QString::fromLocal8Bit("警告"), QString::fromStdString(e.what()));
        exit(1);
    }

    //显示登录界面
    widget_login.show();

    return a.exec();
}
