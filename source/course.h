#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

#include "user.h"

class Course
{
public:
	virtual calculateGPA(float myGrade);	//���㼨��

private:
	std::string _ID;		//�γ̱��
	std::string _name;		//�γ�����
	std::string _credit;	//�γ�ѧ��
	std::string _num;		//�γ�����
	Student* _student;		//ѡ��ѧ��
};