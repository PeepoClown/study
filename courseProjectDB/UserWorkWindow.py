import psycopg2
from functools import partial
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QLabel, QPushButton
from PyQt5.QtCore import QSize
from PyQt5.QtGui import QCursor
import ViewTableWindow


class UserWorkWindow(QMainWindow):
    def __init__(self, connectionStr):
        super().__init__()

        self.setMinimumSize(QSize(1200, 900))
        self.connectionStr = connectionStr
        self.viewTableWin = 0

        try:
            connection = psycopg2.connect(self.connectionStr)
            cursor = connection.cursor()
            cursor.execute('SELECT table_name FROM information_schema.tables WHERE table_schema = \
                            \'public\' ORDER BY table_name;')
            self.tableNames = []
            for i in cursor.fetchall():
                if i[0] != 'chiefbygroup':
                    self.tableNames.append(i[0])
        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()

        self.viewTableButtons = []
        for i in range(0, len(self.tableNames)):
            currLabel = QLabel("Table: " + self.tableNames[i], self)
            currLabel.setGeometry(350, 70 + i * 60, 200, 30)
            currLabel.setStyleSheet('''
                font-size: 16px;
            ''')
            self.viewTableButtons.append(QPushButton("View", self))
            self.viewTableButtons[i].setGeometry(700, 70 + i * 60, 150, 30)
            self.viewTableButtons[i].setStyleSheet('''
                font-size: 18px;
                color: #ede8df;
                background-color: #749cdb;
                border-radius: 10px;
                padding: 3px 8px;
            ''')
            self.viewTableButtons[i].clicked.connect(partial(self.viewTableButtonPressed, self.tableNames[i]))
            self.viewTableButtons[i].setCursor(QCursor(QtCore.Qt.PointingHandCursor))

        self.show()

    def viewTableButtonPressed(self, tableName):
        self.viewTableWin = ViewTableWindow.ViewTableWindow(tableName, self.connectionStr)
