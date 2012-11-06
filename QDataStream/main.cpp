/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12501140/qt-qstring-from-qdatastream
 */

#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QBuffer>

void myFunc(QDataStream& in)
{
    quint8 v;
    in >> v;
qDebug() << v;
    // Ok, I caught v value successfuly
    QString s;
    in >> s;
qDebug() << s;
    // Didnt work :<
}


int main(int argc, char ** argv) {
    QCoreApplication a(argc, argv);

    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);

    // write test data into the biffer
    QDataStream out(&buffer);
    quint8 ival = 42;
    QString sval = "Qt";
    out << ival;
    out << sval;

    // read back data
    buffer.seek(0);
    myFunc(out);
    
    
    return a.exec();
}
