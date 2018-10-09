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


void
cWeaponModel::BuildData()
{
    mRootItem = new cDataItem();
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    if( mWeapon )
    {
        auto nameItem = new cDataItemWeapon( mWeapon, mRootItem );
        nameItem->AddData( "WeaponName" );

        auto damageItem = new cDataItemWeapon( mWeapon, mRootItem );
        damageItem->AddData( "WeaponDamage" );

    }
}
