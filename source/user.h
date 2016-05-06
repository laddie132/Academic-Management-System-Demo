#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

#include "course.h"

//User����������û�����
class User
{
public:
	User(std::string name, std::string id, std::string insititude);
	~User();

 	std::string getID();
	std::string getName();
	std::string getInsititude();

private:
	std::string m_name;			//�û�����
	std::string m_ID;			//�û�ѧ�Ż��߽̹���
	std::string m_insititude;	//�û�����ѧԺ
};

//��User��������ѧ�����࣬����ѧ���û�
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
	std::string m_class;					//ѧ�������༶
	std::set<Course*> m_course;				//ѧ����Ӧ�γ̺ͳɼ�
};

//��User����������ʦ���࣬�����ʦ�û�
class Teacher : public User
{
public:
	using User::User;
	~Teacher();

	Course getCourse();

	void setCourseGrade(Course* course, Student* student, float grade);

private:
	std::set<Course*> m_course;	//��ʦ�οογ�
};