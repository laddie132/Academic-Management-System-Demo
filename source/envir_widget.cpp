/**
 * Name: envir_widget.cpp
 * User: L.Laddie
 * Function: 界面相关环境
 */

#include "include.h"
#include "envir_widget.h"
#include "mainwindow_admin.h"
#include "mainwindow_student.h"
#include "mainwindow_teacher.h"

//界面相关函数实现

void Envir_widget::setWidget(Login* login, MainWindow_student* student, MainWindow_teacher* teacher, MainWindow_admin* admin)
{
    m_widget_admin = admin;
    m_widget_login = login;
    m_widget_student = student;
    m_widget_teacher = teacher;
}

void Envir_widget::showLoginWidget()
{
    m_widget_login->show();
}

void Envir_widget::showAdminWidget(Admin* user)
{
    m_widget_admin->show();
    m_widget_admin->setUser(user);
    m_widget_admin->showInfo();
}

void Envir_widget::showStudentWidget(Student* user)
{
    m_widget_student->show();
    m_widget_student->setUser(user);
    m_widget_student->showInfo();
}

void Envir_widget::showTeacherWidget(Teacher* user)
{
    m_widget_teacher->show();
    m_widget_teacher->setUser(user);
    m_widget_teacher->showInfo();
}
