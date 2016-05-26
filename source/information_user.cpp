/**
 * Name: information_user.cpp
 * User: L.Laddie
 * Function: 添加/编辑用户信息
 */

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
    creatActivex();
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

void Information_user::creatActivex()
{
    ui_course_model_n = new QStandardItemModel();
    ui_course_model_y = new QStandardItemModel();

    ui_course_model_n->sort(0);
    ui_course_model_y->sort(0);

    ui->tableView_course_n->setModel(ui_course_model_n);
    ui->tableView_course_y->setModel(ui_course_model_y);

    ui->tableView_course_n->resizeColumnsToContents();
    ui->tableView_course_y->resizeColumnsToContents();
}

void Information_user::showInfo()
{
    //编辑用户时
    if(m_user){
        ui->lineEdit_user_id->setText(QString::fromStdString(m_user->getID()));
        ui->lineEdit_user_id->setEnabled(false);
        ui->lineEdit_user_name->setText(QString::fromStdString(m_user->getName()));
        ui->lineEdit_user_name->setEnabled(false);
        ui->lineEdit_user_institude->setText(QString::fromStdString(m_user->getInsititude()));
        ui->lineEdit_user_institude->setEnabled(false);
        ui->lineEdit_user_password->clear();
        ui->comboBox_user_type->setEnabled(false);
        ui->add_btn->setEnabled(false);
        ui->update_btn->setEnabled(true);
        ui->del_btn->setEnabled(true);
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

    //添加用户时
    else{
        ui->lineEdit_user_id->clear();
        ui->lineEdit_user_class->clear();
        ui->lineEdit_user_institude->clear();
        ui->lineEdit_user_name->clear();
        ui->lineEdit_user_password->clear();
        ui->lineEdit_user_id->setEnabled(true);
        ui->lineEdit_user_name->setEnabled(true);
        ui->lineEdit_user_institude->setEnabled(true);
        ui->comboBox_user_type->setEnabled(true);
        ui->comboBox_user_type->setCurrentIndex(0);
        ui->add_btn->setEnabled(true);
        ui->update_btn->setEnabled(false);
        ui->del_btn->setEnabled(false);
    }
    updateCourse();
}

void Information_user::updateCourse()
{
    ui_course_model_n->clear();
    ui_course_model_y->clear();

    int row1 = 0;
    int row2 = 0;
    if(m_user){
        switch(m_user->getUserType())
        {
        case user_type::student:
        {
            //打印必修课
            for(auto i : m_admin->getEnvir()->getObligatoryCourse())
            {
                int is_find = 0;
                for(auto j : ((Student*)m_user)->getCourse())
                {
                    if(j->getID() == i->getID()){
                        is_find = 1;
                        break;
                    }
                }
                if(!is_find)
                {
                    ui_course_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row2++;
                }
                else{
                    ui_course_model_y->setItem(row1, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_y->setItem(row1, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row1++;
                }
            }

            //打印选修课
            for(auto i : m_admin->getEnvir()->getElectiveCourse())
            {
                int is_find = 0;
                for(auto j : ((Student*)m_user)->getCourse())
                {
                    if(j->getID() == i->getID()){
                        is_find = 1;
                        break;
                    }
                }
                if(!is_find)
                {
                    ui_course_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row2++;
                }
                else{
                    ui_course_model_y->setItem(row1, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_y->setItem(row1, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row1++;
                }
            }
            break;
        }

        case user_type::teacher:
        {
            //打印必修课
            for(auto i : m_admin->getEnvir()->getObligatoryCourse())
            {
                int is_find = 0;
                for(auto j : ((Teacher*)m_user)->getCourse())
                {
                    if(j->getID() == i->getID()){
                        is_find = 1;
                        break;
                    }
                }
                if(!is_find)
                {
                    ui_course_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row2++;
                }
                else{
                    ui_course_model_y->setItem(row1, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_y->setItem(row1, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row1++;
                }
            }

            //打印选修课
            for(auto i : m_admin->getEnvir()->getElectiveCourse())
            {
                int is_find = 0;
                for(auto j : ((Teacher*)m_user)->getCourse())
                {
                    if(j->getID() == i->getID()){
                        is_find = 1;
                        break;
                    }
                }
                if(!is_find)
                {
                    ui_course_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row2++;
                }
                else{
                    ui_course_model_y->setItem(row1, 0, new QStandardItem(QString::fromStdString(i->getID())));
                    ui_course_model_y->setItem(row1, 1, new QStandardItem(QString::fromStdString(i->getName())));
                    row1++;
                }
            }
            break;
        }

        default:
            break;
        }
    }

    //添加一个用户显示的课程
    else{
        for(auto i : m_admin->getEnvir()->getObligatoryCourse())
        {
            ui_course_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i->getID())));
            ui_course_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i->getName())));
            row2++;
        }
        for(auto i : m_admin->getEnvir()->getElectiveCourse())
        {
            ui_course_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i->getID())));
            ui_course_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i->getName())));
            row2++;
        }
    }
}

void Information_user::on_cancel_btn_clicked()
{
    this->close();
}

