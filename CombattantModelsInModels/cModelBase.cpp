#include "cModelBase.h"



cModelBase::~cModelBase()
{
}


cModelBase::cModelBase( QObject* iParent ) :
    tSuperClass( iParent ),
    mRootItem( 0 )
{
}


QModelIndex
cModelBase::index( int iRow, int iColumn, const QModelIndex & iParent ) const
{
    if( iParent.isValid() && iParent.column() != 0 )
        return  QModelIndex();

    cDataItem* theNode = ExtractDataItemFromIndex( iParent );
    cDataItem* childNode = theNode->ChildAtIndex( iRow );
    if( childNode )
        return  createIndex( iRow, iColumn, childNode );

    return  QModelIndex();

}


QModelIndex
cModelBase::parent( const QModelIndex & iParent ) const
{
    if( !iParent.isValid() )
        return  QModelIndex();

    cDataItem* theNode = ExtractDataItemFromIndex( iParent );
    cDataItem* theParent = theNode->Parent();

    if( theParent == mRootItem )
        return  QModelIndex();


    return  createIndex( theNode->IndexInParent(), 0, theParent );
}


int
cModelBase::rowCount( const QModelIndex & iIndex ) const
{
    cDataItem* data = ExtractDataItemFromIndex( iIndex );
    if( data )
        return  data->ChildrenCount();

    return  0;
}


int
cModelBase::columnCount( const QModelIndex & iIndex ) const
{
    cDataItem* data = ExtractDataItemFromIndex( iIndex );
    if( data )
        return  data->DataCount();

    return  0;
}


QVariant
cModelBase::data( const QModelIndex & iIndex, int iRole ) const
{
    if( !iIndex.isValid() )
        QVariant();

    cDataItem* data = ExtractDataItemFromIndex( iIndex );

    if( !data )
        return  QVariant();

    switch( iRole )
    {
        case  Qt::DisplayRole:
        case  Qt::EditRole:
        {
            return  data->GetDataAtIndex( iIndex.column() );
        }
        case  Qt::ToolTipRole:
        {
            return  data->GetToolTip();
        }
        case  Qt::DecorationRole:
        {
            if( iIndex.column() == 0 )
                return  data->GetIcon();
            break;
        }
    }

    return  QVariant();
}


QVariant
cModelBase::headerData( int iSection, Qt::Orientation iOrientation, int iRole ) const
{
    if( iOrientation == Qt::Horizontal && iRole == Qt::DisplayRole )
        return  mRootItem->GetDataAtIndex( iSection );

    return  QVariant();
}


bool
cModelBase::setData( const QModelIndex & iIndex, const QVariant & iData, int iRole )
{
    if( iRole != Qt::EditRole )
        return  false;

    cDataItem*  item = ExtractDataItemFromIndex( iIndex );
    bool  result = item->SetData( iIndex.column(), iData );
    if( result )
        emit dataChanged( iIndex, iIndex );

    return  result;
}


Qt::ItemFlags
cModelBase::flags( const QModelIndex & iIndex ) const
{
    if( !iIndex.isValid() )
        return  0;

    return  tSuperClass::flags( iIndex ) | Qt::ItemIsEditable;
}


void
cModelBase::BuildData()
{
    // nothing
}


cDataItem*
cModelBase::ExtractDataItemFromIndex( const QModelIndex & iIndex ) const
{
    if( iIndex == QModelIndex() )
        return  mRootItem;

    auto data = (cDataItem*)iIndex.internalPointer();
    if( data )
        return  data;

    return  0;
}

