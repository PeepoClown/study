import psycopg2
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QTextEdit, QLabel, QLineEdit, QPushButton, QTableView, QComboBox, QMessageBox
from PyQt5.QtCore import QSize, QAbstractTableModel, Qt
from PyQt5.QtGui import QCursor
from ViewTableWindow import TableModel, ViewTableWindow


class TaskWindow(QMainWindow):
    def __init__(self, task, connectionStr):
        super().__init__()

        self.setMinimumSize(QSize(700, 560))
        self.connectionStr = connectionStr
        self.desc = QTextEdit(self)
        self.desc.setGeometry(200, 60, 300, 150)
        self.lEdit = 0
        self.cBox = 0
        self.t6LineEdits = []
        self.t6ComboBoxes = []
        self.win = 0
        self.lEditPair = 0
        self.cBoxWeekDay = 0

        self.data = []
        self.table = 0
        self.tableModel = 0

        self.connection = psycopg2.connect(self.connectionStr)
        self.cursor = self.connection.cursor()

        if task == 'task2a':
            self.desc.setText('Вывод результата многотабличного запроса осуществляющего выборку заполненности студентов по группам, по введенному учебному курсу')
            self.task2a()
        elif task == 'task2b':
            self.desc.setText('Вывод результата запроса осуществляющего выборку в многотабличном представлении о соответсвии заведующих кафедра к группам, которые входят в кафедру, с возможность сортировки по шифру и имени')
            self.task2b()
        elif task == 'task2c':
            self.desc.setText('Вывод результата запроса содержащего коррелированные подзапросы в операторах FROM и WHERE, осуществляющего выборку пребодавателей которые заведуют как и каким-либо факультетом, так и кафедрой')
            self.task2с()
        elif task == 'task2d':
            self.desc.setText('Вывод результата многотабличного запроса осуществляющего выборку преподавателей и дней недели в которые они преподают, и если количество пар равно заданному')
            self.task2d()
        elif task == 'task2e':
            self.desc.setText('Вывод результата запроса осуществляющего выборку групп у которых имеются занятия в заданный день недели')
            self.task2e()
        elif task == 'task6':
            self.desc.setText('Осуществление транзакции на добавление группы, которая будет откатана при совпадении шифра вставляемой группы с шифром уже имеющейся')
            self.task6()
        elif task == 'task8.1':
            self.desc.setText('Отображение самого возрастного преподавателя')
            self.taskOldest()
        elif task == 'task8.2':
            self.desc.setText('Отображение свободный аудиторий в заданную пару и заданный день недели')
            self.taskClassrooms()

        self.desc.setReadOnly(True)
        self.show()

    def task2a(self):
        label = QLabel("Enter course: ", self)
        label.setGeometry(150, 300, 100, 30)
        self.lEdit = QLineEdit(self)
        self.lEdit.setGeometry(300, 300, 130, 30)
        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(450, 300, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.task2aButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def task2aButtonPressed(self):
        val = self.lEdit.text()
        if val == '' or not str(val).isdigit():
            val = '0'
        self.cursor.execute('SELECT * FROM selectGroupsByCourse(%i);' % int(val))
        self.data.append(["Group Cipher", "Cathedra", "Capacity"])
        for i in self.cursor.fetchall():
            self.data.append(i)
        self.table = QTableView()
        self.tableModel = TableModel(self.data)
        self.table.setModel(self.tableModel)
        self.table.resizeColumnsToContents()
        self.setCentralWidget(self.table)

    def task2b(self):
        label = QLabel("Choose sort method: ", self)
        label.setGeometry(150, 300, 100, 30)
        self.cBox = QComboBox(self)
        self.cBox.setGeometry(300, 300, 130, 30)
        self.cBox.addItem('Group')
        self.cBox.addItem('Chief Name')
        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(450, 300, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.task2bButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def task2bButtonPressed(self):
        value = 'g'
        if self.cBox.currentText() == 'Chief Name':
            value = 'c'
        self.cursor.execute('SELECT * FROM getChiefByGroup(\'%s\');' % value)
        self.data.append(["Group Cipher", "Chief Name"])
        for i in self.cursor.fetchall():
            self.data.append(i)
        self.table = QTableView()
        self.tableModel = TableModel(self.data)
        self.table.setModel(self.tableModel)
        self.table.resizeColumnsToContents()
        self.setCentralWidget(self.table)

    def task2с(self):
        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(300, 300, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.task2cButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def task2cButtonPressed(self):
        self.cursor.execute('SELECT * FROM getChiefOfCheifs();')
        self.data.append(["Name", "Age", "Phone", "Email", "Cathedra", "Faculty"])
        for i in self.cursor.fetchall():
            self.data.append(i)
        self.table = QTableView()
        self.tableModel = TableModel(self.data)
        self.table.setModel(self.tableModel)
        self.table.resizeColumnsToContents()
        self.setCentralWidget(self.table)

    def task2d(self):
        label = QLabel("Enter count of pairs: ", self)
        label.setGeometry(150, 300, 150, 30)
        self.lEdit = QLineEdit(self)
        self.lEdit.setGeometry(320, 300, 120, 30)
        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(470, 300, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.task2dButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def task2dButtonPressed(self):
        val = self.lEdit.text()
        if val == '' or not str(val).isdigit():
            val = '1'
        self.cursor.execute('SELECT * FROM getClassesByTeacher(%i);' % int(val))
        self.data.append(["Teacher Name", "Day of Week", "Pairs"])
        for i in self.cursor.fetchall():
            self.data.append(i)
        self.table = QTableView()
        self.tableModel = TableModel(self.data)
        self.table.setModel(self.tableModel)
        self.table.resizeColumnsToContents()
        self.setCentralWidget(self.table)

    def task2e(self):
        label = QLabel("Choose weekday: ", self)
        label.setGeometry(150, 300, 110, 30)
        self.cBox = QComboBox(self)
        self.cBox.setGeometry(300, 300, 130, 30)
        self.cBox.addItem('Понедельник')
        self.cBox.addItem('Вторник')
        self.cBox.addItem('Среда')
        self.cBox.addItem('Четверг')
        self.cBox.addItem('Пятница')
        self.cBox.addItem('Суббота')
        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(450, 300, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.task2eButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def task2eButtonPressed(self):
        self.cursor.execute('SELECT * FROM selectGroupsByWeekDay(\'%s\');' % self.cBox.currentText())
        self.data.append(["Group Cipher"])
        for i in self.cursor.fetchall():
            self.data.append(i)
        self.table = QTableView()
        self.tableModel = TableModel(self.data)
        self.table.setModel(self.tableModel)
        self.table.resizeColumnsToContents()
        self.setCentralWidget(self.table)

    def task6(self):
        labels = []
        label = ['Group cipher: ', 'Course:', 'Students:', 'Cathedra:', 'Specialty:']
        for i in range(0, 3):
            labels.append(QLabel(label[i], self))
            labels[i].setGeometry(150, 220 + i * 50, 120, 30)
            self.t6LineEdits.append(QLineEdit(self))
            self.t6LineEdits[i].setGeometry(300, 220 + i * 50, 150, 30)
        for i in range(0, 2):
            labels.append(QLabel(label[i + 3], self))
            labels[i + 3].setGeometry(150, 220 + (i + 3) * 50, 120, 30)
            self.t6ComboBoxes.append(QComboBox(self))
            self.t6ComboBoxes[i].setGeometry(300, 220 + (i + 3) * 50, 300, 30)
            cBoxData = []
            if i == 0:
                self.cursor.execute('SELECT * FROM public.cathedra;')
                for j in self.cursor.fetchall():
                    cBoxData.append(str(tuple(j)))
                for k in cBoxData:
                    self.t6ComboBoxes[i].addItem(k)
            if i == 1:
                self.cursor.execute('SELECT * FROM public.specialty;')
                for j in self.cursor.fetchall():
                    cBoxData.append(str(tuple(j)))
                for k in cBoxData:
                    self.t6ComboBoxes[i].addItem(k)

        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(300, 480, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.task6ButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

        viewGroupsBtn = QPushButton('View Groups', self)
        viewGroupsBtn.setGeometry(520, 300, 130, 30)
        viewGroupsBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        viewGroupsBtn.clicked.connect(self.viewGroupsPressed)
        viewGroupsBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def getFK(self, text):
        text = str(text).split(',')
        text = (text[0])[1:]
        return text

    def task6ButtonPressed(self):
        if self.t6LineEdits[0].text() == '' or self.t6LineEdits[1].text() == '' or self.t6LineEdits[2].text() == '':
            msgBox = QMessageBox(QMessageBox.Information, "Task 6", "You must to fill all fields",
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
        else:
            fk1 = self.t6ComboBoxes[0].currentText()
            fk2 = self.t6ComboBoxes[1].currentText()

            fk1 = int(self.getFK(fk1))
            fk2 = int(self.getFK(fk2))

            self.cursor.execute('START TRANSACTION; CALL rollbackIfInvalidAdd(\'%s\', %i, %i, %i, %i);'
                                % (self.t6LineEdits[0].text(), int(self.t6LineEdits[1].text()),
                                    int(self.t6LineEdits[2].text()), fk1, fk2))
            self.connection.commit()
            msgBox = QMessageBox(QMessageBox.Information, "Task 6", "Try to add group: " + self.t6LineEdits[0].text(),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
        msgBox.exec()

    def viewGroupsPressed(self):
        self.win = ViewTableWindow('group', self.connectionStr)

    def taskOldest(self):
        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(300, 300, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.taskOldestButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def taskOldestButtonPressed(self):
        self.cursor.execute('SELECT * FROM getOldestTeacher();')
        self.data.append(["Oldest Teacher"])
        for i in self.cursor.fetchall():
            self.data.append(i)
        self.table = QTableView()
        self.tableModel = TableModel(self.data)
        self.table.setModel(self.tableModel)
        self.table.resizeColumnsToContents()
        self.setCentralWidget(self.table)

    def taskClassrooms(self):
        labelPair = QLabel('Pair: ', self)
        labelPair.setGeometry(150, 300, 100, 30)
        self.lEditPair = QLineEdit(self)
        self.lEditPair.setGeometry(300, 300, 150, 30)
        labelWeekDay = QLabel('Day of week: ', self)
        labelWeekDay.setGeometry(150, 360, 100, 30)
        self.cBoxWeekDay = QComboBox(self)
        self.cBoxWeekDay.setGeometry(300, 360, 150, 30)
        self.cBoxWeekDay.addItem('Понедельник')
        self.cBoxWeekDay.addItem('Вторник')
        self.cBoxWeekDay.addItem('Среда')
        self.cBoxWeekDay.addItem('Четверг')
        self.cBoxWeekDay.addItem('Пятница')
        self.cBoxWeekDay.addItem('Суббота')

        submitBtn = QPushButton('Submit', self)
        submitBtn.setGeometry(300, 480, 130, 30)
        submitBtn.setStyleSheet('''
            font-size: 18px;
            color: #ede8df;
            background-color: #749cdb;
            border-radius: 10px;
            padding: 3px 8px;
        ''')
        submitBtn.clicked.connect(self.taskClassroomsButtonPressed)
        submitBtn.setCursor(QCursor(QtCore.Qt.PointingHandCursor))

    def taskClassroomsButtonPressed(self):
        val = self.lEditPair.text()
        if val == '' or not str(val).isdigit():
            val = '0'
        self.cursor.execute('SELECT * FROM showFreeClassrooms(%i, \'%s\');' %
                            (int(val), self.cBoxWeekDay.currentText()))
        self.data.append(["Classroom"])
        for i in self.cursor.fetchall():
            self.data.append(i)
        self.table = QTableView()
        self.tableModel = TableModel(self.data)
        self.table.setModel(self.tableModel)
        self.table.resizeColumnsToContents()
        self.setCentralWidget(self.table)
