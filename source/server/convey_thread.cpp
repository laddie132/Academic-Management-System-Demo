#include <QtCore>

#include "convey_thread.h"

Convey_thread::Convey_thread(int socketDescriptor, Envir* envir, QObject *parent):
    m_socketDescriptor(socketDescriptor),
    m_envir(envir),
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
            if(jsonvalue.isObject())
            {
                return translateGet(jsonvalue.toObject());
            }
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
    }
    else{
        tempobj.insert("ack", false);
    }

    QJsonDocument jsondoc;
    jsondoc.setObject(tempobj);
    return jsondoc.toJson();
}

QByteArray Convey_thread::translateGet(QJsonObject jsonobj)
{

}

QByteArray Convey_thread::translatePost(QJsonObject jsonobj)
{

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

}

void Convey_thread::changeState()
{
    this->m_valid = false;
}
