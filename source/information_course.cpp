#include <QDebug>
#include <QMessageBox>

#include "information_course.h"
#include "ui_information_course.h"
#include "include.h"
#include "course.h"

Information_course::Information_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information_course)
{
    ui->setupUi(this);
}

Information_course::~Information_course()
{
    delete ui;
}

void Information_course::setUser(Admin *admin)
{
    m_user = admin;
}

void Information_course::setCourse(Course *course)
{
    m_course = course;
}

void Information_course::showInfo()
{
    ui->comboBox_teacher->clear();
    ui->comboBox_teacher->addItem(QString::fromLocal8Bit("无"));
    for(auto i : m_user->getEnvir()->getUserTeacher())
    {
        ui->comboBox_teacher->addItem(QString::fromStdString(i.first->getID()));
    }
    ui->comboBox_teacher->setCurrentIndex(0);

    if(m_course){
        ui->lineEdit_course_id->setText(QString::fromStdString(m_course->getID()));
        ui->lineEdit_course_name->setText(QString::fromStdString(m_course->getName()));
        ui->lineEdit_course_credit->setText(QString::number(m_course->getCredit()));
        ui->lineEdit_course_capicity->setText(QString::number(m_course->getCapicity()));
        ui->lineEdit_course_num->setText(QString::number(m_course->getStudent().size()));
        ui->comboBox_type->setCurrentIndex(!m_course->getCourseType());
        if(m_course->getTeacher() != NULL){
            int i = 0;
            for(i = 0; i <= ui->comboBox_teacher->count(); i++)
            {
                if(ui->comboBox_teacher->itemText(i).toStdString() ==  m_course->getTeacher()->getID()){
                    ui->comboBox_teacher->setCurrentIndex(i);
                    break;
                }
            }
        }
    }
}

void Information_course::on_add_btn_clicked()
{
    std::string id = ui->lineEdit_course_id->text().toStdString();
    if(m_user->getEnvir()->findCourse(id)){
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("课程ID重复"));
        ui->lineEdit_course_id->clear();
        ui->lineEdit_course_id->setFocus();
        return;
    }
    std::string name = ui->lineEdit_course_name->text().toStdString();
    int credit = ui->lineEdit_course_credit->text().toInt();
    int capicity = ui->lineEdit_course_capicity->text().toInt();
    Teacher* teacher = NULL;
    if(ui->comboBox_teacher->currentText() != QString::fromLocal8Bit("无")){
        User* temp = m_user->getEnvir()->findUser(ui->comboBox_teacher->currentText().toStdString());
        if(temp->getUserType() == user_type::teacher){
            teacher = (Teacher*)temp;
        }
    }

    if(ui->comboBox_type->currentIndex()){
        Elective_course* temp_course = new Elective_course(id, name, credit);
        temp_course->setCapicity(capicity);
        temp_course->setTeacher(teacher);
        m_user->getEnvir()->addElectiveCourse(temp_course);
    }
    else{
        Obligatory_course* temp_course = new Obligatory_course(id, name, credit);
        temp_course->setCapicity(capicity);
        temp_course->setTeacher(teacher);
        m_user->getEnvir()->addObligatoryCourse(temp_course);
    }
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加课程成功"));
    emit updateCourse();
}

void Information_course::on_cancel_btn_clicked()
{
    this->close();
}

void Information_course::on_comboBox_type_currentIndexChanged(int index)
{
    if(index){
        ui->checkBox_start_course->close();
    }
    else ui->checkBox_start_course->show();
}

void Information_course::on_update_btn_clicked()
{
    if(!m_course){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("无课程信息"));
        return;
    }
    std::string id = ui->lineEdit_course_id->text().toStdString();
    std::string name = ui->lineEdit_course_name->text().toStdString();
    int credit = ui->lineEdit_course_credit->text().toInt();
    int capicity = ui->lineEdit_course_capicity->text().toInt();
    m_course->setCapicity(capicity);
    QString teacher_id = "";
    if(ui->comboBox_teacher->currentText() != QString::fromLocal8Bit("无")){
        teacher_id = ui->comboBox_teacher->currentText();
    }
    User* temp = m_user->getEnvir()->findUser(teacher_id.toStdString());
    if(temp && temp->getUserType() == user_type::teacher){
        m_course->setTeacher((Teacher*)temp);
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("更新课程成功"));
        emit updateCourse();
    }
    else QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("无教师信息"));
}

void Information_course::on_del_btn_clicked()
{
    if(!m_course){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("无课程信息"));
        return;
    }
    m_user->getEnvir()->deleteCourse(m_course);
    m_course = NULL;
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除课程成功"));
    emit updateCourse();
}
