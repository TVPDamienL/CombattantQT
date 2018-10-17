#pragma once

#include "cModelBase.h"

class cWeapon;
class cDataItemWeapon;

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

    void  SetNewWeapon( cWeapon* iWeapon );

public:
    cWeapon*  mWeapon;

    cDataItemWeapon* nodeName;
    cDataItemWeapon* nodeDmg;
};

