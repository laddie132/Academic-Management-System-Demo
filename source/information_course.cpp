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

void Information_course::on_confirm_btn_clicked()
{
    std::string id = ui->lineEdit_course_id->text().toStdString();
    std::string name = ui->lineEdit_course_name->text().toStdString();
    int credit = ui->lineEdit_course_credit->text().toInt();
    int capicity = ui->lineEdit_course_capicity->text().toInt();
    if(ui->comboBox_type->currentIndex()){
        Elective_course* temp_course = new Elective_course(id, name, credit);
        temp_course->setCapicity(capicity);
        m_user->getEnvir()->addElectiveCourse(temp_course);
    }
    else{
        Obligatory_course* temp_course = new Obligatory_course(id, name, credit);
        temp_course->setCapicity(capicity);
        m_user->getEnvir()->addObligatoryCourse(temp_course);
    }
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加课程成功"));
    emit addCourse();
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
