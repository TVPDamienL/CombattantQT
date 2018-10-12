#pragma once

#include "cDataItem.h"

class cWeapon;

class cDataItemWeaponBase :
    public cDataItem
{
public:
    typedef  cDataItem tSuperClass;

public:
    ~cDataItemWeaponBase();
    cDataItemWeaponBase( cWeapon* iWeapon, cDataItem* iParent = 0 );

    int                DataCount() const override;

public:
    cWeapon*    Weapon();
    void        Weapon( cWeapon* Weapon );


public: // dirty quickcoding
    cWeapon* mWeapon;
};

// =========

class cDataItemWeaponBaseNode :
    public cDataItemWeaponBase
{
public:
    typedef  cDataItemWeaponBase tSuperClass;

public:
    ~cDataItemWeaponBaseNode();
    cDataItemWeaponBaseNode( cWeapon* iWeapon, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;

public:
    void  Weapon( cWeapon* Weapon );
};

// =========

class cDataItemWeaponName :
    public cDataItemWeaponBase
{
public:
    typedef  cDataItemWeaponBase tSuperClass;

public:
    ~cDataItemWeaponName();
    cDataItemWeaponName( cWeapon* iWeapon, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;
};



// =========

class cDataItemWeaponDamage :
    public cDataItemWeaponBase
{
public:
    typedef  cDataItemWeaponBase tSuperClass;

public:
    ~cDataItemWeaponDamage();
    cDataItemWeaponDamage( cWeapon* iWeapon, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;
};




