#pragma once
//����C++��׼ͷ�ļ��Լ��������ǰ������

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

//��ͨ��
class Course;
class Course_student;
class Course_teacher;
class Course_admin;
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
class Envir_widget;

enum user_type
{
    student,
    teacher,
    admin
};

