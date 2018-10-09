import importlib

from PyQt5.QtWidgets import QApplication

import MainWindow

app = QApplication([])

mainWindow = MainWindow.cMainWindow()
mainWindow.show()

app.exec_()

