//course.cpp 课程对象

#include <cmath>
#include "course.h"
#include "user.h"

//课程基类函数实现

Course::Course(std::string id, std::string name, int credit)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_credit = credit;
}

Course::~Course()
{

}

std::string Course::getID()
{
	return m_ID;
}

std::string Course::getName()
{
	return m_name;
}

int Course::getCredit()
{
	return m_credit;
}

int Course::getCapicity()
{
    return this->m_capicity;
}

void Course::setCapicity(int num)
{
	this->m_capicity = num;
}

Teacher* Course::getTeacher()
{
	return m_teacher;
}

void Course::setTeacher(Teacher* teacher)
{
	this->m_teacher = teacher;
}

std::set<Student*> Course::getStudent()
{
	std::set<Student*> s;
	for (auto& i : m_student)
	{
		s.insert(i.first);
	}
	return s;
}

bool Course::addStudent(Student* student)
{
    if ((int)m_student.size() < m_capicity) {
        auto i = m_student.find(student);
		if (i != m_student.end()) {
			m_student.insert(std::make_pair(student, -1));
			return true;
		}
	}
	return false;
}

bool Course::deleteStudent(Student* student)
{
    auto i = m_student.find(student);
	if (i != m_student.end())
	{
		m_student.erase(i);
	}
	return false;
}

std::map<Student*, float> Course::getStudentGrade()
{
	return m_student;
}

bool Course::setGrade(std::pair<Student*, float> student_grade)
{
    auto i = m_student.find(student_grade.first);
	if (i != m_student.end()) {
		i->second = student_grade.second;
		return true;
	}
	return false;
}

float Course::getMyGrade(Student* student)
{
    auto i = m_student.find(student);
	if (i != m_student.end())
	{
		return i->second;
	}
	return -1;
}

//必修课函数实现

float Obligatory_course::calculateGPA(Student* student)
{
	int student_num = m_student.size();
	float grade_sum = 0;
	for (auto& i : m_student)
	{
		grade_sum += i.second;
	}
	float my_grade = this->getMyGrade(student);
	float gpa = (student_num * 100 / grade_sum) * (my_grade / 100) * this->getCredit();
	return gpa;
}

int Obligatory_course::getCourseType()
{
	return 1;
}

//选修课函数实现

float Elective_course::calculateGPA(Student* student)
{
	float my_grade = this->getMyGrade(student);
	float gpa = (sqrt(my_grade) / 10) * this->getCredit();
	return gpa;
}

int Elective_course::getCourseType()
{
	return 0;
}

//Course_user类函数实现

std::string Course_user::getID()
{
	return m_course->getID();
}

std::string Course_user::getName()
{
	return m_course->getName();
}

int Course_user::getCredit()
{
	return m_course->getCredit();
}

int Course_user::getCourseType()
{
	return m_course->getCourseType();
}

int Course_user::getCapicity()
{
    return m_course->getCapicity();
}

//Course_student类函数实现

float Course_student::getMyGrade(Student* student)
{
	return m_course->getMyGrade(student);
}

float Course_student::calculateGPA(Student* student)
{
	return m_course->calculateGPA(student);
}

std::string Course_student::getTeacherName()
{
	return m_course->getTeacher()->getName();
}

bool Course_student::addElectiveStudent(Student* student)
{
	//判断待增加课程是否为选修课
	if (!this->getCourseType()) {
		return m_course->addStudent(student);
	}
	return false;
}

bool Course_student::deleteElectiveStudent(Student* student)
{
	if (!this->getCourseType()) {
		return m_course->deleteStudent(student);
	}
	return false;
}

//Course_teacher类函数实现

std::set<Student*> Course_teacher::getStudent()
{
	return m_course->getStudent();
}

std::map<Student*, float> Course_teacher::getStudentGrade()
{
	return m_course->getStudentGrade();
}

bool Course_teacher::setGrade(std::pair<Student*, float> student_grade)
{
	return m_course->setGrade(student_grade);
}

//Course_admin类函数实现

Teacher* Course_admin::getTeacher()
{
    return Course_student::m_course->getTeacher();
}

void Course_admin::setTeacher(Teacher* teacher)
{
    Course_student::m_course->setTeacher(teacher);
}

bool Course_admin::addStudent(Student* student)
{
    return Course_student::m_course->addStudent(student);
}

bool Course_admin::deleteStudent(Student* student)
{
    return Course_student::m_course->deleteStudent(student);
}

void Course_admin::setCapicity(int num)
{
    Course_student::m_course->setCapicity(num);
}
