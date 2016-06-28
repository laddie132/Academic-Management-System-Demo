/**
 * Name: mainwindow_admin.cpp
 * User: L.Laddie
 * Function: 管理员界面
 */

#include <QAction>
#include <QDebug>
#include <QFont>
#include <QDateTime>
#include <QtSql/QSqlRecord>
#include <QApplication>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTextCodec>

#include "mainwindow_admin.h"
#include "ui_mainwindow_admin.h"
#include "information_course.h"
#include "information_user.h"
#include "envir_widget.h"

MainWindow_admin::MainWindow_admin(Envir_widget* envir_widget, QWidget *parent) :
    QMainWindow(parent),
    m_envir_widget(envir_widget),
    ui(new Ui::MainWindow_admin)
{
    ui->setupUi(this);
    setFixedSize(800, 500);         //禁止更改大小

    initActivex();       //初始化控件信息
    creatAction();      //链接信号与槽    
    initStatusBar();    //初始化状态栏
}

MainWindow_admin::~MainWindow_admin()
{
    delete ui_label_status;
    delete ui_course_model_o;
    delete ui_course_model_e;
    delete ui_student_model;
    delete ui_teacher_model;
    delete ui_admin_model;
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

//初始化控件信息
void MainWindow_admin::initActivex()
{
    ui_label_status = new QLabel();
    ui_label_time = new QLabel();
    m_timer_status = new QTimer(this);
    m_info_course_widget = new Information_course(this);
    m_info_user_widget = new Information_user(this);

    ui_course_model_o = new QStandardItemModel();
    ui->tableView_course_o->setModel(ui_course_model_o);

    ui_course_model_e = new QStandardItemModel();
    ui->tableView_course_e->setModel(ui_course_model_e);

    ui_student_model = new QStandardItemModel();
    ui->tableView_student->setModel(ui_student_model);

    ui_teacher_model = new QStandardItemModel();
    ui->tableView_teacher->setModel(ui_teacher_model);

    ui_admin_model = new QStandardItemModel();
    ui->tableView_admin->setModel(ui_admin_model);
}

//初始化状态栏信息
void MainWindow_admin::initStatusBar()
{
    ui_label_time->setAlignment(Qt::AlignRight);

    ui->statusbar->addWidget(ui_label_status, 1);
    ui->statusbar->addWidget(ui_label_time, 6);
    ui->statusbar->setStyleSheet(QString("QStatusBar::item{border: 0px}, *{font-size : 8px}"));
}

//定时更新状态栏
void MainWindow_admin::updateStatusBar()
{
    //设置实时人数信息
    QString student_num = "学生：" + QString::number(m_user->getEnvir()->getUserStudent().size()) + "人";
    QString teacher_num = "教师：" + QString::number(m_user->getEnvir()->getUserTeacher().size()) + "人";
    QString admin_num = "管理员：" + QString::number(m_user->getEnvir()->getUserAdmin().size()) + "人";
    QString obligatory_num = "必修课：" + QString::number(m_user->getEnvir()->getObligatoryCourse().size()) + "个";
    QString elective_num = "选修课：" + QString::number(m_user->getEnvir()->getElectiveCourse().size()) + "个";
    ui_label_status->setText("实时信息：" + student_num + " " + teacher_num + " " + admin_num + " " + obligatory_num + " " + elective_num);

    //设置实时系统时间
    QDateTime cur_time = QDateTime::currentDateTime();
    QString cur_time_str = cur_time.toString("hh:mm:ss");
    ui_label_time->setText("系统时间：" + cur_time_str);
}

//初次进入界面更新信息
void MainWindow_admin::showInfo()
{
    ui->label_id->setText(QString::fromStdString(m_user->getID()));
    ui->label_name->setText(QString::fromStdString(m_user->getName()));
    ui->label_institude->setText(QString::fromStdString(m_user->getInsititude()));
    updateTable();   

    updateStatusBar();
    m_timer_status->start(1000);        //每一秒刷新一次状态栏
}

//更新表格信息
void MainWindow_admin::updateTable()
{
    ui_course_model_o->clear();
    ui_course_model_e->clear();
    ui_student_model->clear();
    ui_teacher_model->clear();
    ui_admin_model->clear();

    //设置必修课列表
    ui_course_model_o->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model_o->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model_o->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model_o->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model_o->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程人数")));
    ui_course_model_o->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程容量")));

    //设置选修课列表
    ui_course_model_e->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model_e->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model_e->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model_e->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model_e->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程人数")));
    ui_course_model_e->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程容量")));

    //设置学生列表
    ui_student_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("学号")));
    ui_student_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("姓名")));
    ui_student_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("班级")));
    ui_student_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("学院")));
    ui_student_model->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("密码")));
    ui->tableView_student->setColumnWidth(4, 220);

    //设置教师列表
    ui_teacher_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("工号")));
    ui_teacher_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("姓名")));
    ui_teacher_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("学院")));
    ui_teacher_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("密码")));
    ui->tableView_teacher->setColumnWidth(3, 250);

    //设置管理员列表
    ui_admin_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("用户名")));
    ui_admin_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("姓名")));
    ui_admin_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("学院")));
    ui_admin_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("密码")));
    ui->tableView_admin->setColumnWidth(3, 250);

    int row = 0;

    //更新必修课
    for (auto i : m_user->getEnvir()->getObligatoryCourse())
    {
        ui_course_model_o->setItem(row, 0, new QStandardItem(QString::fromStdString(i->getID())));
        ui_course_model_o->setItem(row, 1, new QStandardItem(QString::fromStdString(i->getName())));
        ui_course_model_o->setItem(row, 2, new QStandardItem(QString::number(i->getCredit())));
        ui_course_model_o->setItem(row, 3, new QStandardItem(QString::fromLocal8Bit("必修")));
        ui_course_model_o->setItem(row, 4, new QStandardItem(QString::number(i->getStudent().size())));
        ui_course_model_o->setItem(row, 5, new QStandardItem(QString::number(i->getCapicity())));
        row++;
    }

    //更新选修课
    row = 0;
    for(auto i : m_user->getEnvir()->getElectiveCourse())
    {
        ui_course_model_e->setItem(row, 0, new QStandardItem(QString::fromStdString(i->getID())));
        ui_course_model_e->setItem(row, 1, new QStandardItem(QString::fromStdString(i->getName())));
        ui_course_model_e->setItem(row, 2, new QStandardItem(QString::number(i->getCredit())));
        ui_course_model_e->setItem(row, 3, new QStandardItem(QString::fromLocal8Bit("选修")));
        ui_course_model_e->setItem(row, 4, new QStandardItem(QString::number(i->getStudent().size())));
        ui_course_model_e->setItem(row, 5, new QStandardItem(QString::number(i->getCapicity())));
        row++;
    }

    //更新学生列表
    row = 0;
    for(auto i : m_user->getEnvir()->getUserStudent())
    {
        ui_student_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
        ui_student_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
        ui_student_model->setItem(row, 2, new QStandardItem(QString::fromStdString(i.first->getClass())));
        ui_student_model->setItem(row, 3, new QStandardItem(QString::fromStdString(i.first->getInsititude())));
        ui_student_model->setItem(row, 4, new QStandardItem(QString::fromStdString(i.second)));
        row++;
    }

    //更新教师列表
    row = 0;
    for(auto i : m_user->getEnvir()->getUserTeacher())
    {
        ui_teacher_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
        ui_teacher_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
        ui_teacher_model->setItem(row, 2, new QStandardItem(QString::fromStdString(i.first->getInsititude())));
        ui_teacher_model->setItem(row, 3, new QStandardItem(QString::fromStdString(i.second)));
        row++;
    }

    //更新管理员列表
    row = 0;
    for(auto i : m_user->getEnvir()->getUserAdmin())
    {
        ui_admin_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
        ui_admin_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
        ui_admin_model->setItem(row, 2, new QStandardItem(QString::fromStdString(i.first->getInsititude())));
        ui_admin_model->setItem(row, 3, new QStandardItem(QString::fromStdString(i.second)));
        row++;
    }

    //排序
    ui_course_model_o->sort(0);
    ui_course_model_e->sort(0);
    ui_student_model->sort(0);
    ui_teacher_model->sort(0);
    ui_admin_model->sort(0);
}

