/**
 * Name: config.cpp
 * User: L.Laddie
 * Function: �����ļ�
 */

#include <QDebug>
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
#include "config.h"

Config_file::Config_file()
{

}

Config_file::~Config_file()
{

}

void Config_file::setEnvir(Envir *envir)
{
    this->m_envir = envir;
}

void Config_file::readConfig()
{
    //�������ļ�
    std::ifstream file;
    file.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    file.open("config.ini", std::ios_base::in);

    //����������ʽƥ�������ļ�
    std::regex pattern("\\[(.*)\\]");
    std::string str;
    std::match_results<std::string::const_iterator> result;

    //һ��һ�ж�ȡ
    config_state state = config_state::nop;
    while(!file.eof()){
        std::getline(file, str);
        if(str[0] == '#' || str == "")       //һ��Ϊע�ͻ���Ϊ��
            continue;

        //ȷ����һ��״̬
        if(std::regex_match(str, result, pattern)){
            if(result[1] == "student")
                state = config_state::student;
            else if(result[1] == "teacher")
                state = config_state::teacher;
            else if(result[1] == "admin")
                state = config_state::admin;
            else if(result[1] == "obligatory")
                state = config_state::obligatory;
            else if(result[1] == "elective")
                state = config_state::elective;

            continue;
        }

        std::stringstream file_line(str);
        switch (state) {
        case config_state::student:
        {
            Student* new_student = new Student();
            std::string pass;
            file_line >> *new_student >> pass;
            this->m_envir->addUserStudent(new_student, pass);
            break;
        }

        case config_state::teacher:
        {
            Teacher* new_teacher = new Teacher();
            std::string pass;
            file_line >> *new_teacher >> pass;
            this->m_envir->addUserTeacher(new_teacher, pass);
            break;
        }

        case config_state::admin:
        {
            Admin* new_admin = new Admin();
            std::string pass;
            file_line >> *new_admin >> pass;
            this->m_envir->addUserAdmin(new_admin, pass);
            break;
        }

        case config_state::obligatory:
        {
            qDebug() << '3';
            break;
        }

        case config_state::elective:
        {
            qDebug() << '4';
            break;
        }

        default:
            break;
        }
    }
}

void Config_file::writeConfig()
{

}
