#include "cDataItemModelWeapon.h"


cDataItemModelWeapon::~cDataItemModelWeapon()
{
}


cDataItemModelWeapon::cDataItemModelWeapon( cWeaponModel* iModel, cDataItem* iParent ) :
    tSuperClass( iModel, iParent )
{
    AddData( iModel->data( iModel->index( 0, 0, QModelIndex() ) ) );
    AddData( "" );
}


std::string
cDataItemModelWeapon::Type() const
{
    return  "WeaponModel";
}


QVariant
cDataItemModelWeapon::GetDataAtIndex( int iIndex )
{
    return  mModel->data( mModel->index( 0, 0, QModelIndex() ) );
}


bool
cDataItemModelWeapon::SetData( int iIndex, const QVariant & value )
{
    if( iIndex == 0 )
        mModel->setData( mModel->index( 0, 0, QModelIndex() ), value );

    return  tSuperClass::SetData( iIndex, value );
}