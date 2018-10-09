#pragma once

#include "cModelBase.h"

class cWeapon;

class cWeaponModel :
    public cModelBase
{
public :
    typedef cModelBase tSuperClass;

public:
    ~cWeaponModel();
    cWeaponModel( cWeapon* iWeapon, QObject* iParent = 0 );

public:
    void  BuildData() override;

public:
    cWeapon*  mWeapon;
};

