#include <QCryptographicHash>
#include <QString>
#include <QDebug>

#include "environment.h"

//析构函数实现
Envir::~Envir()
{
    for (auto i : m_obligatory_course)
	{
		delete i;
	}

    for (auto i : m_elective_course)
	{
		delete i;
	}

    for (auto i : m_student)
	{
		delete i.first;
	}

    for (auto i : m_teacher)
	{
		delete i.first;
	}

    for (auto i : m_admin)
	{
		delete i.first;
	}
    deleteCourseUser();
}

//添加课程函数实现

void Envir::addObligatoryCourse(std::string ID, std::string name, int credit)
{
	m_obligatory_course.insert(new Obligatory_course(ID, name, credit));
}

void Envir::addElectiveCourse(std::string ID, std::string name, int credit)
{
	m_elective_course.insert(new Elective_course(ID, name, credit));
}

//对用户权限课程类操作

void Envir::setCourseUser(user_type type)
{
    deleteCourseUser();
    switch(type)
    {
    case user_type::student:    //添加学生课程权限类
        for(auto i : m_obligatory_course)
        {
            Course_user *temp = new Course_student(i);
            m_course_user.insert(temp);
        }
        for(auto i : m_elective_course)
        {
            Course_user *temp = new Course_student(i);
            m_course_user.insert(temp);
        }
        break;

    case user_type::teacher:    //添加教师课程权限类
        for(auto i : m_obligatory_course)
        {
            Course_user *temp = new Course_teacher(i);
            m_course_user.insert(temp);
        }
        for(auto i : m_elective_course)
        {
            Course_user *temp = new Course_teacher(i);
            m_course_user.insert(temp);
        }
        break;

    case user_type::admin:      //添加管理员课程权限类
        for(auto i : m_obligatory_course)
        {
            Course_user *temp = new Course_admin(i);
            m_course_user.insert(temp);
        }
        for(auto i : m_elective_course)
        {
            Course_user *temp = new Course_admin(i);
            m_course_user.insert(temp);
        }
        break;
    }
}

std::set<Course_user*> Envir::getCourseUser()
{
    return m_course_user;
}

void Envir::deleteCourseUser()
{
    for(auto i : m_course_user)
    {
        delete i;
    }
    m_course_user.clear();
}

//添加用户函数实现

void Envir::addUserStudent(std::string ID, std::string name, std::string insititude)
{
	Student* temp_student = new Student(ID, name, insititude);
    QString md5_pass = QCryptographicHash::hash(ID.c_str(), QCryptographicHash::Md5).toHex();
    m_student.insert(std::make_pair(temp_student, md5_pass.toStdString()));
}

void Envir::addUserTeacher(std::string ID, std::string name, std::string insititude)
{
	Teacher* temp_teacher = new Teacher(ID, name, insititude);
    QString md5_pass = QCryptographicHash::hash(ID.c_str(), QCryptographicHash::Md5).toHex();
    m_teacher.insert(std::make_pair(temp_teacher, md5_pass.toStdString()));
}

void Envir::addUserAdmin(std::string ID, std::string name, std::string insititude)
{
	Admin* temp_admin = new Admin(ID, name, insititude);
    QString md5_pass = QCryptographicHash::hash(ID.c_str(), QCryptographicHash::Md5).toHex();
    m_admin.insert(std::make_pair(temp_admin, md5_pass.toStdString()));
}

//获取用户函数实现

std::map<Student*, std::string> Envir::getUserStudent()
{
	return m_student;
}

std::map<Teacher*, std::string> Envir::getUserTeacher()
{
	return m_teacher;
}

std::map<Admin*, std::string> Envir::getUserAdmin()
{
	return m_admin;
}

Student* Envir::checkUserStudent(std::string username, std::string password)
{
    for (auto i : m_student)
    {
        if (i.first->getID() == username) {
            if(i.second == password){
                return i.first;
            }
            break;
        }
    }
    return NULL;
}

Teacher* Envir::checkUserTeacher(std::string username, std::string password)
{
    for (auto i : m_teacher)
    {
        if (i.first->getID() == username) {
            if(i.second == password){
                return i.first;
            }
            break;
        }
    }
    return NULL;
}

Admin* Envir::checkUserAdmin(std::string username, std::string password)
{
    for (auto i : m_admin)
    {
        if (i.first->getID() == username) {
            if(i.second == password){
                return i.first;
            }
            break;
        }
    }
    return NULL;
}
