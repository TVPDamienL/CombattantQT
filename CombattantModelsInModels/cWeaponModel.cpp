#include "cWeaponModel.h"

#include "cDataItemWeapon.h"
#include "cDataItemModel.h"

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
    mRootItem = new cDataItemModelRoot( this );
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    if( mWeapon )
    {
        nodeName = new cDataItemWeapon( mWeapon, this, mRootItem );
        nodeName->AddData( "WeaponName" );
        AddDataNode( nodeName );

        nodeDmg = new cDataItemWeapon( mWeapon, this, mRootItem );
        nodeDmg->AddData( "WeaponDamage" );
        AddDataNode( nodeDmg );
    }
}


void
cWeaponModel::SetNewWeapon( cWeapon * iWeapon )
{
    mWeapon = iWeapon;
    nodeName->mWeapon = iWeapon;
    nodeDmg->mWeapon = iWeapon;
    emit dataChanged( index( 0, 0, QModelIndex() ), index( 1, 0, QModelIndex() ) );
}
