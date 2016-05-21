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

void Information_user::setUser(Admin* admin)
{
    m_user = admin;
}

void Information_user::on_cancel_btn_clicked()
{
    this->close();
}

void Information_user::on_confirm_btn_clicked()
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
    switch (ui->comboBox_user_type->currentIndex()) {
    //添加学生用户
    case 0:
    {
        Student* temp_student = new Student(id, name, institude);
        temp_student->setClass(ui->lineEdit_user_class->text().toStdString());
        m_user->getEnvir()->addUserStudent(temp_student, password.toStdString());
        break;
    }

    //添加教师用户
    case 1:
    {
        Teacher* temp_teacher = new Teacher(id, name, institude);
        m_user->getEnvir()->addUserTeacher(temp_teacher, password.toStdString());
        break;
    }

    //添加管理员用户
    case 2:
    {
        Admin* temp_admin = new Admin(id, name, institude);
        m_user->getEnvir()->addUserAdmin(temp_admin, password.toStdString());
        break;
    }

    default:
        break;
     }
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加用户成功"));
    emit addUser();
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
