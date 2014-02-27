/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/22063816/how-to-print-something-on-qtextedit-not-setting-text-on-it-with-settext
 */

#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

int main(int argc, char ** argv) {
    QCoreApplication a(argc, argv);

    int X = 42;
    QString str;
    QTextStream out(&str);
    out << "The value of X is " << X << endl;
    qDebug() << str;
    
    return a.exec();
}
