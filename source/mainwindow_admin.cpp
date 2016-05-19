#include <QAction>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTextCodec>

#include "user.h"
#include "mainwindow_admin.h"
#include "ui_mainwindow_admin.h"
#include "environment.h"
#include "envir_widget.h"

MainWindow_admin::MainWindow_admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_admin)
{
    ui->setupUi(this);
    creatAction();
}

MainWindow_admin::~MainWindow_admin()
{
    delete ui_course_model_o;
    delete ui;
}

void MainWindow_admin::setEnvirWidget(Envir_widget* envir_widget)
{
    this->m_envir_widget = envir_widget;
}

void MainWindow_admin::setUser(Admin* user)
{
    this->m_user = user;
}

void MainWindow_admin::showTable()
{
    ui_course_model_o = new QStandardItemModel();
    ui_course_model_o->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model_o->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model_o->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model_o->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model_o->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程人数")));
    ui_course_model_o->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程容量")));

    ui->tableView_course_o->setModel(ui_course_model_o);

    int row = 0;
    for (auto i : m_user->getCourse())
    {
        ui_course_model_o->setItem(row, 0, new QStandardItem(QString::fromStdString(i->getID())));
        ui_course_model_o->setItem(row, 1, new QStandardItem(QString::fromStdString(i->getName())));
        ui_course_model_o->setItem(row, 2, new QStandardItem(QString::number(i->getCredit())));
        ui_course_model_o->setItem(row, 3, new QStandardItem(QString::fromLocal8Bit("必修")));
        ui_course_model_o->setItem(row, 4, new QStandardItem(QString::number(i->getStudent().size())));
        ui_course_model_o->setItem(row, 5, new QStandardItem(QString::number(i->getCapicity())));
        row++;
    }
}

//链接菜单栏按钮的槽函数
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
    this->close();
    m_envir_widget->showLoginWidget();
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
    QMessageBox::about(this, QString::fromLocal8Bit("关于"),
          QString::fromLocal8Bit(" <font color='red'>Students` Grade Manage System 1.1.0 (opensource)</font>"
                                 "<br>项目主页：https://github.com/laddie132/StudentsGradeManageSystem"
                                 " <br>作者：L.Laddie"
                               "  <br><br>Copyright 2016-2016 The Qt Company Ltd. All rights reserved." ));
}

void MainWindow_admin::action_help_triggered()
{

}
