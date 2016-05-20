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
}

//添加和删除课程函数实现

Course* Envir::addObligatoryCourse(std::string ID, std::string name, int credit)
{
    Course* new_course = new Obligatory_course(ID, name, credit);
    m_obligatory_course.insert(new_course);
    return new_course;
}

Course* Envir::addElectiveCourse(std::string ID, std::string name, int credit)
{
    Course* new_course = new Elective_course(ID, name, credit);
    m_elective_course.insert(new_course);
    return new_course;
}

std::set<Course*> Envir::getElectiveCourse()
{
    return m_elective_course;
}

std::set<Course*> Envir::getObligatoryCourse()
{
    return m_obligatory_course;
}

void Envir::deleteCourse(Course *course)
{
    auto i = m_obligatory_course.find(course);
    if(i == m_obligatory_course.end()){
        i = m_elective_course.find(course);
    }
    delete (*i);
}

//对用户权限课程类操作

void Envir::setCourseStudent(Student* student)
{
    std::set<Course_student*> temp_set;
    for(auto i : m_obligatory_course)
    {
        if(i->checkStudent(student)){
            Course_student *temp = new Course_student(i);
            temp_set.insert(temp);
        }
    }
    for(auto i : m_elective_course)
    {
        if(i->checkStudent(student)){
            Course_student *temp = new Course_student(i);
            temp_set.insert(temp);
        }
    }
    student->initCourse(temp_set);
}

void Envir::setCourseTeacher(Teacher *teacher)
{
    std::set<Course_teacher*> temp_set;
    for(auto i : m_obligatory_course)
    {
        if(i->checkTeacher(teacher)){
            Course_teacher *temp = new Course_teacher(i);
            temp_set.insert(temp);
        }
    }
    for(auto i : m_elective_course)
    {
        if(i->checkTeacher(teacher)){
            Course_teacher *temp = new Course_teacher(i);
            temp_set.insert(temp);
        }
    }
    teacher->initCourse(temp_set);
}
/*
void Envir::setCourseAdmin(Admin *admin)
{
    std::set<Course_admin*> temp_set;
    for(auto i : m_obligatory_course)
    {
        Course_admin *temp = new Course_admin(i);
        temp_set.insert(temp);
    }
    for(auto i : m_elective_course)
    {
        Course_admin *temp = new Course_admin(i);
        temp_set.insert(temp);
    }
    admin->initCourse(temp_set);
}*/

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
