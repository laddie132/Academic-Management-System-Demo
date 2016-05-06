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
	void setClass(std::string class);

	std::map<Course*, float> getGrade();
	std::set<Course*> getCourse();

private:
	std::string m_class;					//学生所属班级
	std::set<Course*> m_course;				//学生对应课程和成绩
};

//由User类派生出教师子类，代表教师用户
class Teacher : public User
{
public:
	using User::User;
	~Teacher();

	Course getCourse();

	void setCourseGrade(Course* course, Student* student, float grade);

private:
	std::set<Course*> m_course;	//教师任课课程
};