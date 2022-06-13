import psycopg2
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QLabel, QComboBox, QPushButton
from PyQt5.QtCore import QSize
from PyQt5.QtGui import QCursor


class DeleteTableWindow(QMainWindow):
    def __init__(self, tableName, connectionStr):
        super().__init__()

        self.setMinimumSize(QSize(800, 300))
        self.tableName = tableName
        self.connectionStr = connectionStr
        self.label = QLabel("Delete record: ", self)
        self.label.setGeometry(50, 120, 120, 30)
        self.comboBox = QComboBox(self)
        self.comboBox.setGeometry(200, 120, 500, 30)
        self.submitButton = QPushButton("Submit", self)
        self.submitButton.setGeometry(350, 200, 150, 40)
        self.submitButton.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #e3827b;
            border-radius: 12px;
            padding: 5px 10px;
        ''')
        self.submitButton.clicked.connect(self.submitButtonPressed)
        self.submitButton.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

        try:
            connection = psycopg2.connect(self.connectionStr)
            cursor = connection.cursor()

            cursor.execute('SELECT * FROM public.%s;' % self.tableName)
            for i in cursor.fetchall():
                self.comboBox.addItem(str(tuple(i)))

        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()

        self.show()

    def submitButtonPressed(self):
        msgBox = 0
        try:
            connection = psycopg2.connect(self.connectionStr)
            cursor = connection.cursor()

            procedureName = str(self.tableName).lower() + "Delete"
            tmp = self.comboBox.currentText()
            tmp = tmp.split(',')
            tmp = (tmp[0])[1:]
            argsStr = "(" + tmp + ")"

            cursor.execute('CALL %s%s;' % (procedureName, argsStr))
            connection.commit()

            msgBox = QMessageBox(QMessageBox.Information, "Remove", "Delte record: " + argsStr,
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            self.close()
        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
        msgBox.exec()
