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

        delete  mTheWeaponModelNode->mModel;
        mTheWeaponModelNode->mModel = new  cWeaponModel( mCombattant->CurrentWeapon() );
        emit dataChanged( iIndex, iIndex );
        return  true;
    }

    return  tSuperClass::setData( iIndex, iData, iRole );
}


void
cCombattantModel::BuildData()
{
    mRootItem = new cDataItem();
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    auto nameItem = new cDataItemCombattant( mCombattant, mRootItem );
    nameItem->AddData( "CombattantName" );

    mTheWeaponModelNode = AddModelNode( new  cWeaponModel( mCombattant->CurrentWeapon() ), mRootItem );

    auto shieldItem = new cDataItemCombattant( mCombattant, mRootItem );
    shieldItem->AddData( "CombattantShield" );
}


cWeaponModel*
cCombattantModel::WeaponModelAtIndex( const QModelIndex & iIndex )
{
    auto modelNode = dynamic_cast< cDataItemModel* >( mRootItem->ChildAtIndex( iIndex.row() ) );
    return  dynamic_cast< cWeaponModel* >( modelNode->mModel );
}


