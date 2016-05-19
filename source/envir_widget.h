#ifndef ENVIR_WIDGET_H
#define ENVIR_WIDGET_H

#include "include.h"

//���滷��
class Envir_widget
{
public:
    void setWidget(Login* login, MainWindow_student* student, MainWindow_teacher* teacher, MainWindow_admin* admin);

    //��ָ������
    void showLoginWidget();
    void showAdminWidget(Admin* user);
    void showStudentWidget(Student* user);
    void showTeacherWidget(Teacher* user);

private:
    //���浱ǰ����ָ��
    Login* m_widget_login;
    MainWindow_admin* m_widget_admin;
    MainWindow_student* m_widget_student;
    MainWindow_teacher* m_widget_teacher;
};

#endif // ENVIR_WIDGET_H
