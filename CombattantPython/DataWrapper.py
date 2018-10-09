import Combattant

class cDataItem:
    def __init__(self, iParent):
        self.mParent = iParent
        if iParent != 0:
            self.mParent.AddChild(self)

        self.mChildren = []
    # --------------------------------

                        # Children =================================
    def  AddChild(self, iChild):
        self.mChildren.append( iChild )
    # --------------------------------

    def  ChildAtRow(self, iRow):
        if iRow < 0 or iRow >= len( self.mChildren ):
            return  0
        else:
            return  self.mChildren[ iRow ]
    # --------------------------------

    def  ChildrenCount(self):
        return  len( self.mChildren )
    # --------------------------------

    def  IndexInParent(self):
        i = 0
        for item in self.mParent.mChildren:
            if item == self:
                return  i
            i = i+1

        return  -1
    # --------------------------------

                        # DATA     =================================
    def DataCount(self):
        return  1
    # --------------------------------



    # --------------------------------
    # --------------------------------
    # --------------------------------



class cCombattantNameNode(cDataItem):
    def __init__(self, iParent, iCombattant):
        super(cCombattantNameNode,self).__init__(iParent)
        self.mCombattant = iCombattant
    # --------------------------------

    def Data(self):
        return  self.mCombattant.mName
    # --------------------------------

    def SetData(self, iData):
        self.mCombattant.mName = iData
        return  True
    # --------------------------------



    # --------------------------------
    # --------------------------------
    # --------------------------------



class cCombattantWeaponNode(cDataItem):
    def __init__(self, iParent, iCombattant):
        super(cCombattantWeaponNode,self).__init__(iParent)
        self.mCombattant = iCombattant
    # --------------------------------

    def Data(self):
        return  self.mCombattant.mWeapon.mName
    # --------------------------------

    def SetData(self, iData):
        self.mCombattant.ChangeWeapon( iData )
        return  True
    # --------------------------------


    # --------------------------------
    # --------------------------------
    # --------------------------------



class cCombattantShieldNode(cDataItem):
    def __init__(self, iParent, iCombattant):
        super(cCombattantShieldNode,self).__init__(iParent)
        self.mCombattant = iCombattant
    # --------------------------------

    def Data(self):
        return  self.mCombattant.mShieldRating
    # --------------------------------

    def SetData(self, iData):
        self.mCombattant.mShieldRating = iData
        return  True
    # --------------------------------


    # --------------------------------
    # --------------------------------
    # --------------------------------




