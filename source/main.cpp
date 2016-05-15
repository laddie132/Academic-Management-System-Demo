#include <QDialog>
#include <QDebug>
#include <QApplication>
#include <QCryptographicHash>

#include "login.h"
#include "user.h"
#include "include.h"
#include "environment.h"
#include "mainwindow_admin.h"
#include "mainwindow_student.h"
#include "mainwindow_teacher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置运行环境
    Envir envir;
    QString default_name = "admin";
    envir.addUserAdmin(default_name.toStdString(), default_name.toStdString(), "计算机");

    //设置登录界面
    Login widget_login;
    widget_login.setEnvir(&envir);
    widget_login.show();

    //设置主界面
    MainWindow_admin widget_main_admin;
    widget_main_admin.setEnvir(&envir);

    MainWindow_teacher widget_main_teacher;
    MainWindow_student widget_main_student;
    User* user;
    if(widget_login.exec() == QDialog::Accepted){
        user = widget_login.getCurrentUser();
        switch (user->getUserType()) {
        case 0:
            widget_main_admin.show();
            break;
        case 1:
            widget_main_teacher.show();
            break;
        case 2:
            widget_main_student.show();
            break;
        default:
            break;
        }
    }
    return a.exec();
}
