#ifndef ENVIR_WIDGET_H
#define ENVIR_WIDGET_H

#include "include.h"
#include <QApplication>

//���滷��
class Envir_widget : public QObject
{
    Q_OBJECT

public:
    explicit Envir_widget(){}

    void setWidget(Login* login, MainWindow_student* student, MainWindow_teacher* teacher, MainWindow_admin* admin);

    //��ָ������
    void showLoginWidget();
    void showAdminWidget(Admin* user);
    void showStudentWidget(Student* user);
    void showTeacherWidget(Teacher* user);

    //���������ļ�
    void setConfigFile(Config_file* config);

public slots:
    void updateConfig();

private:
    //���浱ǰ����ָ��
    Login* m_widget_login;
    MainWindow_admin* m_widget_admin;
    MainWindow_student* m_widget_student;
    MainWindow_teacher* m_widget_teacher;

    //�����ļ�
    Config_file* m_config;
};

#endif // ENVIR_WIDGET_H
