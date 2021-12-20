import psycopg2
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QLabel, QLineEdit, QPushButton, QComboBox
from PyQt5.QtCore import QSize
from PyQt5.QtGui import QCursor


class AddTableWindow(QMainWindow):
    def __init__(self, tableName, connectionStr):
        super().__init__()

        self.setMinimumSize(QSize(1200, 500))
        self.tableName = tableName
        self.connectionStr = connectionStr

        self.columns = []
        self.types = []
        self.labels = []
        self.lineEdits = []
        self.comboBoxes = []
        self.submitButton = 0

        try:
            connection = psycopg2.connect(self.connectionStr)
            cursor = connection.cursor()

            cursor.execute('SELECT column_name, data_type FROM information_schema.columns WHERE \
                                       table_name = \'%s\';' % self.tableName)
            for i in cursor.fetchall():
                if str(i[0]) != "id":
                    self.columns.append(i[0])
                    self.types.append(i[1])

            heightCoeff = 0
            widthCoeff = 0
            lineEditsCounter = 0
            comboBoxesCounter = 0

            for i in range(0, len(self.columns)):
                self.labels.append(QLabel("%s: " % self.columns[i], self))
                labelW = 50 + widthCoeff * 400
                self.labels[i].setGeometry(labelW, 80 + heightCoeff * 80, 100, 30)
                if str(self.columns[i]).find("_id") == -1:
                    self.lineEdits.append(QLineEdit(self))
                    self.lineEdits[lineEditsCounter].setGeometry(labelW + 120, 80 + heightCoeff * 80, 200, 30)
                    lineEditsCounter += 1
                else:
                    data = []
                    fkTableName = str(self.columns[i]).split('_')[0]
                    if fkTableName == "chief":
                        fkTableName = "teacher"

                    cursor.execute('SELECT * FROM public.%s;' % fkTableName)
                    for j in cursor.fetchall():
                        data.append(str(tuple(j)))

                    self.comboBoxes.append(QComboBox(self))
                    for k in data:
                        self.comboBoxes[comboBoxesCounter].addItem(k)
                    self.comboBoxes[comboBoxesCounter].setGeometry(labelW + 120, 80 + heightCoeff * 80, 200, 30)
                    comboBoxesCounter += 1
                widthCoeff += 1
                if (i + 1) % 3 == 0:
                    heightCoeff += 1
                    widthCoeff = 0

            self.submitButton = QPushButton("Submit", self)
            self.submitButton.setGeometry(550, 200 + heightCoeff * 100, 150, 40)
            self.submitButton.setStyleSheet('''
                font-size: 18px;
                color: #ede8df;
                background-color: #e3827b;
                border-radius: 12px;
                padding: 5px 10px;
            ''')
            self.submitButton.clicked.connect(self.submitButtonPressed)
            self.submitButton.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()

        self.show()

    def getFK(self, text):
        text = str(text).split(',')
        text = (text[0])[1:]
        return text

    def submitButtonPressed(self):
        msgBox = 0
        if self.tableName == "schedule":
            self.addToSchedule()
        else:
            try:
                connection = psycopg2.connect(self.connectionStr)
                cursor = connection.cursor()

                procedureName = str(self.tableName).lower() + "Add"
                argsStr = "("
                for i in range(0, len(self.lineEdits)):
                    if self.types[i] == 'integer':
                        argsStr += self.lineEdits[i].text() + ", "
                    else:
                        argsStr += '\'' + self.lineEdits[i].text() + '\'' + ", "
                for i in self.comboBoxes:
                    argsStr += self.getFK(i.currentText()) + ", "
                argsStr = argsStr[:-2]
                argsStr += ")"

                cursor.execute('CALL %s%s;' % (procedureName, argsStr))
                connection.commit()

                msgBox = QMessageBox(QMessageBox.Information, "Add", "Insert record: " + argsStr,
                                     QMessageBox.Ok | QMessageBox.Cancel, self)
                self.close()
            except Exception as exception:
                msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                     QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()

    def addToSchedule(self):
        try:
            connection = psycopg2.connect(self.connectionStr)
            cursor = connection.cursor()

            procedureName = "scheduleAdd"
            argsStr = "(" + self.getFK(self.comboBoxes[0].currentText()) + ", " + \
                    self.getFK(self.comboBoxes[1].currentText()) + ", " + \
                    self.getFK(self.comboBoxes[2].currentText()) + ", " + \
                    '\'' + self.lineEdits[0].text() + '\'' + ", " + \
                    self.getFK(self.comboBoxes[3].currentText()) + ", " + \
                    self.getFK(self.comboBoxes[4].currentText()) + ", " + \
                    '\'' + self.lineEdits[1].text() + '\'' + ")"

            cursor.execute('CALL %s%s;' % (procedureName, argsStr))
            connection.commit()

            msgBox = QMessageBox(QMessageBox.Information, "Add", "Insert record: " + argsStr,
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            self.close()
        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
        msgBox.exec()
