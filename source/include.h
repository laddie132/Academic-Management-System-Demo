#pragma once
//����C++��׼ͷ�ļ��Լ��������ǰ������

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <exception>

//��ͨ��
class Course;
class Obligatory_course;
class Elective_course;
class Course_student;
class Course_teacher;
//class Course_admin;
class Course_user;
class User;
class Student;
class Teacher;
class Admin;
class Envir;

//������
class Login;
class MainWindow_student;
class MainWindow_teacher;
class MainWindow_admin;
class Information_user;
class Information_course;
class Envir_widget;

enum user_type
{
    student,
    teacher,
    admin
};

