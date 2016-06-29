#include "convey_server.h"

Convey_server::Convey_server(QObject *parent):
    QTcpServer(parent)
{

}

void Convey_server::setEnvir(Envir *envir)
{
    this->m_envir = envir;
}

void Convey_server::incomingConnection(qintptr socketDescriptor)
{
    Convey_thread* thread = new Convey_thread(socketDescriptor, m_envir, this);
    this->m_client.push_back(socketDescriptor);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
