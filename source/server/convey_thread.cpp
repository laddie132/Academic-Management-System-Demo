#include <QtCore>

#include "convey_thread.h"

Convey_thread::Convey_thread(int socketDescriptor, Envir* envir, Config_file* config, QObject *parent):
    m_socketDescriptor(socketDescriptor),
    m_envir(envir),
    m_config(config),
    QThread(parent)
{

}

void Convey_thread::run()
{
    QTcpSocket socket;
    if(!socket.setSocketDescriptor(m_socketDescriptor))
    {
        emit error(socket.error());
        return;
    }

    socket.setSocketOption(QAbstractSocket::LowDelayOption, "1");    //启用nagle低延迟算法
    socket.setSocketOption(QAbstractSocket::KeepAliveOption, "1");   //设置保持连接状态

    //断开连接时退出循环关闭线程
    connect(&socket, SIGNAL(disconnected()), this, SLOT(changeState()));

    //保存客户端地址和端口
    m_client.first = socket.peerAddress().toString().toStdString();
    m_client.second = socket.peerPort();

    std::cout << "Client " << m_client.first << ":"
              << m_client.second << " connect successfully\n";

    //有效循环
    while(m_valid)
    {
        //等待客户端请求事件
        socket.waitForReadyRead(10000000);
        QByteArray byte = socket.readAll();
        QJsonDocument jsondoc;
        QJsonParseError jsonerror;
        jsondoc = QJsonDocument::fromJson(byte, &jsonerror);
        if(jsonerror.error == QJsonParseError::NoError)
        {
            std::cout << m_client.first << ":" << m_client.second << "\n";
            std::cout << jsondoc.toJson(QJsonDocument::Indented).toStdString();

            //回复客户端请求
            QByteArray send_byte = translateClient(jsondoc);
            socket.write(send_byte);
            socket.flush();
        }
    }

    std::cout << "Client " << m_client.first << ":" << m_client.second << " disconnected\n";
}

QByteArray Convey_thread::translateClient(QJsonDocument jsondoc)
{
    QJsonObject jsonobj;
    QJsonValue jsonvalue;
    if(jsondoc.isObject())
    {
        jsonobj = jsondoc.object();

        //客户端请求验证
        if(jsonobj.contains("verify"))
        {
            jsonvalue = jsonobj.take("verify");
            if(jsonvalue.isObject())
            {
                return translateVerify(jsonvalue.toObject());
            }
        }

        //客户端请求数据
        if(jsonobj.contains("get"))
        {
            jsonvalue = jsonobj.take("get");
            return translateGet(jsonvalue);
        }

        //客户端请求修改数据
        if(jsonobj.contains("post"))
        {
            jsonvalue = jsonobj.take("post");
            if(jsonvalue.isObject())
            {
                return translatePost(jsonvalue.toObject());
            }
        }
    }
}

QByteArray Convey_thread::translateVerify(QJsonObject jsonobj)
{
    QJsonValue jsonvalue;
    QJsonObject tempobj;

    QString username, password;
    if(jsonobj.contains("username"))
    {
        jsonvalue = jsonobj.take("username");
        if(jsonvalue.isString())
        {
            username = jsonvalue.toString();
        }
    }
    if(jsonobj.contains("password"))
    {
        jsonvalue = jsonobj.take("password");
        if(jsonvalue.isString())
        {
            password = jsonvalue.toString();
        }
    }

    User* temp_user = m_envir->checkUserStudent(username.toStdString(), password.toStdString());
    if(!temp_user){
        temp_user = m_envir->checkUserTeacher(username.toStdString(), password.toStdString());
        if(!temp_user){
            temp_user = m_envir->checkUserAdmin(username.toStdString(), password.toStdString());
        }
    }

    //验证用户成功
    if(temp_user){
        tempobj.insert("ack", true);
        tempobj.insert("user", generateUser(temp_user));

        m_user = m_envir->findUser(username.toStdString());     //缓存用户对象指针
        if(m_user->getUserType() == user_type::student)
        {
            m_envir->setCourseStudent((Student*)m_user);
        }
        else if(m_user->getUserType() == user_type::teacher)
        {
            m_envir->setCourseTeacher((Teacher*)m_user);
        }
    }
    else{
        tempobj.insert("ack", false);

        m_user = NULL;
    }

    QJsonDocument jsondoc;
    jsondoc.setObject(tempobj);
    return jsondoc.toJson();
}

