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

    //�������md5����
    QByteArray temp = QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5);
    QString md5_password = temp.toHex();

    //Ѱ�������û�
    Student* user1 = m_envir->checkUserStudent(username.toStdString(), md5_password.toStdString());
    Teacher* user2 = m_envir->checkUserTeacher(username.toStdString(), md5_password.toStdString());
    Admin* user3 = m_envir->checkUserAdmin(username.toStdString(), md5_password.toStdString());

    //�ж��û�����
    if(user1){
        this->close();
        m_envir->setCourseStudent(user1);   //����ѧ���γ�Ȩ����
        m_envir_widget->showStudentWidget(user1);
    }
    else{
        if(user2){
            this->close();
            m_envir->setCourseTeacher(user2);   //���ý�ʦ�γ�Ȩ����
            m_envir_widget->showTeacherWidget(user2);
        }
        else{
            if(user3){
                this->close();
                user3->activateEnvir(m_envir);     //���ù���ԱϵͳȨ��
                m_envir_widget->showAdminWidget(user3);
            }
            else{
        //        QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�û������������"),QMessageBox::Yes);
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
