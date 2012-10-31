/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13116863/qt-show-modal-dialog-ui-on-menu-item-click/13117278#13117278
 */

#include <QApplication>
#include <QDialog>
#include "ui_dialog.h"

int main(int argc, char ** argv) {
	QApplication app( argc, argv );

	QDialog* about = new QDialog(0,0);
	Ui_Dialog myUi;
	myUi.setupUi(about);
	about->exec();

    return 0;
}
