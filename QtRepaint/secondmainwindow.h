/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 */

#ifndef __SECOND_MAIN_WINDOW_H__
#define __SECOND_MAIN_WINDOW_H__

#include <QFrame>

class SecondMainWindow : public QFrame {
	Q_OBJECT

public:
	SecondMainWindow(QWidget* parent);
	~SecondMainWindow();

protected:
	virtual void paintEvent(QPaintEvent *e);
};

#endif
