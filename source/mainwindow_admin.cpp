#include <QAction>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTextCodec>

#include "user.h"
#include "mainwindow_admin.h"
#include "ui_mainwindow_admin.h"
#include "information_course.h"
#include "information_user.h"
#include "environment.h"
#include "envir_widget.h"

MainWindow_admin::MainWindow_admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_admin)
{
    ui->setupUi(this);
    creatAction();
    initTable();
    m_info_course_widget = new Information_course(this);
    m_info_user_widget = new Information_user(this);
}

MainWindow_admin::~MainWindow_admin()
{
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

void MainWindow_admin::initTable()
{
    //���ñ��޿��б�
    ui_course_model_o = new QStandardItemModel();
    ui_course_model_o->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("�γ̱��")));
    ui_course_model_o->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui_course_model_o->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("�γ�ѧ��")));
    ui_course_model_o->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui_course_model_o->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui_course_model_o->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui->tableView_course_o->setModel(ui_course_model_o);

    //����ѡ�޿��б�
    ui_course_model_e = new QStandardItemModel();
    ui_course_model_e->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("�γ̱��")));
    ui_course_model_e->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui_course_model_e->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("�γ�ѧ��")));
    ui_course_model_e->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui_course_model_e->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui_course_model_e->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("�γ�����")));
    ui->tableView_course_e->setModel(ui_course_model_e);

    //����ѧ���б�
    ui_student_model = new QStandardItemModel();
    ui_student_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("ѧ��")));
    ui_student_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("����")));
    ui_student_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("�༶")));
    ui_student_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("ѧԺ")));
    ui_student_model->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("����")));
    ui->tableView_student->setModel(ui_student_model);

    //���ý�ʦ�б�
    ui_teacher_model = new QStandardItemModel();
    ui_teacher_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("����")));
    ui_teacher_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("����")));
    ui_teacher_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("ѧԺ")));
    ui_teacher_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("����")));
    ui->tableView_teacher->setModel(ui_teacher_model);

    //���ù���Ա�б�
    ui_admin_model = new QStandardItemModel();
    ui_admin_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("�û���")));
    ui_admin_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("����")));
    ui_admin_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("ѧԺ")));
    ui_admin_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("����")));
    ui->tableView_admin->setModel(ui_admin_model);
}

void MainWindow_admin::updateTable()
{
    int row = 0;

    //���±��޿�
    for (auto i : m_user->getEnvir()->getObligatoryCourse())
    {
        ui_course_model_o->setItem(row, 0, new QStandardItem(QString::fromStdString(i->getID())));
        ui_course_model_o->setItem(row, 1, new QStandardItem(QString::fromStdString(i->getName())));
        ui_course_model_o->setItem(row, 2, new QStandardItem(QString::number(i->getCredit())));
        ui_course_model_o->setItem(row, 3, new QStandardItem(QString::fromLocal8Bit("����")));
        ui_course_model_o->setItem(row, 4, new QStandardItem(QString::number(i->getStudent().size())));
        ui_course_model_o->setItem(row, 5, new QStandardItem(QString::number(i->getCapicity())));
        row++;
    }

    //����ѡ�޿�
    row = 0;
    for(auto i : m_user->getEnvir()->getElectiveCourse())
    {
        ui_course_model_e->setItem(row, 0, new QStandardItem(QString::fromStdString(i->getID())));
        ui_course_model_e->setItem(row, 1, new QStandardItem(QString::fromStdString(i->getName())));
        ui_course_model_e->setItem(row, 2, new QStandardItem(QString::number(i->getCredit())));
        ui_course_model_e->setItem(row, 3, new QStandardItem(QString::fromLocal8Bit("ѡ��")));
        ui_course_model_e->setItem(row, 4, new QStandardItem(QString::number(i->getStudent().size())));
        ui_course_model_e->setItem(row, 5, new QStandardItem(QString::number(i->getCapicity())));
        row++;
    }

    //����ѧ���б�
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

    //���½�ʦ�б�
    row = 0;
    for(auto i : m_user->getEnvir()->getUserTeacher())
    {
        ui_teacher_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
        ui_teacher_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
        ui_teacher_model->setItem(row, 2, new QStandardItem(QString::fromStdString(i.first->getInsititude())));
        ui_teacher_model->setItem(row, 3, new QStandardItem(QString::fromStdString(i.second)));
        row++;
    }

    //���¹���Ա�б�
    row = 0;
    for(auto i : m_user->getEnvir()->getUserAdmin())
    {
        ui_admin_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
        ui_admin_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
        ui_admin_model->setItem(row, 2, new QStandardItem(QString::fromStdString(i.first->getInsititude())));
        ui_admin_model->setItem(row, 3, new QStandardItem(QString::fromStdString(i.second)));
        row++;
    }
}

//���Ӳ˵�����ť�Ĳۺ���
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
    connect(ui->action_user_add, SIGNAL(triggered()), this, SLOT(action_user_add_triggered()));
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
    ui->tabWidget_admin->setCurrentIndex(0);
}

void MainWindow_admin::action_course_e_triggered()
{
    ui->tabWidget_admin->setCurrentIndex(1);
}

void MainWindow_admin::action_course_add_triggered()
{
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
    m_info_user_widget->show();
}

void MainWindow_admin::action_start_course_triggered()
{

}

void MainWindow_admin::action_about_triggered()
{
    QMessageBox::about(this, QString::fromLocal8Bit("����"),
          QString::fromLocal8Bit(" <font color='red'>Students` Grade Manage System 1.1.0 (opensource)</font>"
                                 "<br>��Ŀ��ҳ��https://github.com/laddie132/StudentsGradeManageSystem"
                                 " <br>���ߣ�L.Laddie"
                               "  <br><br>Copyright 2016-2016 The Qt Company Ltd. All rights reserved." ));
}

void MainWindow_admin::action_help_triggered()
{

}
