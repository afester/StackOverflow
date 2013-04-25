#!/usr/bin/env python2

# This work is licensed under the Creative Commons Attribution 3.0 Unported 
# License. To view a copy of this license, visit 
# http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
# Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.

# StackOverflow reference:
# http://stackoverflow.com/questions/13926807/pyside-qt-signal-not-reaching-my-slot

import sys
from PySide import QtGui, QtCore

class MySoc(object):
    def __init__(self, qte):
        qte.textChanged.connect(self.soc)

    def soc(self):
        print("got signal")

class MainWid(QtGui.QWidget):
    def __init__(self, parent=None):
        super(MainWid, self).__init__(parent)
        self.initgui()

    def initgui(self):
        lay = QtGui.QVBoxLayout()
        txt = QtGui.QTextEdit(self)
        self.soc = MySoc(txt)

        lay.addWidget(txt)
        self.setLayout(lay)
        self.show()

def main():
    app = QtGui.QApplication(sys.argv)
    wid = MainWid()
    sys.exit(app.exec_())

if __name__=="__main__":
    main()
