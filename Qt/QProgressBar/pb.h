/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12407584/qt-progressbar-centering
 */

#include <QObject>

class QProgressBar;

class PbAdvancer : public QObject {
    Q_OBJECT

    QProgressBar* progressBar;
    int step;

public:
    PbAdvancer(QProgressBar* pb);

public slots:
    virtual void advance();
};
