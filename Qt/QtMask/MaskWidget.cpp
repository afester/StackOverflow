/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12571566/qt-draw-triangle-image
 */

#include <QDebug>
#include <QPainter>

#include "MaskWidget.h"

MaskWidget::MaskWidget(QWidget* parent) : QWidget(parent) {
   img = QImage("Sample.jpg");
   mask = QImage("Mask.png");
   QPainter imgPainter(&img); 
   imgPainter.drawImage(0, 0, mask);
}

void MaskWidget::paintEvent ( QPaintEvent * event ) {
   QPainter painter(this);
   painter.drawImage(10, 10, img);
}
