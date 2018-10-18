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
    mRootItem = new cDataItemModelRoot( this, 0 );
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    //for( auto comb : mCombattantList )
    //    AddModelNode( new cCombattantModel( comb ), mRootItem );

    auto modelDoublon = new cCombattantModel( mCombattantList[ 0 ] );
    AddModelNode( modelDoublon, mRootItem );
    AddModelNode( modelDoublon, mRootItem );
    AddModelNode( new cCombattantModel( mCombattantList[ 1 ] ), mRootItem );
}


cCombattantModel*
cCombattantListModel::CombattantModelAtIndex( const QModelIndex& iIndex )
{
    return  dynamic_cast< cCombattantModel* >( ExtractModelFromIndex( iIndex ) );
}

