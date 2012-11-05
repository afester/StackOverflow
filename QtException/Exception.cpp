/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13231273/exceptions-cause-crash-qt-sdk-1-2-1-qt4-8-1-mingw-windows
 */

#include <QApplication>
#include <QDebug>

int main(int argc, char ** argv) {
	QCoreApplication app(argc, argv);
	
	qDebug() << "Starting ...";
	try {
		throw QString("lala");
	}
	catch(QString &s) {
		qDebug() << "Catched!";
	}
	qDebug() << "Done.";
}
