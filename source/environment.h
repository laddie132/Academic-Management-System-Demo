#pragma once

#include "include.h"
#include "user.h"
#include "course.h"

#include "login.h"
#include "mainwindow_admin.h"
#include "mainwindow_student.h"
#include "mainwindow_teacher.h"

//系统工作环境（最高权限访问）
class Envir
{
public:
    Envir(){}
    ~Envir();

    Course* addObligatoryCourse(std::string ID, std::string name, int credit);
    Course* addElectiveCourse(std::string ID, std::string name, int credit);

    std::set<Course*> getObligatoryCourse();
    std::set<Course*> getElectiveCourse();

    void deleteCourse(Course* course);

    //对于学生和教师重新包装课程权限后使用
    void setCourseStudent(Student* student);
    void setCourseTeacher(Teacher* teacher);

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

	//保存用户登录信息(md5密码)
    std::map<Student*, std::string> m_student;
    std::map<Teacher*, std::string> m_teacher;
    std::map<Admin*, std::string> m_admin;
};
