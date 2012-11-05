/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12594729/how-to-keep-buttons-close-to-each-other-horizontally-in-qt-widget
 */


#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QApplication>
#include <QMainWindow>

int main(int argc, char ** argv) {
    QApplication app( argc, argv );
    QMainWindow win;

    QWidget* centralWidget = new QWidget(&win);
    QPushButton* refresh = new QPushButton("Start R");
    QPushButton* zoomIn = new QPushButton("Zoom in");
    QPushButton* zoomOut = new QPushButton("Zoom out");
    QPushButton* panLeft = new QPushButton("Left");
    QPushButton* panRight = new QPushButton("Right");
    QPushButton* panTop = new QPushButton("Top");
    QPushButton* panBottom = new QPushButton("Bottom");
    QPushButton* findInfo = new QPushButton("Find Info");
    QTextEdit* textEdit = new QTextEdit("Vehicle Info. Will be shown here.");

///////////////////////////// 
    QGridLayout *layout = new QGridLayout ();
    centralWidget->setLayout (layout);
    layout->addWidget (refresh, 0, 0);
    layout->addWidget (zoomIn, 1, 0);
    layout->addWidget (zoomOut, 1, 1);
    layout->addWidget (panLeft, 2, 0);
    layout->addWidget (panRight, 2, 1);
    layout->addWidget (panTop, 3, 0);
    layout->addWidget (panBottom, 3, 1);
    layout->addWidget (findInfo, 4, 0);
    layout->addWidget (textEdit, 5, 0);

    win.setCentralWidget (centralWidget);
///////////////////////////// 

    win.show(); 
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
