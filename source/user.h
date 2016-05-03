#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

#include "course.h"

//User����������û�����
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
	std::string _name;			//�û�����
	std::string _ID;			//�û�ѧ�Ż��߽̹���
	std::string _insititude;	//�û�����ѧԺ
};

//��User��������ѧ�����࣬����ѧ���û�
class Student: public User
{
public:
	Student();
	~Student();

	std::string getClass();
	void setClass();

private:
	std::string _class;		//ѧ�������༶
};

//��User����������ʦ���࣬�����ʦ�û�
class Teacher : public User
{
public:
	Teacher();
	~Teacher();

	Course getCourse();
	void setCourse(Course arg);

private:
	Course* _course;	//��ʦ�οογ�
};