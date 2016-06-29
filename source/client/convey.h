#ifndef CONVEY_H
#define CONVEY_H

#include <QString>
#include <QObject>
#include <QTcpSocket>
#include <QtCore>
#include <QMap>
#include "include.h"
#include "model_struct.h"

class Convey: public QObject
{
    Q_OBJECT

public:
    Convey();

    void connectToHost(QString hostname, int port);

    void sendJsonDoc(QJsonDocument jsondoc);                //发送jsondoc对象

    bool translateJsonAck(QByteArray jsonbyte);             //解析服务器端返回的确认包
    User_model translateJsonUser(QJsonObject jsonobj);      //解析jsonobj到User结构体
    Course_model translateJsonCourse(QJsonObject jsonobj);  //解析jsonobj到Course结构体

    User_model verifyUser(QString username, QString password);     //登录验证用户

    std::vector<Course_model> getCourse(QString mode);
    std::vector<Course_model> getCurCourse();   //获取当前用户课程
    std::vector<Course_model> getSelCourse();   //学生获取可选课程

    //获取对应课程或用户的详细信息
    std::pair<Course_model, std::vector<User_model> > getCourseInfo(QString course_id);
    std::pair<User_model, std::vector<Course_model> > getUserInfo(QString user_id);

    //学生选课或者删除已选课程
    void sendPostCourse(QString course_id, QString mode);   //通过mode选择添加还是删除课程
    void sendSelCourse(QString course_id);
    void sendDelCourse(QString course_id);

    void sendStuGrade(QString course_id, QMap<QString, QVariant> stu_grade);

    //管理员修改指定课程或者用户的详细信息
    bool sendCourseInfo(QString course_id, Course_model cur_course, std::vector<User_model> course_stu);
    bool sendUserInfo(QString user_id, User_model cur_user, std::vector<Course_model> user_course);

private slots:
    void destroyConnect();  //断开连接

private:
    QTcpSocket m_convey_socket;
};

#endif // CONVEY_H
