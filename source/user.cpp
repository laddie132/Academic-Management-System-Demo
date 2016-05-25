//user.cpp �û�����
#include <QDebug>
#include <QString>
#include "user.h"

//User���ຯ��ʵ��

std::string User::getID()
{
	return m_ID;
}

std::string User::getName()
{
	return m_name;
}

std::string User::getInsititude()
{
	return m_insititude;
}

//ѧ������ʵ��

std::string Student::getClass()
{
	return m_class;
}

void Student::setClass(std::string class_name)
{
	this->m_class = class_name;
}

std::map<Course_student*, float> Student::getGrade()
{
	std::map<Course_student*, float> ans;
	for (auto& i : m_course)
	{
		float grade = i->getMyGrade(this);
		ans.insert(std::make_pair(i, grade));
	}
	return ans;
}

std::set<Course_student*> Student::getCourse()
{
	return m_course;
}

std::set<Course_student*> Student::getSelectCourse()
{
    return m_select_course;
}

bool Student::addCourse(Course_student* course)
{
	if (course->addElectiveStudent(this)) {
		this->m_course.insert(course);
        this->m_select_course.erase(course);
		return true;
	}
	return false;
}

bool Student::deleteCourse(Course_student* course)
{
    if (course->deleteElectiveStudent(this)) {
		this->m_course.erase(course);
        this->m_select_course.insert(course);
		return true;
	}
	return false;
}

void Student::initCourse(std::set<Course_student *> course, std::set<Course_student *> select_course)
{
    eraseCourse();
    m_course = course;
    m_select_course = select_course;
}

void Student::eraseCourse()
{
    for(auto i : m_course)
    {
        delete i;
    }
    m_course.clear();
    for(auto i : m_select_course)
    {
        delete i;
    }
    m_select_course.clear();
}

user_type Student::getUserType()
{
    return user_type::student;
}

//��ʦ����ʵ��

std::set<Course_teacher*> Teacher::getCourse()
{
	return m_course;
}

void Teacher::initCourse(std::set<Course_teacher *> course)
{
    eraseCourse();
    m_course = course;
}

void Teacher::eraseCourse()
{
    for(auto i : m_course)
    {
        delete i;
    }
    m_course.clear();
}


user_type Teacher::getUserType()
{
    return user_type::teacher;
}

Course_teacher* Teacher::findCourse(std::string id)
{
    Course_teacher* temp = NULL;
    for(auto i : m_course)
    {
        if(i->getID() == id){
            temp = i;
            break;
        }
    }
    return temp;
}

//����Ա����ʵ��

user_type Admin::getUserType()
{
    return user_type::admin;
}

void Admin::activateEnvir(Envir* envir)
{
	m_envir = envir;
}

Envir* Admin::getEnvir()
{
    return m_envir;
}

/*
void Admin::addObligatoryCourse(std::string ID, std::string name, int credit)
{
    m_envir->addObligatoryCourse(ID, name, credit);
}

void Admin::addElectiveCourse(std::string ID, std::string name, int credit)
{
    m_envir->addElectiveCourse(ID, name, credit);
}

void Admin::addUserStudent(std::string ID, std::string name, std::string insititude)
{
    m_envir->addUserStudent(ID, name, insititude);
}

void Admin::addUserTeacher(std::string ID, std::string name, std::string insititude)
{
    m_envir->addUserTeacher(ID, name, insititude);
}

void Admin::addUserAdmin(std::string ID, std::string name, std::string insititude)
{
    m_envir->addUserAdmin(ID, name, insititude);
}

std::map<Student*, std::string> Admin::getUserStudent()
{
	return m_envir->getUserStudent();
}

std::map<Teacher*, std::string> Admin::getUserTeacher()
{
	return m_envir->getUserTeacher();
}

std::map<Admin*, std::string> Admin::getUserAdmin()
{
	return m_envir->getUserAdmin();
}
*/
