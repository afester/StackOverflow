/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12889918/qsharedmemoryhandle-doesnt-exist-error
 */

#include <QtCore/QCoreApplication>
#include <QSharedMemory>
#include <QDebug>

QSharedMemory g_objSharedMemory(QString("Shared Memory"));

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(g_objSharedMemory.isAttached()==false)
    {
        qDebug()<<"Shared memory is not attached !!!!trying to attach it\n ";
        qDebug()<<g_objSharedMemory.errorString();

        qDebug()<<"Creating shared memory ...";
        if(g_objSharedMemory.create(42)==false) {
            qDebug()<<"Failed to create shared memory to the process!!!!";
            qDebug()<<g_objSharedMemory.errorString();
		}

        if(g_objSharedMemory.attach()==false)
        {
            qDebug()<<"Failed to attach shared memory to the process!!!!";
            qDebug()<<g_objSharedMemory.errorString();
            return 0;
        }
    }

    return a.exec();
}
