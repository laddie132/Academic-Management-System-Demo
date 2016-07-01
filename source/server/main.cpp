#include <QDebug>
#include <QString>
#include <QTextCodec>
#include <QCoreApplication>

#include "include.h"
#include "convey_server.h"
#include "convey_thread.h"
#include "config.h"
#include "environment.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

    //设置运行环境
    Envir envir;

    //设置配置文件
    Config_file config;
    config.setEnvir(&envir);

    //读取配置文件
    try{
        config.readConfig();
    }
    catch(std::runtime_error &e){
        qDebug() << e.what();
        return a.exec();
    }

    //开启服务器监听
    Convey_server server;
    server.setEnvir(&envir);
    server.setConfig(&config);
    server.listen(QHostAddress("0.0.0.0"), 10010);

    return a.exec();
}
