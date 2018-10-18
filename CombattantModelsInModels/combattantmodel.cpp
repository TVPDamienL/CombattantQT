#include "combattantmodel.h"

#include "combattant.h"
#include "cDataItemCombattant.h"
#include "cDataItemWeapon.h"
#include "cDataItemModel.h"
#include "cWeaponModel.h"


cCombattantModel::~cCombattantModel()
{
}


cCombattantModel::cCombattantModel( cCombattant* iCombattant, QObject* iParent ) :
    tSuperClass( iParent ),
    mCombattant( iCombattant )
{
    BuildData();
}


bool
cCombattantModel::setData( const QModelIndex& iIndex, const QVariant& iData, int iRole )
{
    auto dataItem = dynamic_cast< cDataItemModel* >( ExtractDataItemFromIndex( iIndex ) );
    if( dataItem )
    {
        mCombattant->CurrentWeapon( iData.toString().toStdString() );

        auto weaponModel = dynamic_cast< cWeaponModel* >( mTheWeaponModelNode->mModel );
        weaponModel->SetNewWeapon( mCombattant->CurrentWeapon() );

        emit dataChanged( iIndex, iIndex );
        return  true;
    }

    return  tSuperClass::setData( iIndex, iData, iRole );
}


void
cCombattantModel::BuildData()
{
    mRootItem = new cDataItemModelRoot( this );
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    auto nameItem = new cDataItemCombattant( mCombattant, this, mRootItem );
    nameItem->AddData( "CombattantName" );
    AddDataNode( nameItem );

    mTheWeaponModelNode = AddModelNode( new  cWeaponModel( mCombattant->CurrentWeapon() ), mRootItem );

    auto shieldItem = new cDataItemCombattant( mCombattant, this, mRootItem );
    shieldItem->AddData( "CombattantShield" );
    AddDataNode( shieldItem );
}


cWeaponModel*
cCombattantModel::WeaponModel()
{
    return  dynamic_cast< cWeaponModel* >( mTheWeaponModelNode->mModel );
}


