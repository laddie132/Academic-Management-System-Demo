#include "convey.h"
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

Convey::Convey()
{
    this->m_convey_socket.setSocketOption(QAbstractSocket::LowDelayOption, "1");    //启用nagle低延迟算法
    this->m_convey_socket.setSocketOption(QAbstractSocket::KeepAliveOption, "1");   //设置保持连接状态
    connect(&m_convey_socket, SIGNAL(disconnected()), this, SLOT(destroyConnect()));
}

void Convey::connectToHost(QString hostname, int port)
{
    this->m_convey_socket.connectToHost(hostname, port);
    bool connected =  this->m_convey_socket.waitForConnected(3000);
    if(!connected)
        throw std::runtime_error("连接失败");
}

void Convey::destroyConnect()
{
    this->m_convey_socket.disconnectFromHost();
    this->m_convey_socket.waitForDisconnected();
}

void Convey::sendJsonDoc(QJsonDocument jsondoc)
{
    if(m_convey_socket.isValid() && !jsondoc.isEmpty()){
        this->m_convey_socket.write(jsondoc.toJson(QJsonDocument::Compact));
        this->m_convey_socket.flush();
    }
    else{
        qDebug() << "Socket Error!";
    }
}

User_model Convey::verifyUser(QString username, QString password)
{
    User_model cur_user;

    //发送json数据包
    QJsonObject tempobj, jsonobj;
    tempobj.insert("username", username);
    tempobj.insert("password", password);
    jsonobj.insert("verify", tempobj);

    QJsonDocument jsondoc;
    jsondoc.setObject(jsonobj);
    sendJsonDoc(jsondoc);

    //接收json数据包
    bool readable = this->m_convey_socket.waitForReadyRead();
    if(readable){
        QByteArray jsonbyte = this->m_convey_socket.readAll();

        //解析json包
        QJsonParseError json_error;
        jsondoc = QJsonDocument::fromJson(jsonbyte, &json_error);
        if(json_error.error == QJsonParseError::NoError){

//            qDebug() << jsondoc;

            if(jsondoc.isObject()){
                jsonobj = jsondoc.object();
                QJsonValue jsonvalue;

                //判断用户合法性
                if(jsonobj.contains("ack"))
                {
                    jsonvalue = jsonobj.take("ack");
                    if(jsonvalue.isBool())
                    {
                        bool verify_true = jsonvalue.toBool();
                        if(!verify_true)
                            return cur_user;
                    }
                }

                //验证通过后接收用户信息
                if(jsonobj.contains("user"))
                {
                    jsonvalue = jsonobj.take("user");
                    if(jsonvalue.isObject())
                    {
                        cur_user = translateJsonUser(jsonvalue.toObject());
                    }
                }
            }
        }
    }
    else{
        qDebug() << "连接超时";
    }

    return cur_user;
}

std::vector<Course_model> Convey::getCourse(QString mode)
{
    std::vector<Course_model> course_list;
    Course_model temp_course;

    //发送json数据包
    QJsonObject jsonobj;
    jsonobj.insert("get", mode);

    QJsonDocument jsondoc;
    jsondoc.setObject(jsonobj);
    sendJsonDoc(jsondoc);

    //接收json数据包
    bool readable = this->m_convey_socket.waitForReadyRead();
    if(readable){
        QByteArray jsonbyte = this->m_convey_socket.readAll();

        //解析json包
        QJsonParseError json_error;
        jsondoc = QJsonDocument::fromJson(jsonbyte, &json_error);
        if(json_error.error == QJsonParseError::NoError){
            if(jsondoc.isObject()){
                jsonobj = jsondoc.object();
                QJsonValue jsonvalue;
                QJsonArray jsonarray;

                if(jsonobj.contains(mode))
                {
                    jsonvalue = jsonobj.take(mode);
                    if(jsonvalue.isArray())
                    {
                        jsonarray = jsonvalue.toArray();
                        for(auto i : jsonarray)
                        {
                            if(i.isObject())
                            {
                                temp_course = translateJsonCourse(i.toObject());
                                course_list.push_back(temp_course);
                            }
                        }
                    }
                }
            }
        }
    }

    return course_list;
}

