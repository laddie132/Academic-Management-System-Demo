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

	std::map<Student*, float> getStudentGrade();	//获取当前课程学生信息

	virtual calculateGPA(float myGrade);	//计算绩点

private:
	std::string m_ID;						//课程编号
	std::string m_name;						//课程名称
	int m_credit;							//课程学分
	std::map<Student*, float> m_student;	//选课学生与对应成绩
	Teacher* m_teacher;						//授课教师
};