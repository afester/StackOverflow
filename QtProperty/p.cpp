/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12742539/q-property-and-has-no-member-error
 */

#include <QApplication>
#include <QDebug>

#include "p.h"

P::P(QObject *parent) :
  QObject(parent)
{
}

int P::getProp() const
{
  return m_p;
}

void P::setProp(int nP)
{
  m_p = nP;
}


int main(int argc, char ** argv) {
    QApplication app( argc, argv );

    P p;
    p.setProperty("Prop", 42);
    qDebug() << p.property("Prop");

    QObject *object = &p;
    object->setProperty("Prop", 42);
    qDebug() << object->property("Prop");
}

