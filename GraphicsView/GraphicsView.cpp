/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/...
 */

#include "ui_GraphicsView.h"

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent) {
}

void GraphicsView::setColor(const QColor& color) {
    viewColor = color;
}

GraphicsItem::GraphicsItem ( qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent) :
        QGraphicsRectItem(x, y, width, height, parent) {
}

void GraphicsItem::paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    painter->setPen(Qt::red);	// !! How to get the color of the view which is painting this item??
    painter->drawRect(rect());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene()) {
    ui->setupUi(this);

    // set up a graphics scene
    GraphicsItem* item = new GraphicsItem(10, 10, 50, 50);
    scene->addItem(item);

    ui->blueView->setScene(scene);
    ui->blueView->setColor(Qt::blue);	// A blue view
    ui->blueView->show();

    ui->redView->setScene(scene);
    ui->redView->setColor(Qt::red);	// a red view
    ui->redView->show();
}

MainWindow::~MainWindow() {
    delete ui;
    delete scene;
}
