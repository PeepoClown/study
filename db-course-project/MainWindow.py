import psycopg2
from functools import partial
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QLabel, QPushButton
from PyQt5.QtCore import QSize
from PyQt5.QtGui import QPixmap, QCursor
import AuthorizationWindow


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Scheduler")
        self.setMinimumSize(QSize(800, 600))
        self.authWin = 0

        programIconLabel = QLabel(self)
        programNameLabel = QLabel("Scheduler", self)
        programIconLabel.setPixmap(QPixmap("img/mainWindowIcon.png"))
        programIconLabel.setGeometry(50, 30, 32, 32)
        programNameLabel.setStyleSheet('''
            font-size: 20px;
            text-transform: uppercase;
        ''')
        programNameLabel.setGeometry(90, 30, 130, 30)

        self.dbUsers = []
        try:
            self.dbConnection()
        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()

        if len(self.dbUsers) == 0:
            self.close()
        else:
            self.userAccessButtons = []
            for i in range(0, len(self.dbUsers)):
                self.userAccessButtons.append(QPushButton(self.dbUsers[i], self))
                self.userAccessButtons[i].setGeometry(330, 200 + i * 55, 150, 40)
                self.userAccessButtons[i].setStyleSheet('''
                    font-size: 18px;
                    color: #ede8df;
                    background-color: #fca503;
                    border-radius: 12px;
                    padding: 5px 10px;
                ''')
                self.userAccessButtons[i].clicked.connect(partial(self.userAccessButtonPressed, self.dbUsers[i]))
                self.userAccessButtons[i].setCursor(QCursor(QtCore.Qt.PointingHandCursor))

            self.show()

    def dbConnection(self):
        connection = psycopg2.connect("dbname='scheduler' user='dmitriy' password='12345'")
        cursor = connection.cursor()
        cursor.execute('SELECT usename FROM pg_catalog.pg_user;')
        for i in cursor.fetchall():
            self.dbUsers.append(i[0])

    def userAccessButtonPressed(self, username):
        self.authWin = AuthorizationWindow.AuthorizationWindow(self, username)
