#include <QAction>
#include <QApplication>
#include <QMessageBox>
#include "mainwindow_admin.h"
#include "ui_mainwindow_admin.h"
#include "environment.h"

MainWindow_admin::MainWindow_admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_admin)
{
    ui->setupUi(this);
    creatAction();
}

MainWindow_admin::~MainWindow_admin()
{
    delete ui;
}

void MainWindow_admin::setEnvir(Envir* envir)
{
    this->m_envir = envir;
}

void MainWindow_admin::creatAction()
{
    connect(ui->action_login, SIGNAL(triggered()), this, SLOT(action_login_triggered()));
    connect(ui->action_quit, SIGNAL(triggered()), this, SLOT(action_quit_triggered()));
    connect(ui->action_course_o, SIGNAL(triggered()), this, SLOT(action_course_o_triggered()));
    connect(ui->action_course_e, SIGNAL(triggered()), this, SLOT(action_course_e_triggered()));
    connect(ui->action_course_add, SIGNAL(triggered()), this, SLOT(action_course_add_triggered()));
    connect(ui->action_student_d, SIGNAL(triggered()), this, SLOT(action_student_d_triggered()));
    connect(ui->action_teachet_d, SIGNAL(triggered()), this, SLOT(action_teacher_d_triggered()));
    connect(ui->action_admin_d, SIGNAL(triggered()), this, SLOT(action_admin_d_triggered()));
    connect(ui->action_student_add, SIGNAL(triggered()), this, SLOT(action_student_add_triggered()));
    connect(ui->action_teacher_add, SIGNAL(triggered()), this, SLOT(action_teachet_add_triggered()));
    connect(ui->action_admin_add, SIGNAL(triggered()), this, SLOT(action_admin_add_triggered()));
    connect(ui->action_start_course, SIGNAL(triggered()), this, SLOT(action_start_course_triggered()));
    connect(ui->action_about, SIGNAL(triggered()), this, SLOT(action_about_triggered()));
    connect(ui->action_help, SIGNAL(triggered()), this, SLOT(action_help_triggered()));
}

void MainWindow_admin::action_login_triggered()
{

}

void MainWindow_admin::action_quit_triggered()
{
    this->close();
}

void MainWindow_admin::action_course_o_triggered()
{

}

void MainWindow_admin::action_course_e_triggered()
{

}

void MainWindow_admin::action_course_add_triggered()
{

}

void MainWindow_admin::action_student_d_triggered()
{

}

void MainWindow_admin::action_teacher_d_triggered()
{

}

void MainWindow_admin::action_admin_d_triggered()
{

}

void MainWindow_admin::action_student_add_triggered()
{

}

void MainWindow_admin::action_teachet_add_triggered()
{

}

void MainWindow_admin::action_admin_add_triggered()
{

}

void MainWindow_admin::action_start_course_triggered()
{

}

void MainWindow_admin::action_about_triggered()
{
    QMessageBox::about(this,QString::fromLocal8Bit("关于"),
          QString::fromLocal8Bit(" <font color='red'>Students` Grade Manage System 1.1.0 (opensource)</font>"
                                 "<br>项目主页：https://github.com/laddie132/"
                                 " <br>作者：L.Laddie"
                               "  <br><br>Copyright 2016-2016 The Qt Company Ltd. All rights reserved." ));
}

void MainWindow_admin::action_help_triggered()
{

}
