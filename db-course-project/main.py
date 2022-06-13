import sys
from PyQt5 import QtWidgets
import MainWindow

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    mainWin = MainWindow.MainWindow()
    sys.exit(app.exec())
