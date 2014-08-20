#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui

class Test(QtGui.QWidget):

    def __init__(self):
        super(Test, self).__init__()

        self.initUI()

    def initUI(self):      
        pixmap = QtGui.QPixmap("test.png")

        lbl = QtGui.QLabel(self)
        lbl.setPixmap(pixmap)

        self.move(300, 200)
        self.setWindowTitle('Test')
        self.show()        

app = QtGui.QApplication(sys.argv)
ex = Test()
sys.exit(app.exec_())
