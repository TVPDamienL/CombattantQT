from PyQt5.QtCore import QAbstractItemModel
from PyQt5.QtCore import QModelIndex
from PyQt5.QtCore import QVariant
from PyQt5.QtCore import Qt

import Combattant
import DataWrapper

class cModel(QAbstractItemModel):
    def __init__(self):
        super(cModel,self).__init__()
        self.mRootIndex = 0
        self.BuildData()
    # --------------------------------


    def index(self, iRow, iColumn, iParent):
        if iParent.isValid() == True and iParent.column() != 0:
            return QModelIndex()

        parentNode = self.ExtractItem( iParent )
        child = parentNode.ChildAtRow( iRow )
        if child != 0:
            return  self.createIndex( iRow, iColumn, child )

        return  QModelIndex()
    # --------------------------------


    def parent(self, iIndex):
        if not iIndex.isValid():
            return  QModelIndex()

        node = self.ExtractItem( iIndex )
        parentNode = node.mParent
        if parentNode == self.mRootIndex:
            return  QModelIndex()

        return  self.createIndex( parentNode.IndexInParent(), 0, parentNode )
    # --------------------------------


    def rowCount(self, iIndex):
        item = self.ExtractItem( iIndex )
        return  item.ChildrenCount()
    # --------------------------------


    def columnCount(self, iIndex):
        return  1
    # --------------------------------


    def data(self, iIndex, iRole):
        if not iIndex.isValid():
            return  QVariant()

        item = self.ExtractItem( iIndex )
        if item == 0:
            return  QVariant()

        if iRole == Qt.DisplayRole or iRole == Qt.EditRole:
            return  item.Data()

        return  QVariant()
    # --------------------------------

    def setData( self, iIndex, iData, iRole ):
        if iRole != Qt.EditRole:
            return  False

        item = self.ExtractItem( iIndex )
        result = item.SetData( iData )
        if result == True:
            if type(item) is DataWrapper.cCombattantNameNode:
                self._UpdateCombattantNameNode( item )
            else:
                self.dataChanged.emit(iIndex, iIndex)

        return  result
    # --------------------------------


    def flags( self, iIndex ):
        if not iIndex.isValid():
            return  0

        return  super(cModel, self).flags(iIndex) | Qt.ItemIsEditable
    # --------------------------------


    def headerData( self, iSection, iOrientation, iRole):
        if iOrientation == Qt.Horizontal or iRole == Qt.DisplayRole:
            return  "Ouioui"
    # --------------------------------


    def ExtractItem(self,iIndex):
        if not iIndex.isValid():
            return  self.mRootIndex

        return  iIndex.internalPointer()
    # --------------------------------


    def BuildData(self):
        self.mRootIndex = DataWrapper.cDataItem(0)

        for i in range(10):
            comb = Combattant.cCombattant("Combattant_" + str(i) )
            combNode = DataWrapper.cCombattantNameNode( self.mRootIndex, comb )
            DataWrapper.cCombattantNameNode( combNode, comb )
            DataWrapper.cCombattantWeaponNode( combNode, comb )
            DataWrapper.cCombattantShieldNode( combNode, comb )
    # --------------------------------


    def _UpdateCombattantNameNode(self, iItem):
        topNode = iItem
        if type(iItem.mParent) is DataWrapper.cCombattantNameNode:
            topNode = iItem.mParent

        self.dataChanged.emit( self.GetIndexFromItem(topNode), self.GetIndexFromItem(topNode) )
        self.dataChanged.emit( self.GetIndexFromItem(topNode.mChildren[0]), self.GetIndexFromItem(topNode.mChildren[0]) )
    # --------------------------------


    def  GetIndexFromItem(self, iItem):
        return  self.createIndex( iItem.IndexInParent(), 0, iItem )
    # --------------------------------






