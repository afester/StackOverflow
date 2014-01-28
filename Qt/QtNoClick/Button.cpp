/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12637440/how-to-remove-click-effect-from-a-qpushbutton
 */

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QApplication>
#include <QMainWindow>

/*
IGNORE: 6  QEvent::KeyPress
IGNORE: 7  QEvent::KeyRelease	
IGNORE: 8  QEvent::FocusIn	
IGNORE: 9  QEvent::FocusOut	
IGNORE: 10 QEvent::Enter	
IGNORE: 11 QEvent::Leave	
IGNORE: 13 QEvent::Move	
IGNORE: 14 QEvent::Resize	
IGNORE: 17 QEvent::Show	
IGNORE: 21 QEvent::ParentChange	
IGNORE: 24 QEvent::WindowActivate	
IGNORE: 25 QEvent::WindowDeactivate	
IGNORE: 26 QEvent::ShowToParent	
IGNORE: 51 QEvent::ShortcutOverride	
IGNORE: 67
IGNORE: 68 QEvent::ChildAdded	
IGNORE: 69 QEvent::ChildPolished	
IGNORE: 70 QEvent::ChildInserted	
IGNORE: 71 QEvent::ChildRemoved	
IGNORE: 74 QEvent::PolishRequest	QEvent::ToolTipChange	
IGNORE: 75 QEvent::Polish	
IGNORE: 184 QEvent::ToolTipChange	
*/

class PushButton : public QPushButton {
public:
    PushButton();

    bool event ( QEvent * e );
};

PushButton::PushButton() {
}

bool PushButton::event ( QEvent * e ) {
// return QPushButton::event(e);

   if (e->type() == QEvent::Paint ||
       e->type() == QEvent::ToolTip) {
      return QPushButton::event(e);
   }
qDebug() << "IGNORE:" << e->type();
   return true;
}


int main(int argc, char ** argv) {
    QApplication app( argc, argv );
    QMainWindow win;

    QWidget* centralWidget = new QWidget(&win);
    QPushButton* refresh = new PushButton();
    refresh->setText("Text");
    refresh->setIcon(QIcon("check.png"));
    refresh->setToolTip("Tooltip");

QLabel* lbl = new QLabel();
lbl->setTextFormat(Qt::RichText);
lbl->setText("<img src=\"myimage.png\">Hello!");

///////////////////////////// 
    QGridLayout *layout = new QGridLayout ();
    centralWidget->setLayout (layout);
    layout->addWidget (refresh, 0, 0);
    layout->addWidget (lbl, 0, 1);
    win.setCentralWidget (centralWidget);
///////////////////////////// 

    win.show(); 
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
