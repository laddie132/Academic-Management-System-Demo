#ifndef CONVEY_THREAD_H
#define CONVEY_THREAD_H

#include <QObject>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>

#include "environment.h"

class Convey_thread: public QThread
{
    Q_OBJECT

public:
    Convey_thread(int socketDescriptor, Envir* envir, QObject *parent);

    void run() Q_DECL_OVERRIDE;

    //响应客户端请求并解析
    QByteArray translateClient(QJsonDocument jsondoc);
    QByteArray translateVerify(QJsonObject jsonobj);
    QByteArray translateGet(QJsonObject jsonobj);
    QByteArray translatePost(QJsonObject jsonobj);

    QJsonObject generateAck(bool ack_flag);             //生成ack的Json对象
    QJsonObject generateUser(User* user);               //生成User的json对象
    QJsonObject generateCourse(Course* course);         //生成Course的json对象

signals:
    void error(QTcpSocket::SocketError socketError);

private slots:
    void changeState();

private:
    int m_socketDescriptor;
    Envir* m_envir;

    bool m_valid = true;

    std::pair<std::string, int> m_client;
};

#endif // CONVEY_THREAD_H
