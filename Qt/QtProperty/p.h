/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12742539/q-property-and-has-no-member-error
 */

#ifndef P_H
#define P_H

#include <QObject>

class P : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int Prop READ getProp WRITE setProp)
  public:
    explicit P(QObject *parent = 0);

    int getProp() const;
    void setProp(int nP);
  private:
    int m_p;
};

#endif // P_H
