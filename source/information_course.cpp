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
    creatActivex();
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

void Information_course::creatActivex()
{
    ui_student_model_n = new QStandardItemModel();
    ui_student_model_y = new QStandardItemModel();

    ui_student_model_n->sort(0);
    ui_student_model_y->sort(0);

    ui->tableView_student_n->setModel(ui_student_model_n);
    ui->tableView_student_y->setModel(ui_student_model_y);

    ui->tableView_student_n->resizeColumnsToContents();
    ui->tableView_student_y->resizeColumnsToContents();

    ui->checkBox_start_course->close();
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

    //编辑课程时
    if(m_course){
        ui->lineEdit_course_id->setText(QString::fromStdString(m_course->getID()));
        ui->lineEdit_course_id->setEnabled(false);
        ui->lineEdit_course_name->setText(QString::fromStdString(m_course->getName()));
        ui->lineEdit_course_name->setEnabled(false);
        ui->lineEdit_course_credit->setText(QString::number(m_course->getCredit()));
        ui->lineEdit_course_credit->setEnabled(false);
        ui->comboBox_type->setEnabled(false);
        ui->lineEdit_course_capicity->setText(QString::number(m_course->getCapicity()));
        ui->label_course_student->setText(QString::number(m_course->getStudent().size()));
        ui->comboBox_type->setCurrentIndex(!m_course->getCourseType());
        ui->add_btn->setEnabled(false);
        ui->update_btn->setEnabled(true);
        ui->del_btn->setEnabled(true);
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

    //添加课程时
    else{
        ui->lineEdit_course_id->clear();
        ui->lineEdit_course_capicity->clear();
        ui->lineEdit_course_credit->clear();
        ui->lineEdit_course_name->clear();
        ui->lineEdit_course_id->setEnabled(true);
        ui->lineEdit_course_name->setEnabled(true);
        ui->lineEdit_course_credit->setEnabled(true);
        ui->comboBox_type->setEnabled(true);
        ui->add_btn->setEnabled(true);
        ui->update_btn->setEnabled(false);
        ui->del_btn->setEnabled(false);
    }
    updateStudent();
}

void Information_course::updateStudent()
{
    ui_student_model_n->clear();
    ui_student_model_y->clear();

    int row1 = 0;
    int row2 = 0;
    if(m_course){
        for(auto i : m_user->getEnvir()->getUserStudent())
        {
            if(!m_course->getStudent().count(i.first))
            {
                ui_student_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
                ui_student_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
                row2++;
            }
            else{
                ui_student_model_y->setItem(row1, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
                ui_student_model_y->setItem(row1, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
                row1++;
            }
        }
    }
    else{
        for(auto i : m_user->getEnvir()->getUserStudent())
        {
            ui_student_model_n->setItem(row2, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
            ui_student_model_n->setItem(row2, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
            row2++;
        }
    }
}

void Information_course::on_add_btn_clicked()
{
    std::string id = ui->lineEdit_course_id->text().toStdString();
    if(id == ""){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("课程ID不能为空"));
        ui->lineEdit_course_id->setFocus();
        return;
    }
    if(m_user->getEnvir()->findCourse(id)){
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("课程ID重复"));
        ui->lineEdit_course_id->clear();
        ui->lineEdit_course_id->setFocus();
        return;
    }

    std::string name = ui->lineEdit_course_name->text().toStdString();
    if(name == ""){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("课程名称不能为空"));
        ui->lineEdit_course_name->setFocus();
        return;
    }

    QString credit_string = ui->lineEdit_course_credit->text();
    if(credit_string == ""){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("课程学分不能为空"));
        ui->lineEdit_course_credit->setFocus();
        return;
    }
    int credit = credit_string.toInt();

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
        addStudent((Course*)temp_course);
        m_user->getEnvir()->addElectiveCourse(temp_course);
    }
    else{
        Obligatory_course* temp_course = new Obligatory_course(id, name, credit);
        temp_course->setCapicity(capicity);
        temp_course->setTeacher(teacher);
        addStudent((Course*)temp_course);
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
    if(!index){
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
    }
    else{
        m_course->setTeacher(NULL);
    }
    addStudent(m_course);
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("更新课程成功"));

    emit updateCourse();
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

void Information_course::on_select_student_btn_clicked()
{
    int row = ui->tableView_student_n->currentIndex().row();
    if(row == -1){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("未选中学生信息"));
        return;
    }
    ui_student_model_y->insertRow(0, ui_student_model_n->takeRow(row));
}

void Information_course::on_cancel_student_btn_clicked()
{
    int row = ui->tableView_student_y->currentIndex().row();
    if(row == -1){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("未选中学生信息"));
        return;
    }
    ui_student_model_n->insertRow(0, ui_student_model_y->takeRow(row));
}

void Information_course::addStudent(Course * course)
{
    course->clearStudent();
    int row = ui_student_model_y->rowCount();
    if(row != -1){
        for(int i = 0; i < row; i++)
        {
            QString id = ui_student_model_y->item(i, 0)->text();
            User* user = m_user->getEnvir()->findUser(id.toStdString());
            if(user->getUserType() == user_type::student){
                course->addStudent((Student*)user);
            }
        }
    }
}
