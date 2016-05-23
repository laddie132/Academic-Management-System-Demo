#include <QDebug>
#include <QMessageBox>

#include "mainwindow_teacher.h"
#include "ui_mainwindow_teacher.h"

MainWindow_teacher::MainWindow_teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_teacher)
{
    ui->setupUi(this);
    initActivex();
    creatAction();
}

MainWindow_teacher::~MainWindow_teacher()
{
    delete ui;
}

void MainWindow_teacher::setEnvirWidget(Envir_widget* envir_widget)
{
    this->m_envir_widget = envir_widget;
}

void MainWindow_teacher::setUser(Teacher* user)
{
    this->m_user = user;
}

void MainWindow_teacher::initActivex()
{
    ui_course_model = new QStandardItemModel();
    ui_student_model = new QStandardItemModel();

    ui_course_model->sort(0);
    ui_student_model->sort(0);

    ui->tableView_course->setModel(ui_course_model);
    ui->tableView_student->setModel(ui_student_model);
}

void MainWindow_teacher::updateTable()
{
    ui_course_model->clear();

    //设置必修课程列表
    ui_course_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("课程编号")));
    ui_course_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("课程名称")));
    ui_course_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("课程学分")));
    ui_course_model->setHorizontalHeaderItem(3, new QStandardItem(QString::fromLocal8Bit("课程类型")));
    ui_course_model->setHorizontalHeaderItem(4, new QStandardItem(QString::fromLocal8Bit("课程人数")));
    ui_course_model->setHorizontalHeaderItem(5, new QStandardItem(QString::fromLocal8Bit("课程容量")));

    int row = 0;
    for(auto i : m_user->getCourse())
    {
        ui_course_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i->getID())));
        ui_course_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i->getName())));
        ui_course_model->setItem(row, 2, new QStandardItem(QString::number(i->getCredit())));
        ui_course_model->setItem(row, 3, new QStandardItem(i->getCourseType() ? QString::fromLocal8Bit("必修") : QString::fromLocal8Bit("选修")));
        ui_course_model->setItem(row, 4, new QStandardItem(QString::number(i->getStudent().size())));
        ui_course_model->setItem(row, 5, new QStandardItem(QString::number(i->getCapicity())));
        row++;
    }
}

void MainWindow_teacher::showInfo()
{
    ui->label_id->setText(QString::fromStdString(m_user->getID()));
    ui->label_name->setText(QString::fromStdString(m_user->getName()));
    ui->label_institude->setText(QString::fromStdString(m_user->getInsititude()));
    updateTable();

    ui->comboBox_course->clear();
    for(auto i : m_user->getCourse())
    {
        ui->comboBox_course->addItem(QString::fromStdString(i->getID()));
        ui->comboBox_course->setCurrentIndex(0);
    }
    updateStudent();
}

void MainWindow_teacher::updateStudent()
{
    if(ui->comboBox_course->currentIndex() != -1){
        QString id = ui->comboBox_course->currentText();
        Course_teacher* temp = m_user->findCourse(id.toStdString());
        if(temp){
            ui->label_course_id->setText(QString::fromStdString(temp->getID()));
            ui->label_course_name->setText(QString::fromStdString(temp->getName()));
            ui->label_course_credit->setText(QString::number(temp->getCredit()));
            ui->label_course_type->setText(temp->getCourseType() ? QString::fromLocal8Bit("必修") : QString::fromLocal8Bit("选修"));
        }

        //更新学生表格信息
        ui_student_model->clear();

        ui_student_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("学号")));
        ui_student_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("姓名")));
        ui_student_model->setHorizontalHeaderItem(2, new QStandardItem(QString::fromLocal8Bit("成绩")));

        int row = 0;
        for(auto i : temp->getStudentGrade())
        {
            ui_student_model->setItem(row, 0, new QStandardItem(QString::fromStdString(i.first->getID())));
            ui_student_model->setItem(row, 1, new QStandardItem(QString::fromStdString(i.first->getName())));
            ui_student_model->setItem(row, 2, new QStandardItem(QString("%1").arg(i.second)));
            row++;
        }
    }
}

//链接菜单栏按钮的槽函数
void MainWindow_teacher::creatAction()
{
    connect(ui->action_login, SIGNAL(triggered()), this, SLOT(action_login_triggered()));
    connect(ui->action_quit, SIGNAL(triggered()), this, SLOT(action_quit_triggered()));
    connect(ui->action_course, SIGNAL(triggered()), this, SLOT(action_course_triggered()));
    connect(ui->action_set_grade, SIGNAL(triggered()), this, SLOT(action_set_grade_triggered()));
    connect(ui->action_about, SIGNAL(triggered()), this, SLOT(action_about_triggered()));
    connect(ui->action_help, SIGNAL(triggered()), this, SLOT(action_help_triggered()));
    connect(ui->action_password, SIGNAL(triggered()), this, SLOT(action_change_pass_triggered()));

    connect(ui->set_grade_btn, SIGNAL(clicked()), this, SLOT(action_set_grade_triggered()));
}

void MainWindow_teacher::action_login_triggered()
{
    this->close();
    m_envir_widget->showLoginWidget();
}

void MainWindow_teacher::action_quit_triggered()
{
    this->close();
}

void MainWindow_teacher::action_course_triggered()
{
    ui->tabWidget_teacher->setCurrentIndex(0);
}

void MainWindow_teacher::action_set_grade_triggered()
{
    ui->tabWidget_teacher->setCurrentIndex(1);
}

void MainWindow_teacher::action_change_pass_triggered()
{

}

void MainWindow_teacher::action_about_triggered()
{
    QMessageBox::about(this, QString::fromLocal8Bit("关于"),
          QString::fromLocal8Bit(" <font color='red'>Students` Grade Manage System 1.1.0 (opensource)</font>"
                                 "<br>项目主页：https://github.com/laddie132/StudentsGradeManageSystem"
                                 " <br>作者：L.Laddie"
                               "  <br><br>Copyright 2016-2016 The Qt Company Ltd. All rights reserved." ));
}

void MainWindow_teacher::action_help_triggered()
{

}

void MainWindow_teacher::on_comboBox_course_currentIndexChanged(int index)
{
    updateStudent();
}

void MainWindow_teacher::on_cancel_btn_clicked()
{
    updateStudent();
}

void MainWindow_teacher::on_confirm_btn_clicked()
{
    if(ui->comboBox_course->currentIndex() != -1){
        QString course_id = ui->comboBox_course->currentText();
        Course_teacher* temp = m_user->findCourse(course_id.toStdString());
        if(temp){
            int row = ui_student_model->rowCount();
            for(int i = 0; i < row; i++)
            {
                Student* cur_student = NULL;
                QString student_id = ui_student_model->item(i, 0)->text();
               for(auto j : temp->getStudent())
                {
                    if(j->getID() == student_id.toStdString())
                    {
                        cur_student = j;
                        break;
                    }
                }
                float grade = ui_student_model->item(i, 2)->text().toFloat();
                temp->setGrade(std::make_pair(cur_student, grade));
            }
        }
    }
}
