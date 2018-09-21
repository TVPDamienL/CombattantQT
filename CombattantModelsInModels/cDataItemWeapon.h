#pragma once

#include "cDataItem.h"

class cWeapon;

class cDataItemWeapon :
    public cDataItem
{
public:
    typedef  cDataItem tSuperClass;

public:
    ~cDataItemWeapon();
    cDataItemWeapon( cWeapon* iWeapon, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;


public: // dirty quickcoding
    cWeapon* mWeapon;
};

