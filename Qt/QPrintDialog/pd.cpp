/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12723993/how-to-extend-the-qt-print-dialog/12724933#12724933
 */

#include <QPrinter>
#include <QPrintDialog>
#include <QApplication>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDebug>
#include "pd.h"

MyPrintDialog::MyPrintDialog(QPrinter* p, QWidget* parent) : QPrintDialog(p, parent) {
    qDebug() << "MyPrintDialog";
    QLayout* l = layout();
    if (l == 0) {
        qDebug() << "NO LAYOUT!";
    } else {
        qDebug() << l->metaObject()->className();
    }
    QVBoxLayout* theLayout = dynamic_cast<QVBoxLayout*>(layout());
    if (theLayout) {
        qDebug() << "LAYOUT FOUND!";
        QCheckBox* c = new QCheckBox("Additional checkbox", this);
        theLayout->addWidget(c);
    }
}



int main(int argc, char ** argv) {

    QApplication app( argc, argv );

    QPrinter p;
    MyPrintDialog pd(&p, 0);
    pd.exec();

    return 0;
}
