#ifndef USER_H
#define USER_H

//课程结构体
struct course_module{
    std::string id;
    std::string name;
    int credit;
    int capacity;
    float grade;
    float gpa;
};

//用户结构体
struct user_model
{
    std::string id;
    std::string name;
    std::string class_name = "";
    std::string institude;
    float grade = 0;
    float gpa = 0;
};

#endif // USER_H
