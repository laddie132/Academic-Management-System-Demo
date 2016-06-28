#ifndef CONVEY_H
#define CONVEY_H

#include <QString>
#include <QObject>
#include <QTcpSocket>
#include <QtCore>

class Convey: public QObject
{
    Q_OBJECT

public:
    Convey();

    void connect(QString hostname, int port);

    int verifyUser(QString username, QString password);

private:
    QTcpSocket* m_convey_socket;
};

#endif // CONVEY_H
