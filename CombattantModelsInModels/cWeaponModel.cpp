#include "cWeaponModel.h"

#include "cDataItemWeapon.h"

cWeaponModel::~cWeaponModel()
{
}


cWeaponModel::cWeaponModel( cWeapon* iWeapon, QObject* iParent ) :
    tSuperClass( iParent ),
    mWeapon( iWeapon )
{
    BuildData();
}


QVariant
cWeaponModel::data( const QModelIndex & iIndex, int iRole ) const
{
    auto  dataItem = dynamic_cast< cDataItemWeapon* >( ExtractDataItemFromIndex( iIndex ) );
    if( dataItem && dataItem->mWeapon == 0 )
        return  "None";

    return  tSuperClass::data( iIndex, iRole );
}


void
cWeaponModel::BuildData()
{
    mRootItem = new cDataItem();
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    auto nameItem = new cDataItemWeapon( mWeapon, mRootItem );
    nameItem->AddData( "WeaponName" );

    auto damageItem = new cDataItemWeapon( mWeapon, mRootItem );
    damageItem->AddData( "WeaponDamage" );
}
