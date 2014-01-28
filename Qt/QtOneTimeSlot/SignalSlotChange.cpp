/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13672866/change-signal-slot-connection-in-a-slot-when-called
 */

#include "SignalSlotChange.h"

SignalSlotChange::SignalSlotChange(QWidget *parent) : QWidget(parent)
{
    delegate = &SignalSlotChange::firstCall;

    button = new QPushButton("Messgage", this);
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(callCall()));
    show();
}

void SignalSlotChange::callCall() {
    (this->*delegate) ();
}

void SignalSlotChange::firstCall()
{
    QMessageBox::information(this, "SignalSlotChange", "First call", QMessageBox::Ok, QMessageBox::NoButton);

    // Change the signal-slot connection to secondCall()
    delegate = &SignalSlotChange::secondCall;

//    QObject::disconnect(button, SIGNAL(clicked()), this, SLOT(firstCall()));
//    QObject::connect(button, SIGNAL(clicked()), this, SLOT(secondCall()));
}

void SignalSlotChange::secondCall()
{
    QMessageBox::information(this, "SignalSlotChange", "Second call", QMessageBox::Ok, QMessageBox::NoButton);
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SignalSlotChange ssc;
    return app.exec();
}
