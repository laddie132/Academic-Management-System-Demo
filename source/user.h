#pragma once

#include "include.h"
#include "course.h"
#include "environment.h"

//User����������û�����
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

    virtual user_type getUserType() {}	//��ȡ�û�����

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
	~Student() {

	}

	using User::operator<;

	std::string getClass();
	void setClass(std::string class_name);

	std::map<Course_student*, float> getGrade();	//ѧ����ȡ�Լ��Ŀγ̼����Ӧ�ɼ�
	std::set<Course_student*> getCourse();			//ѧ����ȡ�Լ��Ŀγ̣��ɶ���γ̽������ã�

	bool addCourse(Course_student* course);			//ѧ��ѡ��
	bool deleteCourse(Course_student* course);		//ѧ��ɾ����ѡ�γ�

    user_type getUserType() final override;				//��ȡ�û�����(0�������Ա��1����ѧ����2�����ʦ)

private:
	std::string m_class;							//ѧ�������༶
	std::set<Course_student*> m_course;				//ѧ����Ӧ�γ�
};

//��User����������ʦ���࣬�����ʦ�û�
class Teacher : public User
{
public:
	using User::User;

	using User::operator<;

	std::set<Course_teacher*> getCourse();	//��ʦ��ȡ�Լ��γ��б�

    user_type getUserType() final override;		//��ȡ�û�����

private:
	std::set<Course_teacher*> m_course;		//��ʦ�οογ�
};

//��������Ա�û�
class Admin : public User
{
public:
	using User::User;
	using User::operator<;

	void activateEnvir(Envir* envir);		//���ǰ��������

	std::set<Course_admin*> getCourse();
	void addObligatoryCourse(std::string ID, std::string name, int credit);
	void addElectiveCourse(std::string ID, std::string name, int credit);

    user_type getUserType() final override;		//��ȡ�û�����

	void addUserStudent(std::string ID, std::string name, std::string insititude);
	void addUserTeacher(std::string ID, std::string name, std::string insititude);
	void addUserAdmin(std::string ID, std::string name, std::string insititude);

    std::map<Student*, std::string> getUserStudent();
    std::map<Teacher*, std::string> getUserTeacher();
    std::map<Admin*, std::string> getUserAdmin();

private:
	std::set<Course_admin*> m_course;		//�������пγ�Ȩ��
	Envir* m_envir;							//��ǰϵͳ����
};
