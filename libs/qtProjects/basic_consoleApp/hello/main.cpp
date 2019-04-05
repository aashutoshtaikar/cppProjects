#include <QCoreApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); //creates an instance a of the qcore application
    QString mStr = "from asht";
    qDebug()<<"hello world "<<mStr<<endl;
    return a.exec(); //waiting for you to close it
}
