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


bool
cCombattantListModel::setData( const QModelIndex& iIndex, const QVariant& iData, int iRole )
{
    bool result = tSuperClass::setData( iIndex, iData, iRole );
    if( !result )
        return  false;

    // If we change the model node, which displays and allow edition of combattant's name, which isn't the best in a tree thing,
    // we need to inform the node name within combat model it changed, so we do just that here
    auto item = ExtractDataItemFromIndex( iIndex );
    auto itemCombattantModel = dynamic_cast< cDataItemModel* >( item );
    if( itemCombattantModel )
    {
        auto combattantModel = itemCombattantModel->mModel;
        combattantModel->dataChanged( combattantModel->index( 0, 0, QModelIndex() ), combattantModel->index( 0, 1, QModelIndex() ) );
    }

    return  result;
}


cCombattantModel*
cCombattantListModel::CombattantModelAtIndex( const QModelIndex& iIndex )
{
    return  dynamic_cast< cCombattantModel* >( ExtractModelFromIndex( iIndex ) );
}