std::vector<Course_model> Convey::getCurCourse()
{
    return getCourse("cur_course");
}

std::vector<Course_model> Convey::getSelCourse()
{
    return getCourse("sel_course");
}

User_model Convey::translateJsonUser(QJsonObject jsonobj)
{
    QJsonValue jsonvalue;
    User_model cur_user;

    if(jsonobj.contains("id"))
    {
        jsonvalue = jsonobj.take("id");
        if(jsonvalue.isString())
        {
            cur_user.id = jsonvalue.toString().toStdString();
        }
    }

    if(jsonobj.contains("name"))
    {
        jsonvalue = jsonobj.take("name");
        if(jsonvalue.isString())
        {
            cur_user.name = jsonvalue.toString().toStdString();
        }
    }

    if(jsonobj.contains("class_name"))
    {
        jsonvalue = jsonobj.take("class_name");
        if(jsonvalue.isString())
        {
            cur_user.class_name = jsonvalue.toString().toStdString();
        }
    }

    if(jsonobj.contains("institude"))
    {
        jsonvalue = jsonobj.take("institude");
        if(jsonvalue.isString())
        {
            cur_user.institude = jsonvalue.toString().toStdString();
        }
    }

    if(jsonobj.contains("grade"))
    {
        jsonvalue = jsonobj.take("grade");
        if(jsonvalue.isDouble())
        {
            cur_user.grade = jsonvalue.toVariant().toFloat();
        }
    }

    if(jsonobj.contains("user_type"))
    {
        jsonvalue = jsonobj.take("user_type");
        if(jsonvalue.isDouble())
        {
            cur_user.user_type = jsonvalue.toVariant().toInt();
        }
    }

    return cur_user;
}

Course_model Convey::translateJsonCourse(QJsonObject jsonobj)
{
    QJsonValue jsonvalue;
    Course_model cur_course;

    if(jsonobj.contains("id"))
    {
        jsonvalue = jsonobj.take("id");
        if(jsonvalue.isString())
        {
            cur_course.id = jsonvalue.toString().toStdString();
        }
    }

    if(jsonobj.contains("name"))
    {
        jsonvalue = jsonobj.take("name");
        if(jsonvalue.isString())
        {
            cur_course.name = jsonvalue.toString().toStdString();
        }
    }

    if(jsonobj.contains("credit"))
    {
        jsonvalue = jsonobj.take("credit");
        if(jsonvalue.isDouble())
        {
            cur_course.credit = jsonvalue.toVariant().toInt();
        }
    }

    if(jsonobj.contains("cur_num"))
    {
        jsonvalue = jsonobj.take("cur_num");
        if(jsonvalue.isDouble())
        {
            cur_course.cur_num = jsonvalue.toVariant().toInt();
        }
    }

    if(jsonobj.contains("capacity"))
    {
        jsonvalue = jsonobj.take("capacity");
        if(jsonvalue.isDouble())
        {
            cur_course.capacity = jsonvalue.toVariant().toInt();
        }
    }

    if(jsonobj.contains("grade"))
    {
        jsonvalue = jsonobj.take("grade");
        if(jsonvalue.isDouble())
        {
            cur_course.grade = jsonvalue.toVariant().toFloat();
        }
    }

    if(jsonobj.contains("gpa"))
    {
        jsonvalue = jsonobj.take("gpa");
        if(jsonvalue.isString())
        {
            cur_course.gpa = jsonvalue.toVariant().toFloat();
        }
    }

    if(jsonobj.contains("course_type"))
    {
        jsonvalue = jsonobj.take("course_type");
        if(jsonvalue.isDouble())
        {
            cur_course.course_type = jsonvalue.toVariant().toInt();
        }
    }

    return cur_course;
}