//链接各项槽函数
void MainWindow_admin::creatAction()
{
    //菜单栏
    connect(ui->action_login, SIGNAL(triggered()), this, SLOT(action_login_triggered()));
    connect(ui->action_quit, SIGNAL(triggered()), this, SLOT(action_quit_triggered()));
    connect(ui->action_course_o, SIGNAL(triggered()), this, SLOT(action_course_o_triggered()));
    connect(ui->action_course_e, SIGNAL(triggered()), this, SLOT(action_course_e_triggered()));
    connect(ui->action_course_add, SIGNAL(triggered()), this, SLOT(action_course_add_triggered()));
    connect(ui->action_student_d, SIGNAL(triggered()), this, SLOT(action_student_d_triggered()));
    connect(ui->action_teachet_d, SIGNAL(triggered()), this, SLOT(action_teacher_d_triggered()));
    connect(ui->action_admin_d, SIGNAL(triggered()), this, SLOT(action_admin_d_triggered()));
    connect(ui->action_user_add, SIGNAL(triggered()), this, SLOT(action_user_add_triggered()));
    connect(ui->action_start_course, SIGNAL(triggered()), this, SLOT(action_start_course_triggered()));
    connect(ui->action_about, SIGNAL(triggered()), this, SLOT(action_about_triggered()));
    connect(ui->action_help, SIGNAL(triggered()), this, SLOT(action_help_triggered()));

    //子界面信号
    connect(m_info_user_widget, SIGNAL(updateUser()), this, SLOT(updateTable_slots()));
    connect(m_info_course_widget, SIGNAL(updateCourse()), this, SLOT(updateTable_slots()));
    connect(m_info_user_widget, SIGNAL(updateConfig()), this->m_envir_widget, SLOT(updateConfig()));
    connect(m_info_course_widget, SIGNAL(updateConfig()), this->m_envir_widget, SLOT(updateConfig()));

    //表格项目双击事件
    connect(ui->tableView_course_o, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(update_course_slots()));
    connect(ui->tableView_course_e, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(update_course_slots()));
    connect(ui->tableView_student, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(update_user_slots()));
    connect(ui->tableView_teacher, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(update_user_slots()));
    connect(ui->tableView_admin, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(update_user_slots()));

    //界面按钮
    connect(ui->add_course_btn, SIGNAL(clicked()), this, SLOT(action_course_add_triggered()));
    connect(ui->add_user_btn, SIGNAL(clicked()), this, SLOT(action_user_add_triggered()));

    //状态栏计时器
    connect(m_timer_status, SIGNAL(timeout()), this, SLOT(updateStatusBar()));
}

