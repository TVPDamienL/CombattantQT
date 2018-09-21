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
    virtual  QVariant       data( const QModelIndex& iIndex, int iRole = Qt::DisplayRole )                          const   override;


public:
    void  BuildData() override;

public:
    cWeapon*  mWeapon;
};

