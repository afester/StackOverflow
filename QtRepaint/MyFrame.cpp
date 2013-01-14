/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13979186/how-do-i-draw-on-a-frame-in-qt/13980245
 */

#include <QPainter>

#include "MyFrame.h"

MyFrame::MyFrame(QWidget *parent) :
    QFrame(parent) {
}

MyFrame::~MyFrame() {
}

void MyFrame::paintEvent(QPaintEvent *e) {
    QPainter paint(this);
    paint.setPen(Qt::red);
    paint.drawEllipse(10,10,100,100);
    paint.end();

    QFrame::paintEvent(e);
}
