#pragma once

#include "include.h"
#include "environment.h"
#include "user.h"

//课程类
class Course
{
public:
	Course(std::string id, std::string name, int credit);
	~Course();

	bool operator < (const Course* course)
	{
		return this->m_ID < course->m_ID;
	}

	std::string getID();					
	std::string getName();
	int getCredit();		

	void setCapicity(int num);						//设置课程容量

	Teacher* getTeacher();							//获取当前课程教师信息
	void setTeacher(Teacher* teacher);				//设置当前课程教师信息

	std::set<Student*> getStudent();				//获取当前学生信息
	bool addStudent(Student* student);				//添加学生信息
	bool deleteStudent(Student* student);			//删除当前学生信息

	std::map<Student*, float> getStudentGrade();				//获取当前课程学生成绩
	bool setGrade(std::pair<Student*, float> student_grade);	//设置学生成绩

	float getMyGrade(Student* student);				//获取指定学生的成绩

	virtual float calculateGPA(Student* student) {}	//计算绩点
	virtual int getCourseType() {}					//获取课程类型(返回0代表选修，1代表必修)

protected:
	std::map<Student*, float> m_student;	//选课学生与对应成绩

private:
	std::string m_ID;						//课程编号
	std::string m_name;						//课程名称
	int m_credit;							//课程学分
	int m_capicity = 100;					//最大课程容量

	Teacher* m_teacher;						//授课教师
};

//必修课
class Obligatory_course: public Course
{
public:
	using Course::Course;
	using Course::operator<;

	float calculateGPA(Student* student) final override;	//重载课程中计算GPA的虚函数

	int getCourseType() final override;
};

//选修课
class Elective_course: public Course
{
public:
	using Course::Course;
	using Course::operator<;

	float calculateGPA(Student* student) final override;	//重载课程中计算GPA的虚函数

	int getCourseType() final override;
};

//重新包装权限后的课程类
class Course_user
{
public:
	Course_user(Course* course) : m_course(course){}
	~Course_user();

	bool operator < (const Course_user* course)
	{
		return m_course->getID() < course->m_course->getID();
	}

	//学生与教师公共权限
	std::string getID();
	std::string getName();
	int getCredit();
	int getCourseType();

protected:
	Course* m_course;
};

//学生端可操作的课程类
class Course_student: public Course_user
{
public:
	using Course_user::Course_user;
	using Course_user::operator<;

	float getMyGrade(Student* student);			//学生获取自己的成绩

	float calculateGPA(Student* student);		//计算绩点

	std::string getTeacherName();				//获取当前教师信息

	bool addElectiveStudent(Student* student);			//学生增加选修课
	bool deleteElectiveStudent(Student* student);		//学生删除选修课
};

//教师端可操作的课程类
class Course_teacher: public Course_user
{
public:
	using Course_user::Course_user;
	using Course_user::operator<;

	std::set<Student*> getStudent();				//获取当前学生信息

	std::map<Student*, float> getStudentGrade();	//获取当前课程学生成绩
	bool setGrade(std::pair<Student*, float> student_grade);	//设置学生成绩
};

//最高管理员权限的课程类
class Course_admin: public Course_teacher, public Course_student
{
public:
	using Course_student::Course_student;
    using Course_student::operator<;

	Teacher* getTeacher();							//获取当前课程教师信息
	void setTeacher(Teacher* teacher);				//设置当前课程教师信息

	void setCapicity(int num);

	bool addStudent(Student* student);				//添加学生
	bool deleteStudent(Student* student);			//删除学生
};
