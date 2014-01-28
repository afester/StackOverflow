/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12307119/qgraphicssceneitems-returns-no-items-for-a-given-rect
 */

#include <QMainWindow>
#include <QWidget>
#include <QEvent>
#include <QGraphicsScene>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:

	MainWindow(QWidget* parent);
	~MainWindow();
	bool eventFilter(QObject *obj, QEvent *event);

        Ui_MainWindow* ui;
        QGraphicsScene* scene;
};
