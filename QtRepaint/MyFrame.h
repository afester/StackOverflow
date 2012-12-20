/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 */

#ifndef __MY_FRAME_H__
#define __MY_FRAME_H__

#include <QFrame>

class MyFrame : public QFrame {
	Q_OBJECT

public:
	MyFrame(QWidget* parent);
	~MyFrame();

protected:
	virtual void paintEvent(QPaintEvent *e);
};

#endif
