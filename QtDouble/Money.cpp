/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12911723/qt-qstringtodouble-produces-inexact-results
 */

#include <QStringList>
#include <QApplication>
#include <QDebug>

struct Money {
    int integ;
    int fract;
};

Money parseMoney(const QString& input) {
    QString cleanInput = input;
    Money result = {0,0};

    // remove group separators
    QLocale locale = QLocale::system();
    cleanInput.remove(locale.groupSeparator());

    // convert to money
    QStringList parts = cleanInput.split(locale.decimalPoint());
    if (parts.count() == 1) {
       result.integ = parts[0].toInt();
    } else if (parts.count() == 2) {
       result.integ = parts[0].toInt();
       result.fract = parts[1].toInt() * 10;
    } else {
         // error, not a number
    }

    return result;
}


int main(int argc, char ** argv) {
    QApplication app( argc, argv );

    int i = ((QString)"294.4").toDouble() * 100;
    qDebug() << i;

    double d = 294.4;
    qDebug() << d;

    int i2 = d * 100.0;
    qDebug() << i2;

    // Assumption: string has the format "nnn,nnn.nn"
    QString input = "3,294.4";
    Money m = parseMoney(input);
    qDebug() << input << " = " << m.integ << "," << m.fract;
}

