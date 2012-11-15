/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13357667/qt-thread-signal-slot-issue
 */

#include <QThread>
#include <QMutex>

class ThreadCheck : public QThread {
	Q_OBJECT

signals:
	void signalReceived();

protected:
	void run();

public slots:
	void slotReceived();
	
private:
	QMutex mutex;
};
