#include "cDataItemWeapon.h"

#include "combattant.h"

cDataItemWeaponBase::~cDataItemWeaponBase()
{
}


cDataItemWeaponBase::cDataItemWeaponBase( cWeapon* iWeapon, cDataItem* iParent ) :
    tSuperClass( iParent ),
    mWeapon( iWeapon )
{
}


int
cDataItemWeaponBase::DataCount() const
{
    return  2;
}


cWeapon*
cDataItemWeaponBase::Weapon()
{
    return  mWeapon;
}


void
cDataItemWeaponBase::Weapon( cWeapon * iWeapon )
{
    mWeapon = iWeapon;
}


// ==============
// ==============
// ==============



cDataItemWeaponBaseNode::~cDataItemWeaponBaseNode()
{
}


cDataItemWeaponBaseNode::cDataItemWeaponBaseNode( cWeapon* iWeapon, cDataItem* iParent ) :
    tSuperClass( iWeapon, iParent )
{
}


QVariant
cDataItemWeaponBaseNode::GetDataAtIndex( int iIndex )
{
    if( iIndex == 0 )
        return  "Weapon";
}


bool
cDataItemWeaponBaseNode::SetData( int iIndex, const QVariant & value )
{
    if( iIndex != 1 )
        return  false;
    return  true;
}


// ==============
// ==============
// ==============



cDataItemWeaponName::~cDataItemWeaponName()
{
}


cDataItemWeaponName::cDataItemWeaponName( cWeapon* iWeapon, cDataItem* iParent ) :
    tSuperClass( iWeapon, iParent )
{
}


QVariant
cDataItemWeaponName::GetDataAtIndex( int iIndex )
{
    if( iIndex == 0 )
        return  "Name";

    return  QString( mWeapon->Name().c_str() );
}


bool
cDataItemWeaponName::SetData( int iIndex, const QVariant & value )
{
    mWeapon->Name( value.toString().toStdString() );
    return  true;
}


// ==============
// ==============
// ==============



cDataItemWeaponDamage::~cDataItemWeaponDamage()
{
}


cDataItemWeaponDamage::cDataItemWeaponDamage( cWeapon* iWeapon, cDataItem* iParent ) :
    tSuperClass( iWeapon, iParent )
{
}


QVariant
cDataItemWeaponDamage::GetDataAtIndex( int iIndex )
{
    if( iIndex == 0 )
        return  "Damage";

    return  mWeapon->Damage();
}


bool
cDataItemWeaponDamage::SetData( int iIndex, const QVariant & value )
{
    mWeapon->Damage( value.toInt() );
    return  true;
}


