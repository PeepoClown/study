import psycopg2
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QLabel, QPushButton, QLineEdit
from PyQt5.QtGui import QCursor
import AdminWorkWindow
import UserWorkWindow


class AuthorizationWindow(QMainWindow):
    def __init__(self, parent, username):
        super().__init__()

        self.setWindowTitle("Authorization")
        geo = self.geometry()
        geo.moveCenter(parent.geometry().center())
        self.setGeometry(geo)
        self.username = username
        self.parentWindow = parent
        self.workWin = 0
        self.isSuperUser = False

        loginLabel = QLabel("Login as " + username, self)
        loginLabel.setGeometry(250, 150, 200, 30)
        loginLabel.setStyleSheet('''
            font-size: 20px;
        ''')
        passwdLabel = QLabel("type password: ", self)
        passwdLabel.setGeometry(200, 200, 130, 30)
        passwdLabel.setStyleSheet('''
            font-size: 16px;
        ''')
        self.passwdEdit = QLineEdit(self)
        self.passwdEdit.setGeometry(330, 200, 150, 30)
        self.passwdEdit.setStyleSheet('''
            font-size: 16px;
        ''')
        self.submitButton = QPushButton("Submit", self)
        self.submitButton.setGeometry(280, 260, 150, 40)
        self.submitButton.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #e3827b;
            border-radius: 12px;
            padding: 5px 10px;
        ''')
        self.submitButton.clicked.connect(self.submitButtonPressed)
        self.submitButton.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

        self.show()

    def submitButtonPressed(self):
        try:
            connectionStr = "dbname='scheduler' user='%s' password='%s'" % (self.username, self.passwdEdit.text())
            connection = psycopg2.connect(connectionStr)
            cursor = connection.cursor()
            msgBox = QMessageBox(QMessageBox.Information, "Login", "Login on user: " + self.username,
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()
            self.close()
            self.parentWindow.close()

            cursor.execute('SELECT (usename, usesuper) FROM pg_catalog.pg_user;')
            for i in cursor.fetchall():
                values = i[0].replace('(', '').replace(')', '').split(',')
                if values[0] == self.username and values[1] == 't':
                    self.isSuperUser = True

            if self.isSuperUser:
                self.workWin = AdminWorkWindow.AdminWorkWindow(connectionStr)
            else:
                self.workWin = UserWorkWindow.UserWorkWindow(connectionStr)

        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()
