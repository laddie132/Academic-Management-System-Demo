#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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
        QMessageBox::warning(&widget_main_admin, QString::fromLocal8Bit("警告"), QString::fromStdString(e.what()));
        exit(1);
    }

    return a.exec();
}
