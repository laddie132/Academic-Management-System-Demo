#include <QDebug>
#include <QString>
#include <QCryptographicHash>
#include <QMessageBox>

#include "login.h"
#include "ui_login.h"
#include "environment.h"

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

void Login::setEnvir(Envir* envir)
{
    this->m_envir = envir;
}

User* Login::getCurrentUser()
{
    return m_user;
}

void Login::on_login_btn_clicked()
{
    QString username = ui->username_edit->text();
    QString password = ui->passowrd_edit->text();
    //密码采用md5加密
    QByteArray temp = QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5);
    QString md5_password = temp.toHex();
    m_user = m_envir->checkUser(username.toStdString(), md5_password.toStdString());
    if(m_user != NULL){
        this->close();
        accept();
    }
    else{
//        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("用户名或密码错误！"),QMessageBox::Yes);
        ui->wrong_label->show();
//        ui->username_edit->clear();
        ui->passowrd_edit->clear();
    }
}

void Login::on_cancel_btn_clicked()
{
    this->close();
    reject();
    exit(0);
}
