#pragma once

#include "include.h"
#include "user.h"
#include "course.h"

class Envir
{
public:
	Envir();
	~Envir();

	void addObligatoryCourse(std::string ID, std::string name, int credit);
	void addElectiveCourse(std::string ID, std::string name, int credit);

	void addUserStudent(std::string ID, std::string name, std::string insititude);
	void addUserTeacher(std::string ID, std::string name, std::string insititude);
	void addUserAdmin(std::string ID, std::string name, std::string insititude);

    std::map<User*, std::string> getUserStudent();
	std::map<User*, std::string> getUserTeacher();
    std::map<User*, std::string> getUserAdmin();

	User* checkUser(std::string username, std::string password);

private:
	//���浱ǰϵͳ�γ�
	std::set<Course*> m_obligatory_course;
	std::set<Course*> m_elective_course;

	//�����û���¼��Ϣ(md5����)
	std::map<User*, std::string> m_student;
	std::map<User*, std::string> m_teacher;
	std::map<User*, std::string> m_admin;
};
