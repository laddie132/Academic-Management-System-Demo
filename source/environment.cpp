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

//添加课程函数实现

void Envir::addObligatoryCourse(std::string ID, std::string name, int credit)
{
	m_obligatory_course.insert(new Obligatory_course(ID, name, credit));
}

void Envir::addElectiveCourse(std::string ID, std::string name, int credit)
{
	m_elective_course.insert(new Elective_course(ID, name, credit));
}

//添加用户函数实现

void Envir::addUserStudent(std::string ID, std::string name, std::string insititude)
{
	Student* temp_student = new Student(ID, name, insititude);
	m_student.insert(std::make_pair(temp_student, ID));
}

void Envir::addUserTeacher(std::string ID, std::string name, std::string insititude)
{
	Teacher* temp_teacher = new Teacher(ID, name, insititude);
	m_teacher.insert(std::make_pair(temp_teacher, ID));
}

void Envir::addUserAdmin(std::string ID, std::string name, std::string insititude)
{
	Admin* temp_admin = new Admin(ID, name, insititude);
	m_admin.insert(std::make_pair(temp_admin, ID));
}

//获取用户函数实现

std::map<User*, std::string> Envir::getUserStudent()
{
	return m_student;
}

std::map<User*, std::string> Envir::getUserTeacher()
{
	return m_teacher;
}

std::map<User*, std::string> Envir::getUserAdmin()
{
	return m_admin;
}

User* Envir::checkUser(std::string username, std::string password)
{
    std::pair<User*, std::string> ans;
	int is_find = 0;
    for (auto i : m_student)
	{
        if (i.first->getID() == username) {
			is_find = 1;
            ans = i;
			break;
		}
	}
	if (!is_find) {
        for (auto i : m_teacher)
		{
			if (i.first->getID() == username) {
				is_find = 1;
				break;
			}
		}
	}
	if (!is_find) {
        for (auto i : m_admin)
		{
			if (i.first->getID() == username) {
				is_find = 1;
				break;
			}
		}
	}
	if (is_find) {
		if (ans.second == password) {
			return ans.first;
		}
	}
	return NULL;
}
