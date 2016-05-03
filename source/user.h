#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

#include "course.h"

//User类代表所有用户类型
class User
{
public:
	User();
	~User();

 	std::string getID();
	void setID(std::string arg);

	std::string getName();
	void setName(std::string arg);

	std::string getInsititude();
	void setInsititude(std::string arg);

private:
	std::string _name;			//用户姓名
	std::string _ID;			//用户学号或者教工号
	std::string _insititude;	//用户所属学院
};

//由User类派生出学生子类，代表学生用户
class Student: public User
{
public:
	Student();
	~Student();

	std::string getClass();
	void setClass();

private:
	std::string _class;		//学生所属班级
};

//由User类派生出教师子类，代表教师用户
class Teacher : public User
{
public:
	Teacher();
	~Teacher();

	Course getCourse();
	void setCourse(Course arg);

private:
	Course* _course;	//教师任课课程
};