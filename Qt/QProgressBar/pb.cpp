/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12407584/qt-progressbar-centering
 */

#include <QApplication>
#include <QProgressBar>
#include <QTimer>
#include <QDesktopWidget>
#include <QDebug>
#include "pb.h"

PbAdvancer::PbAdvancer(QProgressBar* pb) : progressBar(pb), step(1) {

}


void PbAdvancer::advance() {
    progressBar->setValue(step++);
}


int main(int argc, char ** argv) {

    QApplication app( argc, argv );

    QProgressBar vBar;
    vBar.setWindowFlags(Qt::FramelessWindowHint);
    vBar.setRange(0,9);
    vBar.setAlignment(Qt::AlignCenter);
    qDebug() << QApplication::desktop()->width() << " x " << QApplication::desktop()->height();

    vBar.show();
    vBar.move((QApplication::desktop()->width()- vBar.width() ) / 2,
              (QApplication::desktop()->height()- vBar.height() ) / 2);

    qDebug() << vBar.width() << " x " << vBar.height();

    PbAdvancer pbAdvancer(&vBar);
    QTimer t;
    t.setInterval(1000);
    t.start();
    QObject::connect(&t, SIGNAL(timeout()), &pbAdvancer, SLOT(advance()));

    app.exec();
    return 0;
}
