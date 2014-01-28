/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13672866/change-signal-slot-connection-in-a-slot-when-called
 */


#ifndef SIGNALSLOTCHANGE_H
#define SIGNALSLOTCHANGE_H

#include <QtGui>

class SignalSlotChange : public QWidget
{
Q_OBJECT


public:
    SignalSlotChange(QWidget *parent = 0);

private slots:
    void callCall();

private:
    void (SignalSlotChange::* delegate) ();

    void firstCall();
    void secondCall();

    QPushButton *button;

};

#endif // SIGNALSLOTCHANGE_H
