from functools import partial
from PyQt5 import QtCore
from PyQt5.QtWidgets import QMainWindow, QPushButton
from PyQt5.QtCore import QSize
from PyQt5.QtGui import QCursor
import TaskWindow


class TaskViewWindow(QMainWindow):
	def __init__(self, connectionStr):
		super().__init__()

		self.setMinimumSize(QSize(800, 600))
		self.connectionStr = connectionStr
		self.taskWin = 0

		self.btnNames = ["task2a", "task2b", "task2c", "task2d", "task2e", "task6", "task8.1", "task8.2"]
		self.taskButtons = []
		widthCoeff = 0
		heightCoeff = 0
		for i in range(0, len(self.btnNames)):
			self.taskButtons.append(QPushButton(self.btnNames[i], self))
			self.taskButtons[i].setGeometry(230 + widthCoeff * 200, 150 + heightCoeff * 60, 150, 30)
			self.taskButtons[i].setStyleSheet('''
				font-size: 18px;
				color: #ede8df;
				background-color: #749cdb;
				border-radius: 10px;
				padding: 3px 8px;
			''')
			self.taskButtons[i].clicked.connect(partial(self.taskButtonPressed, self.btnNames[i]))
			self.taskButtons[i].setCursor(QCursor(QtCore.Qt.PointingHandCursor))
			heightCoeff += 1
			if (i + 1) % 4 == 0:
				widthCoeff += 1
				heightCoeff = 0

		self.show()

	def taskButtonPressed(self, btnName):
		self.taskWin = TaskWindow.TaskWindow(btnName, self.connectionStr)
