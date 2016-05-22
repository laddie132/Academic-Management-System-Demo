#include <QMessageBox>

#include "mainwindow_student.h"
#include "ui_mainwindow_student.h"

MainWindow_student::MainWindow_student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_student)
{
    ui->setupUi(this);
    initActivex();
    creatAction();
}

MainWindow_student::~MainWindow_student()
{
    delete ui;
}

void MainWindow_student::setEnvirWidget(Envir_widget* envir_widget)
{
    this->m_envir_widget = envir_widget;
}

void MainWindow_student::setUser(Student* user)
{
    this->m_user = user;
}

void MainWindow_student::initActivex()
{
    ui_course_model_o = new QStandardItemModel();
    ui_course_model_e = new QStandardItemModel();
    ui_course_model_s = new QStandardItemModel();

    ui_course_model_o->sort(0);
    ui_course_model_e->sort(0);
    ui_course_model_s->sort(0);

    ui->tableView_course_o->setModel(ui_course_model_o);
    ui->tableView_course_e->setModel(ui_course_model_e);
    ui->tableView_course_s->setModel(ui_course_model_s);
}

void MainWindow_student::showInfo()
{
    ui->label_id->setText(QString::fromStdString(m_user->getID()));
    ui->label_name->setText(QString::fromStdString(m_user->getName()));
    ui->label_institude->setText(QString::fromStdString(m_user->getInsititude()));
    ui->label_class->setText(QString::fromStdString(m_user->getClass()));
    updateTable();
}

void MainWindow_student::updateTable()
{
    ui_course_model_o->clear();
    ui_course_model_e->clear();
    ui_course_model_s->clear();

    //设置必修课程列表
    ui_course_model_o->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model_o->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model_o->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model_o->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model_o->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程容量")));
    ui_course_model_o->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程成绩")));
    ui_course_model_o->setHorizontalHeaderItem(6, new QStandardItem(QString::fromLocal8Bit("课程绩点")));

    //设置选修课列表
    ui_course_model_e->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model_e->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model_e->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model_e->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model_e->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程容量")));
    ui_course_model_e->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程成绩")));
    ui_course_model_e->setHorizontalHeaderItem(6, new QStandardItem(QString::fromLocal8Bit("课程绩点")));

    //设置选课列表
    ui_course_model_s->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model_s->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model_s->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model_s->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model_s->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程人数")));
    ui_course_model_s->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程容量")));

    int row1 = 0, row2 = 0;

    //更新必修和选修课
    for (auto i : m_user->getGrade())
    {
        if(i.first->getCourseType()){
            ui_course_model_e->setItem(row2, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
            ui_course_model_e->setItem(row2, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
            ui_course_model_e->setItem(row2, 2, new QStandardItem(QString::number(i.first->getCredit())));
            ui_course_model_e->setItem(row2, 3, new QStandardItem(QString::fromLocal8Bit("选修")));
            ui_course_model_e->setItem(row2, 4, new QStandardItem(QString::number(i.first->getCapicity())));
            ui_course_model_e->setItem(row2, 5, new QStandardItem(QString("%1").arg(i.second)));
            ui_course_model_e->setItem(row2, 6, new QStandardItem(QString("%1").arg(i.first->calculateGPA(m_user))));
            row2++;
        }
        else{
            ui_course_model_o->setItem(row1, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
            ui_course_model_o->setItem(row1, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
            ui_course_model_o->setItem(row1, 2, new QStandardItem(QString::number(i.first->getCredit())));
            ui_course_model_o->setItem(row1, 3, new QStandardItem(QString::fromLocal8Bit("必修")));
            ui_course_model_o->setItem(row1, 4, new QStandardItem(QString::number(i.first->getCapicity())));
            ui_course_model_o->setItem(row1, 5, new QStandardItem(QString("%1").arg(i.second)));
            ui_course_model_o->setItem(row1, 6, new QStandardItem(QString("%1").arg(i.first->calculateGPA(m_user))));
            row1++;
        }
    }
}

//链接菜单栏按钮的槽函数
void MainWindow_student::creatAction()
{
    connect(ui->action_login, SIGNAL(triggered()), this, SLOT(action_login_triggered()));
    connect(ui->action_quit, SIGNAL(triggered()), this, SLOT(action_quit_triggered()));
    connect(ui->action_course_o, SIGNAL(triggered()), this, SLOT(action_course_o_triggered()));
    connect(ui->action_course_e, SIGNAL(triggered()), this, SLOT(action_course_e_triggered()));
    connect(ui->action_course_start, SIGNAL(triggered()), this, SLOT(action_start_course_triggered()));
    connect(ui->action_about, SIGNAL(triggered()), this, SLOT(action_about_triggered()));
    connect(ui->action_help, SIGNAL(triggered()), this, SLOT(action_help_triggered()));
    connect(ui->action_password, SIGNAL(triggered()), this, SLOT(action_change_pass_triggered()));
}

void MainWindow_student::action_login_triggered()
{
    this->close();
    m_envir_widget->showLoginWidget();
}

void MainWindow_student::action_quit_triggered()
{
    this->close();
}

void MainWindow_student::action_course_o_triggered()
{
    ui->tabWidget_student->setCurrentIndex(0);
}

void MainWindow_student::action_course_e_triggered()
{
    ui->tabWidget_student->setCurrentIndex(1);
}

void MainWindow_student::action_start_course_triggered()
{
    ui->tabWidget_student->setCurrentIndex(2);
}

void MainWindow_student::action_change_pass_triggered()
{

}

void MainWindow_student::action_about_triggered()
{
    QMessageBox::about(this, QString::fromLocal8Bit("关于"),
          QString::fromLocal8Bit(" <font color='red'>Students` Grade Manage System 1.1.0 (opensource)</font>"
                                 "<br>项目主页：https://github.com/laddie132/StudentsGradeManageSystem"
                                 " <br>作者：L.Laddie"
                               "  <br><br>Copyright 2016-2016 The Qt Company Ltd. All rights reserved." ));
}

void MainWindow_student::action_help_triggered()
{

}
