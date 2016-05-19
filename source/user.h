#pragma once

#include "include.h"
#include "course.h"
#include "environment.h"

//User类代表所有用户类型
class User
{
public:
	User(std::string ID, std::string name, std::string insititude) : 
			m_name(name), m_ID(ID), m_insititude(insititude) {}
	~User(){}

	bool operator < (const User* user)
	{
		return this->m_ID < user->m_ID;
	}

 	std::string getID();
	std::string getName();
	std::string getInsititude();

    virtual user_type getUserType() {}	//获取用户类型

private:
	std::string m_name;			//用户姓名
	std::string m_ID;			//用户学号或者教工号
	std::string m_insititude;	//用户所属学院
};

//由User类派生出学生子类，代表学生用户
class Student: public User
{
public:
	using User::User;
	~Student() {

	}

	using User::operator<;

	std::string getClass();
	void setClass(std::string class_name);

	std::map<Course_student*, float> getGrade();	//学生获取自己的课程及其对应成绩
	std::set<Course_student*> getCourse();			//学生获取自己的课程（可对其课程进行设置）

	bool addCourse(Course_student* course);			//学生选课
	bool deleteCourse(Course_student* course);		//学生删除已选课程

    user_type getUserType() final override;				//获取用户类型(0代表管理员，1代表学生，2代表教师)

private:
	std::string m_class;							//学生所属班级
	std::set<Course_student*> m_course;				//学生对应课程
};

//由User类派生出教师子类，代表教师用户
class Teacher : public User
{
public:
	using User::User;

	using User::operator<;

	std::set<Course_teacher*> getCourse();	//教师获取自己课程列表

    user_type getUserType() final override;		//获取用户类型

private:
	std::set<Course_teacher*> m_course;		//教师任课课程
};

//超级管理员用户
class Admin : public User
{
public:
	using User::User;
	using User::operator<;

	void activateEnvir(Envir* envir);		//激活当前工作环境

	std::set<Course_admin*> getCourse();
	void addObligatoryCourse(std::string ID, std::string name, int credit);
	void addElectiveCourse(std::string ID, std::string name, int credit);

    user_type getUserType() final override;		//获取用户类型

	void addUserStudent(std::string ID, std::string name, std::string insititude);
	void addUserTeacher(std::string ID, std::string name, std::string insititude);
	void addUserAdmin(std::string ID, std::string name, std::string insititude);

    std::map<Student*, std::string> getUserStudent();
    std::map<Teacher*, std::string> getUserTeacher();
    std::map<Admin*, std::string> getUserAdmin();

private:
	std::set<Course_admin*> m_course;		//管理所有课程权限
	Envir* m_envir;							//当前系统环境
};
