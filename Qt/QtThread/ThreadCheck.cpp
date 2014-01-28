/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13357667/qt-thread-signal-slot-issue
 */

#include <QApplication>
#include <QDebug>

#include "ThreadCheck.h"

void ThreadCheck::slotReceived() {
    mutex.lock();
    qDebug() << "hello";
    mutex.unlock();
}

void ThreadCheck::run() {
	qDebug() << "Thread running.";
	 while(1)
     {
         mutex.lock();
         /*
          do some stuff
         */
		 sleep(1);

         mutex.unlock();
         emit signalReceived();
     }
}

int main(int argc, char ** argv) {
	QCoreApplication app(argc, argv);

	ThreadCheck t;
	QObject::connect(&t, SIGNAL(signalReceived()), &t, SLOT(slotReceived()));
	t.start();

    // while(1);	// Need to allow execution of app.exec()!
	app.exec();
}
