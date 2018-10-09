import Model


from PyQt5.QtCore       import Qt
from PyQt5.QtCore       import QByteArray
from PyQt5.QtWidgets    import QMainWindow
from PyQt5.QtWidgets    import QDataWidgetMapper
from PyQt5.uic          import loadUi


class cMainWindow(QMainWindow):
    def __init__(self):
        super(cMainWindow, self).__init__()
        loadUi('MainWindow.ui', self)
        self.mModel = Model.cModel()
        self.mainList.setModel( self.mModel )
        self.treeView.setModel( self.mModel )

        self.mMapper = QDataWidgetMapper()
        self.mMapper.setModel( self.mModel )
        self.mMapper.setOrientation( Qt.Vertical )
        self.mMapper.addMapping( self.nameLineEdit, 0)
        self.mMapper.addMapping( self.weaponComboBox, 0, b"currentText" )
        self.mMapper.addMapping( self.shiledSpinBox, 1)

        self.mainList.selectionModel().currentChanged.connect( self.CombattantSelected )


    def CombattantSelected(self, iIndex):
        self.mMapper.setRootIndex( iIndex )
        self.mMapper.toFirst()