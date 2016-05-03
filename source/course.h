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
	virtual calculateGPA(float myGrade);	//计算绩点

private:
	std::string _ID;		//课程编号
	std::string _name;		//课程名称
	std::string _credit;	//课程学分
	std::string _num;		//课程人数
	Student* _student;		//选课学生
};