/**
 * Name: login.cpp
 * User: L.Laddie
 * Function: 登录界面
 */

#include <QDebug>
#include <QString>
#include <QCryptographicHash>
#include <QMessageBox>

#include "login.h"
#include "ui_login.h"
#include "environment.h"
#include "envir_widget.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->wrong_label->close();
    ui->hello_label->setAttribute(Qt::WA_TranslucentBackground);
    ui->password_label->setAttribute(Qt::WA_TranslucentBackground);
    ui->username_label->setAttribute(Qt::WA_TranslucentBackground);
    ui->gridLayoutWidget->setAttribute(Qt::WA_TranslucentBackground);
    ui->horizontalLayoutWidget->setAttribute(Qt::WA_TranslucentBackground);
    ui->wrong_label->setAttribute(Qt::WA_TranslucentBackground);
}

Login::~Login()
{
    delete ui;
}

void Login::setEnvir(Envir* envir, Envir_widget* envir_widget)
{
    this->m_envir = envir;
    this->m_envir_widget = envir_widget;
}

void Login::on_login_btn_clicked()
{
    QString username = ui->username_edit->text();
    QString password = ui->passowrd_edit->text();

    ui->passowrd_edit->clear();
    ui->wrong_label->close();

    //密码采用md5加密
    QByteArray temp = QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5);
    QString md5_password = temp.toHex();

    //寻找输入用户
    Student* user1 = m_envir->checkUserStudent(username.toStdString(), md5_password.toStdString());
    Teacher* user2 = m_envir->checkUserTeacher(username.toStdString(), md5_password.toStdString());
    Admin* user3 = m_envir->checkUserAdmin(username.toStdString(), md5_password.toStdString());

    //判断用户类型
    if(user1){
        this->close();
        m_envir->setCourseStudent(user1);   //设置学生课程权限类
        m_envir_widget->showStudentWidget(user1);
    }
    else{
        if(user2){
            this->close();
            m_envir->setCourseTeacher(user2);   //设置教师课程权限类
            m_envir_widget->showTeacherWidget(user2);
        }
        else{
            if(user3){
                this->close();
                user3->activateEnvir(m_envir);     //设置管理员系统权限
                m_envir_widget->showAdminWidget(user3);
            }
            else{
        //        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("用户名或密码错误！"),QMessageBox::Yes);
                ui->wrong_label->show();
            }
        }
    }
}

void Login::on_cancel_btn_clicked()
{
    this->close();
    exit(0);
}
