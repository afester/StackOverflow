/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12307119/qgraphicssceneitems-returns-no-items-for-a-given-rect
 */

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , scene(new QGraphicsScene())
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->installEventFilter(this);
    ui->graphicsView->show();

    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            QPixmap pixmap("desert.png");
            QGraphicsPixmapItem* newItem(scene->addPixmap(pixmap));
            newItem->setPos(x * 25, y * 25);
            newItem->setOpacity(0.01);
            qDebug() << newItem << newItem->isVisible();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Space) {
            QRectF rect(0, 0, 25 * 3, 25 * 3);
            QList<QGraphicsItem*> items(scene->items(rect, Qt::ContainsItemBoundingRect, Qt::AscendingOrder));
            qDebug() << items;
            foreach (QGraphicsItem *item, items) {
                item->setOpacity(1.0);
            }
        }
        return true;
    }
    return QObject::eventFilter(obj, event);
}
