#pragma once

#include "include.h"
#include "user.h"
#include "course.h"

#include "login.h"
#include "mainwindow_admin.h"
#include "mainwindow_student.h"
#include "mainwindow_teacher.h"

class Envir
{
public:
    Envir(){}
    ~Envir();

	void addObligatoryCourse(std::string ID, std::string name, int credit);
	void addElectiveCourse(std::string ID, std::string name, int credit);

    void setCourseUser(user_type type);
    std::set<Course_user*> getCourseUser();

    void deleteCourseUser();

	void addUserStudent(std::string ID, std::string name, std::string insititude);
	void addUserTeacher(std::string ID, std::string name, std::string insititude);
	void addUserAdmin(std::string ID, std::string name, std::string insititude);

    std::map<Student*, std::string> getUserStudent();
    std::map<Teacher*, std::string> getUserTeacher();
    std::map<Admin*, std::string> getUserAdmin();

    Student* checkUserStudent(std::string username, std::string password);
    Teacher* checkUserTeacher(std::string username, std::string password);
    Admin* checkUserAdmin(std::string username, std::string password);

private:
	//保存当前系统课程
	std::set<Course*> m_obligatory_course;
	std::set<Course*> m_elective_course;

    std::set<Course_user*> m_course_user;

	//保存用户登录信息(md5密码)
    std::map<Student*, std::string> m_student;
    std::map<Teacher*, std::string> m_teacher;
    std::map<Admin*, std::string> m_admin;
};
