#ifndef CONVEY_SERVER_H
#define CONVEY_SERVER_H

#include <QObject>
#include <QVector>
#include <QTcpServer>
#include <QTcpSocket>

#include "convey_thread.h"

class Convey_server: public QTcpServer
{
    Q_OBJECT

public:
    Convey_server(QObject *parent = 0);

    void setEnvir(Envir* envir);

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;

private:
    QVector<int> m_client;

    Envir* m_envir;
};

#endif // CONVEY_SERVER_H
