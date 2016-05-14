#pragma once

#include "include.h"
#include "environment.h"
#include "user.h"

//�γ���
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

	void setCapicity(int num);						//���ÿγ�����

	Teacher* getTeacher();							//��ȡ��ǰ�γ̽�ʦ��Ϣ
	void setTeacher(Teacher* teacher);				//���õ�ǰ�γ̽�ʦ��Ϣ

	std::set<Student*> getStudent();				//��ȡ��ǰѧ����Ϣ
	bool addStudent(Student* student);				//���ѧ����Ϣ
	bool deleteStudent(Student* student);			//ɾ����ǰѧ����Ϣ

	std::map<Student*, float> getStudentGrade();				//��ȡ��ǰ�γ�ѧ���ɼ�
	bool setGrade(std::pair<Student*, float> student_grade);	//����ѧ���ɼ�

	float getMyGrade(Student* student);				//��ȡָ��ѧ���ĳɼ�

	virtual float calculateGPA(Student* student) {}	//���㼨��
	virtual int getCourseType() {}					//��ȡ�γ�����(����0����ѡ�ޣ�1�������)

protected:
	std::map<Student*, float> m_student;	//ѡ��ѧ�����Ӧ�ɼ�

private:
	std::string m_ID;						//�γ̱��
	std::string m_name;						//�γ�����
	int m_credit;							//�γ�ѧ��
	int m_capicity = 100;					//���γ�����

	Teacher* m_teacher;						//�ڿν�ʦ
};

//���޿�
class Obligatory_course: public Course
{
public:
	using Course::Course;
	using Course::operator<;

	float calculateGPA(Student* student) final override;	//���ؿγ��м���GPA���麯��

	int getCourseType() final override;
};

//ѡ�޿�
class Elective_course: public Course
{
public:
	using Course::Course;
	using Course::operator<;

	float calculateGPA(Student* student) final override;	//���ؿγ��м���GPA���麯��

	int getCourseType() final override;
};

//���°�װȨ�޺�Ŀγ���
class Course_user
{
public:
	Course_user(Course* course) : m_course(course){}
	~Course_user();

	bool operator < (const Course_user* course)
	{
		return m_course->getID() < course->m_course->getID();
	}

	//ѧ�����ʦ����Ȩ��
	std::string getID();
	std::string getName();
	int getCredit();
	int getCourseType();

protected:
	Course* m_course;
};

//ѧ���˿ɲ����Ŀγ���
class Course_student: public Course_user
{
public:
	using Course_user::Course_user;
	using Course_user::operator<;

	float getMyGrade(Student* student);			//ѧ����ȡ�Լ��ĳɼ�

	float calculateGPA(Student* student);		//���㼨��

	std::string getTeacherName();				//��ȡ��ǰ��ʦ��Ϣ

	bool addElectiveStudent(Student* student);			//ѧ������ѡ�޿�
	bool deleteElectiveStudent(Student* student);		//ѧ��ɾ��ѡ�޿�
};

//��ʦ�˿ɲ����Ŀγ���
class Course_teacher: public Course_user
{
public:
	using Course_user::Course_user;
	using Course_user::operator<;

	std::set<Student*> getStudent();				//��ȡ��ǰѧ����Ϣ

	std::map<Student*, float> getStudentGrade();	//��ȡ��ǰ�γ�ѧ���ɼ�
	bool setGrade(std::pair<Student*, float> student_grade);	//����ѧ���ɼ�
};

//��߹���ԱȨ�޵Ŀγ���
class Course_admin: public Course_teacher, public Course_student
{
public:
	using Course_student::Course_student;
    using Course_student::operator<;

	Teacher* getTeacher();							//��ȡ��ǰ�γ̽�ʦ��Ϣ
	void setTeacher(Teacher* teacher);				//���õ�ǰ�γ̽�ʦ��Ϣ

	void setCapicity(int num);

	bool addStudent(Student* student);				//���ѧ��
	bool deleteStudent(Student* student);			//ɾ��ѧ��
};