QByteArray Convey_thread::translateGet(QJsonValue get_value)
{
    if(!m_user)
        return QByteArray("");

    QJsonValue jsonvalue;
    QJsonDocument jsondoc;
    QJsonArray jsonarray;
    QJsonObject jsonobj, tempobj;

    if(get_value.isString())
    {
        QString get_string = get_value.toString();

        //获取当前课程
        if(get_string == "cur_course")
        {
            if(m_user->getUserType() == user_type::student)
            {
                Student* cur_student = (Student*)m_user;
                for(auto i : cur_student->getCourse())
                {
                    jsonarray.append(generateCourse(i));
                }
            }
            else if(m_user->getUserType() == user_type::teacher)
            {
                Teacher* cur_teacher = (Teacher*)m_user;
                for(auto i : cur_teacher->getCourse())
                {
                    jsonarray.append(generateCourse(i));
                }
            }
            else
            {

            }

            jsonobj.insert("cur_course", jsonarray);
        }

        //学生获取可选课程
        else if(get_string == "sel_course")
        {
            if(m_user->getUserType() == user_type::student)
            {
                Student* cur_student = (Student*)m_user;
                for(auto i : cur_student->getSelectCourse())
                {
                    jsonarray.append(generateCourse(i));
                }
                jsonobj.insert("sel_course", jsonarray);
            }
        }
    }

    else if(get_value.isObject())
    {
        QJsonObject get_object = get_value.toObject();

        //获取课程详细信息
        if(get_object.contains("course_info"))
        {
            QJsonObject info_obj;

            jsonvalue = get_object.take("course_info");
            if(jsonvalue.isString())
            {
                QString course_id = jsonvalue.toString();

                if(m_user->getUserType() == user_type::teacher)
                {
                    Teacher* cur_teacher = (Teacher*)m_user;
                    Course_teacher* cur_course = cur_teacher->findCourse(course_id.toStdString());
                    info_obj.insert("course", generateCourse(cur_course));  //插入课程信息

                    for(auto i : cur_course->getStudentGrade()) //生成学生名单
                    {
                        tempobj = generateUser(i.first);
                        tempobj.insert("grade", i.second);
                        jsonarray.append(tempobj);
                    }

                    info_obj.insert("student", jsonarray);          //插入学生信息
                }
                else if(m_user->getUserType() == user_type::admin)
                {

                }

                jsonobj.insert("course_info", info_obj);
            }
        }

        //获取用户详细信息
        if(get_object.contains("user_info"))
        {
            jsonvalue = get_object.take("user_info");
        }
    }

    jsondoc.setObject(jsonobj);
    return jsondoc.toJson(QJsonDocument::Compact);
}

QByteArray Convey_thread::translatePost(QJsonObject jsonobj)
{
    if(!m_user)
        return QByteArray("");

    QJsonDocument jsondoc;
    QJsonObject rtnobj = generateAck(false);
    QJsonValue jsonvalue;
    QString course_id = "";

    //学生选择选修课
    if(jsonobj.contains("sel_course"))
    {
        jsonvalue = jsonobj.take("sel_course");
        if(jsonvalue.isString())
        {
            QString course_id = jsonvalue.toString();
            if(m_user->getUserType() == user_type::student)
            {
                Student* cur_student = (Student*)m_user;
                Course_student* cur_course = cur_student->findSelCourse(course_id.toStdString());

                if(cur_course)
                {
                    cur_student->addCourse(cur_course);
                    rtnobj = generateAck(true);

                    if(m_config)
                    {
                        m_config->writeConfig();
                    }
                }
            }
        }
    }

    //学生删除选修课
    if(jsonobj.contains("del_course"))
    {
        jsonvalue = jsonobj.take("del_course");
        if(jsonvalue.isString())
        {
            QString course_id = jsonvalue.toString();
            if(m_user->getUserType() == user_type::student)
            {
                Student* cur_student = (Student*)m_user;
                Course_student* cur_course = cur_student->findCourse(course_id.toStdString());

                if(cur_course)
                {
                    cur_student->deleteCourse(cur_course);
                    rtnobj = generateAck(true);

                    if(m_config)
                    {
                        m_config->writeConfig();
                    }
                }
            }
        }
    }

    //设置当前课程id
    if(jsonobj.contains("course_id"))
    {
        jsonvalue = jsonobj.take("course_id");
        if(jsonvalue.isString())
        {
            course_id = jsonvalue.toString();
        }
    }

    //教师更改学生成绩
    if(jsonobj.contains("stu_grade"))
    {
        jsonvalue = jsonobj.take("stu_grade");
        if(m_user->getUserType() == user_type::teacher)
        {
            Teacher* cur_teacher = (Teacher*)m_user;
            Course_teacher* cur_course = cur_teacher->findCourse(course_id.toStdString());

            if(cur_course)
            {
                if(jsonvalue.isObject())
                {
                    QJsonObject tempobj = jsonvalue.toObject();
                    for(auto i : tempobj.keys())
                    {
                        Student* pre_student = cur_course->findStudent(i.toStdString());
                        float grade = tempobj.take(i).toDouble();
                        try{
                            cur_course->setGrade(std::make_pair(pre_student, grade));
                            rtnobj = generateAck(true);

                            if(m_config)
                            {
                                m_config->writeConfig();
                            }
                        }
                        catch(std::invalid_argument& e)
                        {
                            qDebug() << e.what();
                        }
                    }
                }
            }
        }
    }

    jsondoc.setObject(rtnobj);
    return jsondoc.toJson(QJsonDocument::Compact);
}

