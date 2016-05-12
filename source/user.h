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
	void setClass(std::string class_name);

	std::map<Course_student*, float> getGrade();	//ѧ����ȡ�Լ��Ŀγ̼����Ӧ�ɼ�
	std::set<Course_student*> getCourse();			//ѧ����ȡ�Լ��Ŀγ̣��ɶ���γ̽������ã�

	bool deleteCourse(Course_student* course);

private:
	std::string m_class;							//ѧ�������༶
	std::set<Course_student*> m_course;				//ѧ����Ӧ�γ�
};

//��User����������ʦ���࣬�����ʦ�û�
class Teacher : public User
{
public:
	using User::User;
	~Teacher();

	std::set<Course_teacher*> getCourse();			//��ʦ��ȡ�Լ��γ��б�

private:
	std::set<Course_teacher*> m_course;		//��ʦ�οογ�
};

//��������Ա�û�
class admin : public User
{
public:
	using User::User;

	std::set<Course_admin*> getCourse();

private:
	std::set<Course_admin*> m_course;		//�������пγ�Ȩ��
};