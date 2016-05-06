#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#include "user.h"

class Course
{
public:
	Course(std::string id, std::string name, std::string credit);
	~Course();

	std::string getID();					
	std::string getName();
	int getCredit();		

	Teacher* getTeacher();		
	void setTeacher(Teacher* teacher);

	std::set<Student*> getStudent();
	void addStudent(Student* student);

	std::map<Student*, float> getStudentGrade();	//��ȡ��ǰ�γ�ѧ����Ϣ

	virtual calculateGPA(float myGrade);	//���㼨��

private:
	std::string m_ID;						//�γ̱��
	std::string m_name;						//�γ�����
	int m_credit;							//�γ�ѧ��
	std::map<Student*, float> m_student;	//ѡ��ѧ�����Ӧ�ɼ�
	Teacher* m_teacher;						//�ڿν�ʦ
};