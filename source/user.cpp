//user.cpp �û�����

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

bool Student::addCourse(Course_student* course)
{
	if (course->addElectiveStudent(this)) {
		this->m_course.insert(course);
		return true;
	}
	return false;
}

bool Student::deleteCourse(Course_student* course)
{
	if (course->deleteElectiveStudent(this)) {
		this->m_course.erase(course);
		return true;
	}
	return false;
}

int Student::getUserType()
{
	return 1;
}

//��ʦ����ʵ��

std::set<Course_teacher*> Teacher::getCourse()
{
	return m_course;
}

int Teacher::getUserType()
{
	return 2;
}

//����Ա����ʵ��

std::set<Course_admin*> Admin::getCourse()
{
	return m_course;
}

int Admin::getUserType()
{
	return 0;
}

void Admin::activateEnvir(Envir* envir)
{
	m_envir = envir;
}

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
	return m_envir->addUserStudent(ID, name, insititude);
}

void Admin::addUserTeacher(std::string ID, std::string name, std::string insititude)
{
	return m_envir->addUserTeacher(ID, name, insititude);
}

void Admin::addUserAdmin(std::string ID, std::string name, std::string insititude)
{
	return m_envir->addUserAdmin(ID, name, insititude);
}

std::map<User*, std::string> Admin::getUserStudent()
{
	return m_envir->getUserStudent();
}

std::map<User*, std::string> Admin::getUserTeacher()
{
	return m_envir->getUserTeacher();
}

std::map<User*, std::string> Admin::getUserAdmin()
{
	return m_envir->getUserAdmin();
}