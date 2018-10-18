#include "cDataItemWeapon.h"

#include "combattant.h"

cDataItemWeapon::~cDataItemWeapon()
{
}


cDataItemWeapon::cDataItemWeapon( cWeapon* iWeapon, cModelBase* iModel, cDataItem* iParent ) :
    tSuperClass( iModel, iParent ),
    mWeapon( iWeapon )
{
}


QVariant
cDataItemWeapon::GetDataAtIndex( int iIndex )
{
    if( mWeapon && mData[ 0 ] == "WeaponName" )
        return  QString( mWeapon->Name().c_str() );
    else if( mWeapon && mData[ 0 ] == "WeaponDamage" )
        return  mWeapon->Damage();

    return tSuperClass::GetDataAtIndex( iIndex );
}


bool
cDataItemWeapon::SetData( int iIndex, const QVariant & value )
{
    if( mWeapon && mData[ 0 ] == "WeaponName" )
    {
        mWeapon->Name( value.toString().toStdString() );
        _DataChanged( this );
        return  true;
    }
    else if( mWeapon && mData[ 0 ] == "WeaponDamage" )
    {
        mWeapon->Damage( value.toInt() );
        _DataChanged( this );
        return  true;
    }

    return  tSuperClass::SetData( iIndex, value );
}
