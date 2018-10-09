#include "cProxyFilterSortBase.h"

#include "cDataItemModel.h"
#include "cModelBase.h"


cProxyFilterSortBase::~cProxyFilterSortBase()
{
}


cProxyFilterSortBase::cProxyFilterSortBase( QObject* iParent ) :
    tSuperClass( iParent )
{
}


QModelIndex
cProxyFilterSortBase::index( int iRow, int iColumn, const QModelIndex & iParent ) const
{
    if( iParent.isValid() && iParent.column() != 0 )
        return  QModelIndex();

    cDataItem* theNode = ExtractDataItemFromIndex( iParent );
    cDataItem* childNode = theNode->ChildAtIndex( iRow );

    // Otherwise, we use the usual children
    if( childNode )
        return  createIndex( iRow, iColumn, childNode );

    return  QModelIndex();
}


QModelIndex
cProxyFilterSortBase::parent( const QModelIndex & iParent ) const
{
    //if( !iParent.isValid() )
    //    return  QModelIndex();

    //cDataItem* theNode = ExtractDataItemFromIndex( iParent );
    //cDataItem* theParent = theNode->Parent();

    //if( theParent == mRootItem )
    //    return  QModelIndex();

    //return  createIndex( theNode->IndexInParent(), 0, theParent );
    return  QModelIndex();
}


cDataItem*
cProxyFilterSortBase::ExtractDataItemFromIndex( const QModelIndex & iIndex ) const
{
    auto parentAsProxy = dynamic_cast< cProxyFilterSortBase* >( sourceModel() );
    if( parentAsProxy )
        return  parentAsProxy->ExtractDataItemFromIndex( mapToSource( iIndex ) );

    auto parentAsModelBase = dynamic_cast< cModelBase* >( sourceModel() );
    if( parentAsModelBase )
        return  parentAsModelBase->ExtractDataItemFromIndex( mapToSource( iIndex ) );

    return  0;
}

