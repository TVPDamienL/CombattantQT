#pragma once

#include "cDataItemModel.h"

#include "cWeaponModel.h"

class cDataItemModelWeapon :
    public cDataItemModel
{
public:
    typedef  cDataItemModel tSuperClass;

public:
    virtual  ~cDataItemModelWeapon();
    cDataItemModelWeapon( cWeaponModel* iModel, cDataItem* iParent = 0 );

public:
    std::string     Type()                                          const   override;
    QVariant        GetDataAtIndex( int iIndex )                            override;
    bool            SetData( int iIndex, const QVariant & value )           override;
};

