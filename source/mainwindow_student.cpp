#include "mainwindow_student.h"
#include "ui_mainwindow_student.h"

MainWindow_student::MainWindow_student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_student)
{
    ui->setupUi(this);
}

MainWindow_student::~MainWindow_student()
{
    delete ui;
}

void MainWindow_student::setEnvirWidget(Envir_widget* envir_widget)
{
    this->m_envir_widget = envir_widget;
}

void MainWindow_student::setUser(Student* user)
{
    this->m_user = user;
}

void MainWindow_student::initTable()
{

}

void MainWindow_student::updateTable()
{

}