bool Convey::translateJsonAck(QByteArray jsonbyte)
{
    QJsonDocument jsondoc;
    QJsonObject jsonobj;

    //解析json包
    QJsonParseError json_error;
    jsondoc = QJsonDocument::fromJson(jsonbyte, &json_error);
    if(json_error.error == QJsonParseError::NoError){
        if(jsondoc.isObject()){
            jsonobj = jsondoc.object();
            QJsonValue jsonvalue;

            //判断是否修改成功
            if(jsonobj.contains("ack"))
            {
                jsonvalue = jsonobj.take("ack");
                if(jsonvalue.isBool())
                {
                    bool verify_true = jsonvalue.toBool();
                    if(verify_true)
                        return true;
                }
            }
        }
    }
    return false;
}

void Convey::sendPostCourse(QString course_id, QString mode)
{
    //发送json数据包
    QJsonObject jsonobj, tempobj;
    tempobj.insert(mode, course_id);
    jsonobj.insert("post", tempobj);

    QJsonDocument jsondoc;
    jsondoc.setObject(jsonobj);
    sendJsonDoc(jsondoc);

    //接收json数据包
    bool readable = this->m_convey_socket.waitForReadyRead();
    if(readable){
        QByteArray jsonbyte = this->m_convey_socket.readAll();
        if(!translateJsonAck(jsonbyte))
            throw std::runtime_error("修改失败！");
    }
    else{
        throw std::runtime_error("发送超时");
    }
}

void Convey::sendSelCourse(QString course_id)
{
    sendPostCourse(course_id, "select_course");
}

void Convey::sendDelCourse(QString course_id)
{
    sendPostCourse(course_id, "delete_course");
}


void Convey::sendStuGrade(QString course_id, QMap<QString, QVariant> stu_grade)
{
    //发送json数据包
    QJsonArray jsonarray;
    QJsonObject jsonobj, tempobj;
    QJsonDocument jsondoc;

    jsondoc = QJsonDocument::fromVariant(QVariant(stu_grade));

    tempobj.insert("stu_grade", jsondoc.object());
    jsonobj.insert("post", tempobj);

    jsondoc.setObject(jsonobj);
    sendJsonDoc(jsondoc);

    //接收json数据包
    bool readable = this->m_convey_socket.waitForReadyRead();
    if(readable){
        QByteArray jsonbyte = this->m_convey_socket.readAll();
        if(!translateJsonAck(jsonbyte))
            throw std::runtime_error("修改失败！");
    }
    else{
        throw std::runtime_error("发送超时");
    }
}

std::pair<Course_model, std::vector<User_model> > Convey::getCourseInfo(QString course_id)
{
    std::vector<User_model> student_list;
    Course_model temp_course;

    //发送json数据包
    QJsonObject jsonobj, tempobj;
    tempobj.insert("course_info", course_id);
    jsonobj.insert("get", tempobj);

    QJsonDocument jsondoc;
    jsondoc.setObject(jsonobj);
    sendJsonDoc(jsondoc);

    //接收json数据包
    bool readable = this->m_convey_socket.waitForReadyRead();
    if(readable){
        QByteArray jsonbyte = this->m_convey_socket.readAll();

        //解析json包
        QJsonParseError json_error;
        jsondoc = QJsonDocument::fromJson(jsonbyte, &json_error);
        if(json_error.error == QJsonParseError::NoError){
            if(jsondoc.isObject())
            {
                QJsonValue jsonvalue;
                jsonobj = jsondoc.object();
                if(jsonobj.contains("course"))
                {
                    jsonvalue = jsonobj.take("course");
                    if(jsonvalue.isObject())
                    {
                        temp_course = translateJsonCourse(jsonvalue.toObject());
                    }
                }

                if(jsonobj.contains("student"))
                {
                    jsonvalue = jsonobj.take("student");
                    if(jsonvalue.isArray())
                    {
                        QJsonArray jsonarray = jsonvalue.toArray();
                        for(auto i : jsonarray)
                        {
                            if(i.isObject())
                            {
                                User_model temp_user = translateJsonUser(i.toObject());
                                student_list.push_back(temp_user);
                            }
                        }
                    }
                }
            }
        }
    }
    return std::make_pair(temp_course, student_list);
}
