#pragma once

#include "include.h"
#include "course.h"
#include "environment.h"

//User����������û�����
class User
{
public:
    User(){}
	User(std::string ID, std::string name, std::string insititude) : 
			m_name(name), m_ID(ID), m_insititude(insititude) {}
	~User(){}

    bool operator <(User& user)
    {
        return this->m_ID < user.getID();
    }

    friend std::istream& operator >> (std::istream& input, User& user);
    friend std::ostream& operator << (std::ostream& output, User& user);

 	std::string getID();
	std::string getName();
	std::string getInsititude();

    virtual user_type getUserType() {}	//��ȡ�û�����

protected:
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
        eraseCourse();
	}

    friend std::istream& operator >> (std::istream& input, Student& student);
    friend std::ostream& operator << (std::ostream& output, Student& student);

	std::string getClass();
	void setClass(std::string class_name);

    void initCourse(std::set<Course_student*> course, std::set<Course_student *> select_course);  //ͬ��ѧ���γ��б�
    void eraseCourse();

	std::map<Course_student*, float> getGrade();	//ѧ����ȡ�Լ��Ŀγ̼����Ӧ�ɼ�
	std::set<Course_student*> getCourse();			//ѧ����ȡ�Լ��Ŀγ̣��ɶ���γ̽������ã�

    std::set<Course_student*> getSelectCourse();    //ѧ����ȡ��ѡ�γ�

    void addCourse(Course_student* course);			//ѧ��ѡ��
	bool deleteCourse(Course_student* course);		//ѧ��ɾ����ѡ�γ�

    user_type getUserType() final override;				//��ȡ�û�����

private:
	std::string m_class;							//ѧ�������༶
	std::set<Course_student*> m_course;				//ѧ����Ӧ�γ�
    std::set<Course_student*> m_select_course;      //ѧ����Ӧ��ѡ�γ�
};

//��User����������ʦ���࣬�����ʦ�û�
class Teacher : public User
{
public:
	using User::User;
    ~Teacher(){
        eraseCourse();
    }

    void initCourse(std::set<Course_teacher*> course);
    void eraseCourse();

    Course_teacher* findCourse(std::string id);

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
    ~Admin(){}

	void activateEnvir(Envir* envir);		//���ǰ��������

    user_type getUserType() final override;		//��ȡ�û�����

    Envir* getEnvir();                      //��ȡ��ǰϵͳ����

/*    void addObligatoryCourse(std::string ID, std::string name, int credit);
    void addElectiveCourse(std::string ID, std::string name, int credit);

	void addUserStudent(std::string ID, std::string name, std::string insititude);
	void addUserTeacher(std::string ID, std::string name, std::string insititude);
	void addUserAdmin(std::string ID, std::string name, std::string insititude);

    std::map<Student*, std::string> getUserStudent();
    std::map<Teacher*, std::string> getUserTeacher();
    std::map<Admin*, std::string> getUserAdmin();
*/
private:
	Envir* m_envir;							//��ǰϵͳ����
};
