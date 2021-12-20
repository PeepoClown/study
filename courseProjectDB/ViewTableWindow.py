import psycopg2
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QTableView
from PyQt5.QtCore import QSize, QAbstractTableModel, Qt


class TableModel(QAbstractTableModel):
    def __init__(self, data):
        super(TableModel, self).__init__()
        self.data = data

    def data(self, index, role):
        if role == Qt.DisplayRole:
            return self.data[index.row()][index.column()]

    def rowCount(self, index):
        return len(self.data)

    def columnCount(self, index):
        return len(self.data[0])


class ViewTableWindow(QMainWindow):
    def __init__(self, tableName, connectionStr):
        super().__init__()

        self.setMinimumSize(QSize(1200, 675))
        self.tableName = tableName
        self.connectionStr = connectionStr
        self.header = []
        self.data = []

        try:
            connection = psycopg2.connect(self.connectionStr)
            cursor = connection.cursor()

            cursor.execute('SELECT column_name FROM information_schema.columns WHERE \
                           table_name = \'%s\';' % self.tableName)
            for i in cursor.fetchall():
                self.header.append(i[0])
            self.data.append(self.header)

            cursor.execute('SELECT * FROM public.%s;' % tableName)
            for i in cursor.fetchall():
                currList = list(i)
                newList = []
                for j in currList:
                    newList.append(str(j))
                self.data.append(tuple(newList))

            self.table = QTableView()
            self.tableModel = TableModel(self.data)
            self.table.setModel(self.tableModel)
            self.table.resizeColumnsToContents()
            self.setCentralWidget(self.table)

        except Exception as exception:
            msgBox = QMessageBox(QMessageBox.Critical, "Error", "Error: " + str(exception),
                                 QMessageBox.Ok | QMessageBox.Cancel, self)
            msgBox.exec()

        self.show()
