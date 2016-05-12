#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

#include "course.h"

//User类代表所有用户类型
class User
{
public:
	User(std::string name, std::string id, std::string insititude);
	~User();

 	std::string getID();
	std::string getName();
	std::string getInsititude();

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
	~Student();

	std::string getClass();
	void setClass(std::string class_name);

	std::map<Course_student*, float> getGrade();	//学生获取自己的课程及其对应成绩
	std::set<Course_student*> getCourse();			//学生获取自己的课程（可对其课程进行设置）

	bool deleteCourse(Course_student* course);

private:
	std::string m_class;							//学生所属班级
	std::set<Course_student*> m_course;				//学生对应课程
};

//由User类派生出教师子类，代表教师用户
class Teacher : public User
{
public:
	using User::User;
	~Teacher();

	std::set<Course_teacher*> getCourse();			//教师获取自己课程列表

private:
	std::set<Course_teacher*> m_course;		//教师任课课程
};

//超级管理员用户
class admin : public User
{
public:
	using User::User;

	std::set<Course_admin*> getCourse();

private:
	std::set<Course_admin*> m_course;		//管理所有课程权限
};