QJsonObject Convey_thread::generateAck(bool ack_flag)
{
    QJsonObject jsonobj;
    jsonobj.insert("ack", ack_flag);
    return jsonobj;
}

QJsonObject Convey_thread::generateUser(User *user)
{
    QJsonObject jsonobj;

    jsonobj.insert("id", QString::fromStdString(user->getID()));
    jsonobj.insert("name", QString::fromStdString(user->getName()));
    jsonobj.insert("institude", QString::fromStdString(user->getInsititude()));

    switch(user->getUserType())
    {
    case user_type::student:
    {
        Student* temp_student = (Student*)user;
        jsonobj.insert("class_name", QString::fromStdString(temp_student->getClass()));
        jsonobj.insert("user_type", 2);
        break;
    }

    case user_type::teacher:
    {
        Teacher* temp_teacher = (Teacher*)user;
        jsonobj.insert("user_type", 1);
        break;
    }

    case user_type::admin:
    {
        Admin* temp_admin = (Admin*)user;
        jsonobj.insert("user_type", 0);
        break;
    }

    default:
        break;
    }

    return jsonobj;
}

QJsonObject Convey_thread::generateCourse(Course *course)
{
    QJsonObject jsonobj;
    if(!m_user)
        return jsonobj;
    jsonobj.insert("id", QString::fromStdString(course->getID()));
    jsonobj.insert("name", QString::fromStdString(course->getName()));
    jsonobj.insert("credit", course->getCredit());
    jsonobj.insert("capacity", course->getCapicity());
    jsonobj.insert("course_type", course->getCourseType());
    jsonobj.insert("cur_num", (int)course->getStudent().size());
    return jsonobj;
}

QJsonObject Convey_thread::generateCourse(Course_user *course)
{
    QJsonObject jsonobj;
    if(!m_user)
        return jsonobj;
    jsonobj.insert("id", QString::fromStdString(course->getID()));
    jsonobj.insert("name", QString::fromStdString(course->getName()));
    jsonobj.insert("credit", course->getCredit());
    jsonobj.insert("capacity", course->getCapicity());
    jsonobj.insert("course_type", course->getCourseType());

    if(m_user->getUserType() == user_type::student)
    {
        Course_student* cur_course = (Course_student*)course;
        jsonobj.insert("cur_num", cur_course->getElectiveNum());
        jsonobj.insert("grade", cur_course->getMyGrade((Student*)m_user));
        jsonobj.insert("gpa", cur_course->calculateGPA((Student*)m_user));
    }
    else if(m_user->getUserType() == user_type::teacher)
    {
        Course_teacher* cur_course = (Course_teacher*)course;
        jsonobj.insert("cur_num", (int)cur_course->getStudent().size());
    }

    return jsonobj;
}

void Convey_thread::changeState()
{
    this->m_valid = false;
}
