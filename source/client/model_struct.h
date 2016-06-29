#ifndef USER_H
#define USER_H

//课程结构体
struct course_model{
    std::string id;
    std::string name;
    int credit;
    int capacity;
    int cur_num;
    float grade;
    float gpa;
    int course_type;
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
    int user_type;
};

typedef struct user_model User_model;
typedef struct course_model Course_model;

#endif // USER_H
