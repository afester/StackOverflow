/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12606365/how-to-match-tab-length-to-a-number-of-spaces-in-qt
 */

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    ui->textEdit->setFontFamily("Courier New");
    QFontMetrics fm(ui->textEdit->currentFont());
    int spaceWidth = fm.width(" ");
    int tabStop = spaceWidth * 4;
    ui->textEdit->setTabStopWidth(tabStop + 1);
    ui->textEdit->setText("\tAfter one tab\n"
                          "    After 4 spaces\n"
                          "\t\tAfter two tabs\n"
                          "        After 8 spaces\n"
                          "\t\t\t\t\t\tAfter six tabs\n"
                          "                        After 24 spaces\n"
                          "\t\t\t\t\t\t\t\t\t\t\t\tAfter 12 tabs\n"
                          "                                                After 48 spaces\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}
