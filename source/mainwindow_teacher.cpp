#include <QMessageBox>

#include "mainwindow_teacher.h"
#include "ui_mainwindow_teacher.h"

MainWindow_teacher::MainWindow_teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_teacher)
{
    ui->setupUi(this);
    initActivex();
    creatAction();
}

MainWindow_teacher::~MainWindow_teacher()
{
    delete ui;
}

void MainWindow_teacher::setEnvirWidget(Envir_widget* envir_widget)
{
    this->m_envir_widget = envir_widget;
}

void MainWindow_teacher::setUser(Teacher* user)
{
    this->m_user = user;
}

void MainWindow_teacher::initActivex()
{
    ui_course_model = new QStandardItemModel();
    ui_course_model->sort(0);
    ui->tableView_course->setModel(ui_course_model);
}

void MainWindow_teacher::updateTable()
{
    ui_course_model->clear();

    //设置必修课程列表
    ui_course_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程人数")));
    ui_course_model->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程容量")));

    int row = 0;
    for(auto i : m_user->getCourse())
    {
        ui_course_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i->getID())));
        ui_course_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i->getName())));
        ui_course_model->setItem(row, 2, new QStandardItem(QString::number(i->getCredit())));
        ui_course_model->setItem(row, 3, new QStandardItem(i->getCourseType() ? QString::fromLocal8Bit("选修") : QString::fromLocal8Bit("必修")));
        ui_course_model->setItem(row, 4, new QStandardItem(QString::number(i->getStudent().size())));
        ui_course_model->setItem(row, 5, new QStandardItem(QString::number(i->getCapicity())));
        row++;
    }
}

void MainWindow_teacher::showInfo()
{
    ui->label_id->setText(QString::fromStdString(m_user->getID()));
    ui->label_name->setText(QString::fromStdString(m_user->getName()));
    ui->label_institude->setText(QString::fromStdString(m_user->getInsititude()));
    updateTable();
}

//链接菜单栏按钮的槽函数
void MainWindow_teacher::creatAction()
{
    connect(ui->action_login, SIGNAL(triggered()), this, SLOT(action_login_triggered()));
    connect(ui->action_quit, SIGNAL(triggered()), this, SLOT(action_quit_triggered()));
    connect(ui->action_course, SIGNAL(triggered()), this, SLOT(action_course_triggered()));
    connect(ui->action_set_grade, SIGNAL(triggered()), this, SLOT(action_set_grade_triggered()));
    connect(ui->action_about, SIGNAL(triggered()), this, SLOT(action_about_triggered()));
    connect(ui->action_help, SIGNAL(triggered()), this, SLOT(action_help_triggered()));
    connect(ui->action_password, SIGNAL(triggered()), this, SLOT(action_change_pass_triggered()));

    connect(ui->set_grade_btn, SIGNAL(clicked()), this, SLOT(action_set_grade_triggered()));
}

void MainWindow_teacher::action_login_triggered()
{
    this->close();
    m_envir_widget->showLoginWidget();
}

void MainWindow_teacher::action_quit_triggered()
{
    this->close();
}

void MainWindow_teacher::action_course_triggered()
{
    ui->tabWidget_teacher->setCurrentIndex(0);
}

void MainWindow_teacher::action_set_grade_triggered()
{
    ui->tabWidget_teacher->setCurrentIndex(1);
}

void MainWindow_teacher::action_change_pass_triggered()
{

}

void MainWindow_teacher::action_about_triggered()
{
    QMessageBox::about(this, QString::fromLocal8Bit("关于"),
          QString::fromLocal8Bit(" <font color='red'>Students` Grade Manage System 1.1.0 (opensource)</font>"
                                 "<br>项目主页：https://github.com/laddie132/StudentsGradeManageSystem"
                                 " <br>作者：L.Laddie"
                               "  <br><br>Copyright 2016-2016 The Qt Company Ltd. All rights reserved." ));
}

void MainWindow_teacher::action_help_triggered()
{

}
