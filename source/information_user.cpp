#include <QDebug>
#include <QMessageBox>
#include <QCryptographicHash>

#include "information_user.h"
#include "ui_information_user.h"
#include "include.h"
#include "user.h"
#include "course.h"

Information_user::Information_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information_user)
{
    ui->setupUi(this);
}

Information_user::~Information_user()
{
    delete ui;
}

void Information_user::setUser_admin(Admin* admin)
{
    m_admin = admin;
}

void Information_user::setUser(User *user)
{
    m_user = user;
}

void Information_user::showInfo()
{
    if(m_user){
        ui->lineEdit_user_id->setText(QString::fromStdString(m_user->getID()));
        ui->lineEdit_user_name->setText(QString::fromStdString(m_user->getName()));
        ui->lineEdit_user_institude->setText(QString::fromStdString(m_user->getInsititude()));
        ui->lineEdit_user_password->clear();
        switch(m_user->getUserType())
        {
        case user_type::student:
        {
            ui->comboBox_user_type->setCurrentIndex(0);
            ui->lineEdit_user_class->setText(QString::fromStdString(((Student*)m_user)->getClass()));
            break;
        }

        case user_type::teacher:
            ui->comboBox_user_type->setCurrentIndex(1);
            break;

        case user_type::admin:
            ui->comboBox_user_type->setCurrentIndex(2);
            break;

        default:
            break;
        }
    }
}

void Information_user::on_cancel_btn_clicked()
{
    this->close();
}

void Information_user::on_add_btn_clicked()
{
    QString password;
    if(ui->lineEdit_user_password->text() == ""){
        password = QCryptographicHash::hash(ui->lineEdit_user_id->text().toLocal8Bit(), QCryptographicHash::Md5).toHex();
    }
    else{
        password = QCryptographicHash::hash(ui->lineEdit_user_password->text().toLocal8Bit(), QCryptographicHash::Md5).toHex();
    }
    std::string id = ui->lineEdit_user_id->text().toStdString();
    std::string name = ui->lineEdit_user_name->text().toStdString();
    std::string institude = ui->lineEdit_user_institude->text().toStdString();
    if(m_admin->getEnvir()->findUser(id)){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("重复的用户ID"));
        return;
    }
    switch (ui->comboBox_user_type->currentIndex()) {
    //添加学生用户
    case 0:
    {
        Student* temp_student = new Student(id, name, institude);
        temp_student->setClass(ui->lineEdit_user_class->text().toStdString());
        m_admin->getEnvir()->addUserStudent(temp_student, password.toStdString());
        break;
    }

    //添加教师用户
    case 1:
    {
        Teacher* temp_teacher = new Teacher(id, name, institude);
        m_admin->getEnvir()->addUserTeacher(temp_teacher, password.toStdString());
        break;
    }

    //添加管理员用户
    case 2:
    {
        Admin* temp_admin = new Admin(id, name, institude);
        m_admin->getEnvir()->addUserAdmin(temp_admin, password.toStdString());
        break;
    }

    default:
        break;
     }
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加用户成功"));
    emit updateUser();
}

void Information_user::on_comboBox_user_type_currentIndexChanged(int index)
{
    if(index != 0){
        ui->label_user_class->close();
        ui->lineEdit_user_class->close();
    }
    else{
        ui->label_user_class->show();
        ui->lineEdit_user_class->show();
    }
}

void Information_user::on_update_btn_clicked()
{
    if(!m_user){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("无用户信息"));
        return;
    }
    std::string id = ui->lineEdit_user_id->text().toStdString();
    std::string name = ui->lineEdit_user_name->text().toStdString();
    std::string institude = ui->lineEdit_user_institude->text().toStdString();
    QString password = ui->lineEdit_user_password->text();
    if(password != ""){
        QString pass = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Md5).toHex();
        m_admin->getEnvir()->changeUserPass(m_user, pass.toStdString());
    }
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改用户成功"));
    emit updateUser();
}

void Information_user::on_del_btn_clicked()
{
    if(!m_user){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("无用户信息"));
        return;
    }
    if(m_user->getID() == m_admin->getID()){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("无法删除正在使用的管理员"));
        return;
    }
    m_admin->getEnvir()->deleteUser(m_user);
    m_user = NULL;
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除用户成功"));
    emit updateUser();
}
