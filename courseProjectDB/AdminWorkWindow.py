import psycopg2
from functools import partial
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QLabel, QPushButton
from PyQt5.QtCore import QSize
from PyQt5.QtGui import QCursor
import AddTableWindow
import DeleteTableWindow
import ChangeTableWindow
import ViewTableWindow
import TaskViewWindow


class AdminWorkWindow(QMainWindow):
    def __init__(self, connectionStr):
        super().__init__()

        self.setMinimumSize(QSize(1600, 900))
        self.connectionStr = connectionStr
        self.addTableWin = 0
        self.deleteTableWin = 0
        self.changeTableWin = 0
        self.viewTableWin = 0
        self.taskWindow = 0

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

        self.addTableButtons = []
        self.changeTableButtons = []
        self.deleteTableButtons = []
        self.viewTableButtons = []
        for i in range(0, len(self.tableNames)):
            currLabel = QLabel("Table: " + self.tableNames[i], self)
            currLabel.setGeometry(300, 50 + i * 70, 200, 30)
            currLabel.setStyleSheet('''
                font-size: 16px;
            ''')

            if self.tableNames[i] != 'teacherprofilelogs':
                self.addTableButtons.append(QPushButton("Add", self))
                self.addTableButtons[i].setGeometry(520, 50 + i * 70, 150, 30)
                self.addTableButtons[i].setStyleSheet('''
                    font-size: 18px;
                    color: #ede8df;
                    background-color: #749cdb;
                    border-radius: 10px;
                    padding: 3px 8px;
                ''')
                self.addTableButtons[i].clicked.connect(partial(self.addTableButtonPressed, self.tableNames[i]))
                self.addTableButtons[i].setCursor(QCursor(QtCore.Qt.PointingHandCursor))

                self.changeTableButtons.append(QPushButton("Change", self))
                self.changeTableButtons[i].setGeometry(720, 50 + i * 70, 150, 30)
                self.changeTableButtons[i].setStyleSheet('''
                    font-size: 18px;
                    color: #ede8df;
                    background-color: #749cdb;
                    border-radius: 10px;
                    padding: 3px 8px;
                ''')
                self.changeTableButtons[i].clicked.connect(partial(self.changeTableButtonPressed, self.tableNames[i]))
                self.changeTableButtons[i].setCursor(QCursor(QtCore.Qt.PointingHandCursor))

                self.deleteTableButtons.append(QPushButton("Delete", self))
                self.deleteTableButtons[i].setGeometry(920, 50 + i * 70, 150, 30)
                self.deleteTableButtons[i].setStyleSheet('''
                                font-size: 18px;
                                color: #ede8df;
                                background-color: #749cdb;
                                border-radius: 10px;
                                padding: 3px 8px;
                            ''')
                self.deleteTableButtons[i].clicked.connect(partial(self.deleteTableButtonPressed, self.tableNames[i]))
                self.deleteTableButtons[i].setCursor(QCursor(QtCore.Qt.PointingHandCursor))

            self.viewTableButtons.append(QPushButton("View", self))
            self.viewTableButtons[i].setGeometry(1120, 50 + i * 70, 150, 30)
            self.viewTableButtons[i].setStyleSheet('''
                font-size: 18px;
                color: #ede8df;
                background-color: #749cdb;
                border-radius: 10px;
                padding: 3px 8px;
            ''')
            self.viewTableButtons[i].clicked.connect(partial(self.viewTableButtonPressed, self.tableNames[i]))
            self.viewTableButtons[i].setCursor(QCursor(QtCore.Qt.PointingHandCursor))

        self.taskButton = QPushButton("Task", self)
        self.taskButton.setGeometry(1400, 400, 150, 30)
        self.taskButton.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        self.taskButton.clicked.connect(self.taskButtonPressed)
        self.taskButton.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

        self.show()

    def addTableButtonPressed(self, tableName):
        self.addTableWin = AddTableWindow.AddTableWindow(tableName, self.connectionStr)

    def changeTableButtonPressed(self, tableName):
        self.changeTableWin = ChangeTableWindow.ChangeTableWindow(tableName, self.connectionStr)

    def deleteTableButtonPressed(self, tableName):
        self.deleteTableWin = DeleteTableWindow.DeleteTableWindow(tableName, self.connectionStr)

    def viewTableButtonPressed(self, tableName):
        self.viewTableWin = ViewTableWindow.ViewTableWindow(tableName, self.connectionStr)

    def taskButtonPressed(self):
        self.taskWindow = TaskViewWindow.TaskViewWindow(self.connectionStr)