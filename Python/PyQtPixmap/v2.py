#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui

class Test(QtGui.QWidget):

    def __init__(self):
        super(Test, self).__init__()

        self.initUI()

    def initUI(self):      
        layout = QtGui.QVBoxLayout()
        pixmap = QtGui.QPixmap("test.png")

        lbl = QtGui.QLabel(self)
        lbl.setPixmap(pixmap)

        layout.addWidget(lbl)
        self.setLayout(layout)

        self.move(300, 200)
        self.setWindowTitle('test')
        self.show()        

app = QtGui.QApplication(sys.argv)
ex = Test()
sys.exit(app.exec_())