void Information_user::on_add_btn_clicked()
{
    std::string id = ui->lineEdit_user_id->text().toStdString();
    if(id == ""){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("用户ID不能为空"));
        ui->lineEdit_user_id->setFocus();
        return;
    }
    if(m_admin->getEnvir()->findUser(id)){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("重复的用户ID"));
        ui->lineEdit_user_id->clear();
        ui->lineEdit_user_id->setFocus();
        return;
    }

    std::string name = ui->lineEdit_user_name->text().toStdString();
    if(name == ""){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("用户姓名不能为空"));
        ui->lineEdit_user_name->setFocus();
        return;
    }

    std::string institude = ui->lineEdit_user_institude->text().toStdString();
    if(institude == ""){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("用户学院不能为空"));
        ui->lineEdit_user_institude->setFocus();
        return;
    }

    QString password;
    if(ui->lineEdit_user_password->text() == ""){
        password = QCryptographicHash::hash(ui->lineEdit_user_id->text().toLocal8Bit(), QCryptographicHash::Md5).toHex();
    }
    else{
        password = QCryptographicHash::hash(ui->lineEdit_user_password->text().toLocal8Bit(), QCryptographicHash::Md5).toHex();
    }

    switch (ui->comboBox_user_type->currentIndex()) {
    //添加学生用户
    case 0:
    {
        Student* temp_student = new Student(id, name, institude);
        temp_student->setClass(ui->lineEdit_user_class->text().toStdString());
        addCourse((User*)temp_student);
        m_admin->getEnvir()->addUserStudent(temp_student, password.toStdString());
        break;
    }

    //添加教师用户
    case 1:
    {
        Teacher* temp_teacher = new Teacher(id, name, institude);
        addCourse((User*)temp_teacher);
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
        ui->label_user_class->setEnabled(false);
        ui->lineEdit_user_class->setEnabled(false);
    }
    else{
        ui->label_user_class->setEnabled(true);
        ui->lineEdit_user_class->setEnabled(true);
    }
    if(index == 2){
        ui->label_course->setEnabled(false);
        ui->tableView_course_n->setEnabled(false);
        ui->tableView_course_y->setEnabled(false);
        ui->select_course_btn->setEnabled(false);
        ui->cancel_course_btn->setEnabled(false);
    }
    else{
        ui->label_course->setEnabled(true);
        ui->tableView_course_n->setEnabled(true);
        ui->tableView_course_y->setEnabled(true);
        ui->select_course_btn->setEnabled(true);
        ui->cancel_course_btn->setEnabled(true);
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

    if(m_user->getUserType() == user_type::student){
        std::string class_name = ui->lineEdit_user_class->text().toStdString();
        ((Student*)m_user)->setClass(class_name);
    }

    deleteCourse();
    addCourse(m_user);
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改用户成功"));
    emit updateUser();
}

void Information_user::deleteCourse()
{
    switch(m_user->getUserType())
    {
    case user_type::student:
    {
        Student* temp_student = (Student*)m_user;
        for(auto i : temp_student->getCourse())
        {
            Course* course = m_admin->getEnvir()->findCourse(i->getID());
            course->deleteStudent(temp_student);
        }
        break;
    }

    case user_type::teacher:
    {
        Teacher* temp_teacher = (Teacher*)m_user;
        for(auto i : temp_teacher->getCourse())
        {
            Course* course = m_admin->getEnvir()->findCourse(i->getID());
            course->setTeacher(NULL);
        }
        break;
    }

    default:
        break;
    }
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

void Information_user::on_select_course_btn_clicked()
{
    int row = ui->tableView_course_n->currentIndex().row();
    if(row == -1){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("未选中课程信息"));
        return;
    }
    ui_course_model_y->insertRow(0, ui_course_model_n->takeRow(row));
}

void Information_user::on_cancel_course_btn_clicked()
{
    int row = ui->tableView_course_y->currentIndex().row();
    if(row == -1){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("未选中课程信息"));
        return;
    }
    ui_course_model_n->insertRow(0, ui_course_model_y->takeRow(row));
}

void Information_user::addCourse(User* user)
{
    int row = ui_course_model_y->rowCount();
    if(row != -1){
        for(int i = 0; i < row; i++)
        {
            QString id = ui_course_model_y->item(i, 0)->text();
            Course* course = m_admin->getEnvir()->findCourse(id.toStdString());
            switch(user->getUserType())
            {
            case user_type::student:
            {
                Student* temp_student = (Student*) user;
                if(course->getStudent().size() < course->getCapicity()){
                    course->addStudent(temp_student);
                }
                else{
                    QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("课程容量已满"));
                }
                break;
            }

            case user_type::teacher:
            {
                Teacher* temp_teacher = (Teacher*) user;
                if(course->getTeacher()){
                    if(course->getTeacher()->getID() != temp_teacher->getID()){
                        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("课程已设置教师"));
                    }
                }
                else{
                    course->setTeacher(temp_teacher);
                }
                break;
            }

            default:
                break;
            }
        }
    }
}
