/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13121922/qt-or-general-c-how-to-get-or-detect-the-host-of-the-a-href-file-html-in/13122158#comment17862382_13122158
 */

#include <QApplication>
#include <QUrl>
#include <QDebug>

int main(int argc, char ** argv) {

    QApplication app( argc, argv );

    QString s("/About-us/");
    QString base("http://qt.digia.com");
    QString urlForReq;
    QUrl baseUrl(base);          // this was missing in the code from the question
    if(!s.startsWith("http:")) {       
        QString uu = QUrl(s).toString();
        QString rurl = baseUrl.resolved(QUrl(s)).toString();
        urlForReq = rurl;
    }
    qDebug() << "urlForReq:" << urlForReq;

    return 0;
}
