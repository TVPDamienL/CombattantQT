#include "combattantlistmodel.h"


#include "combattantmodel.h"
#include "combattant.h"


cCombattantListModel::~cCombattantListModel()
{
}


cCombattantListModel::cCombattantListModel( QVector< cCombattant* > iCombattantList, QObject* iParent ) :
    tSuperClass( iParent ),
    mCombattantList( iCombattantList )
{
    BuildData();
}


void
cCombattantListModel::BuildData()
{
    mRootItem = new cDataItem();
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    for( auto comb : mCombattantList )
        new  cDataItemModelCombattant( new cCombattantModel( comb ), mRootItem );
}


cCombattantModel*
cCombattantListModel::CombattantModelAtIndex( const QModelIndex & iIndex )
{
    auto modelNode = dynamic_cast< cDataItemModelCombattant* >( mRootItem->ChildAtIndex( iIndex.row() ) );
    return  dynamic_cast< cCombattantModel* >( modelNode->mModel );
}

