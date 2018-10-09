class cWeapon:
    def __init__(self, iName, iDmg):
        self.mName = iName
        self.mDamage = iDmg


gAllWeapons = [ cWeapon( "Fist", 1 ), cWeapon( "Dagger", 2 ), cWeapon( "Sword", 4 ), cWeapon( "Pike", 8 ) ]


class cCombattant:
    def __init__(self, iName):
        self.mName = iName
        self.mWeapon = gAllWeapons[ 0 ]
        self.mShieldRating = 0
    # --------------------------------


    def ChangeWeapon(self, iWeaponName):
        for weapon in gAllWeapons:
            if weapon.mName == iWeaponName:
                self.mWeapon = weapon
    # --------------------------------