void MainWindow_admin::action_login_triggered()
{
    if(m_timer_status->isActive()){
        m_timer_status->stop();         //停止状态栏计时器
    }
    this->close();
    m_envir_widget->showLoginWidget();
}

void MainWindow_admin::action_quit_triggered()
{
    if(m_timer_status->isActive()){
        m_timer_status->stop();         //停止状态栏计时器
    }
    this->close();
}

void MainWindow_admin::action_course_o_triggered()
{
    ui->tabWidget_admin->setCurrentIndex(0);
}

void MainWindow_admin::action_course_e_triggered()
{
    ui->tabWidget_admin->setCurrentIndex(1);
}

void MainWindow_admin::action_course_add_triggered()
{
    m_info_course_widget->setUser(m_user);
    m_info_course_widget->setCourse(NULL);
    m_info_course_widget->showInfo();
    m_info_course_widget->show();
}

void MainWindow_admin::action_student_d_triggered()
{
    ui->tabWidget_admin->setCurrentIndex(2);
}

void MainWindow_admin::action_teacher_d_triggered()
{
    ui->tabWidget_admin->setCurrentIndex(3);
}

void MainWindow_admin::action_admin_d_triggered()
{
    ui->tabWidget_admin->setCurrentIndex(4);
}

void MainWindow_admin::action_user_add_triggered()
{
    m_info_user_widget->setUser_admin(m_user);
    m_info_user_widget->setUser(NULL);
    m_info_user_widget->showInfo();
    m_info_user_widget->show();
}

void MainWindow_admin::action_start_course_triggered()
{

}

void MainWindow_admin::action_about_triggered()
{
    QMessageBox::about(this, QString::fromLocal8Bit("关于"),
          QString::fromLocal8Bit(" <font color='red'>Students` Grade Manage System 2.9.0 (opensource)</font>"
                                 "<br>项目主页：https://github.com/laddie132/StudentsGradeManageSystem"
                                 " <br>作者：L.Laddie"
                               "  <br><br>Copyright 2016-2016 The Qt Company Ltd. All rights reserved." ));
}

void MainWindow_admin::action_help_triggered()
{

}

void MainWindow_admin::updateTable_slots()
{
    updateTable();
}

//修改某一门课程
void MainWindow_admin::update_course_slots()
{
    QString id;
    int tab = ui->tabWidget_admin->currentIndex();
    switch(tab)
    {
    case 0:
    {
        int row = ui->tableView_course_o->currentIndex().row();
        id = ui_course_model_o->item(row, 0)->text();
        break;
    }

    case 1:
    {
        int row = ui->tableView_course_e->currentIndex().row();
        id = ui_course_model_e->item(row, 0)->text();
        break;
    }

    default:
        break;
    }
    Course* course = m_user->getEnvir()->findCourse(id.toStdString());

    m_info_course_widget->setUser(m_user);
    m_info_course_widget->setCourse(course);
    m_info_course_widget->showInfo();
    m_info_course_widget->show();
}

//修改某一个用户
void MainWindow_admin::update_user_slots()
{
    QString id;
    int tab = ui->tabWidget_admin->currentIndex();
    User* temp;
    switch(tab)
    {
    case 2:
    {
        int row = ui->tableView_student->currentIndex().row();
        id = ui_student_model->item(row, 0)->text();
        temp = m_user->getEnvir()->findUser(id.toStdString());
        m_user->getEnvir()->setCourseStudent((Student*)temp);   //初始化学生权限课程
        break;
    }

    case 3:
    {
        int row = ui->tableView_teacher->currentIndex().row();
        id = ui_teacher_model->item(row, 0)->text();
        temp = m_user->getEnvir()->findUser(id.toStdString());
        m_user->getEnvir()->setCourseTeacher((Teacher*)temp);   //初始化教师权限课程
        break;
    }

    case 4:
    {
        int row = ui->tableView_admin->currentIndex().row();
        id = ui_admin_model->item(row, 0)->text();
        temp = m_user->getEnvir()->findUser(id.toStdString());
        break;
    }

    default:
        break;
    }

    m_info_user_widget->setUser_admin(m_user);
    m_info_user_widget->setUser(temp);
    m_info_user_widget->showInfo();
    m_info_user_widget->show();
}
