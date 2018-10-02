#include "cModelBase.h"

#include "cDataItemModel.h"


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

    if( iParent.isValid() && iParent.model() != this )
        return  iParent.model()->index( iRow, iColumn, iParent );

    cDataItem* theNode = ExtractDataItemFromIndex( iParent );
    cDataItem* childNode = theNode->ChildAtIndex( iRow );

    // If the child node is a model node, and that model is exposed, we go to the model
    auto  itemAsDataModel = dynamic_cast< cDataItemModel* >( theNode );
    if( itemAsDataModel && itemAsDataModel->Exposed() )
        return  itemAsDataModel->mModel->index( iRow, iColumn, QModelIndex() );

    // Otherwise, we use the usual children
    if( childNode )
        return  createIndex( iRow, iColumn, childNode );

    return  QModelIndex();
}


QModelIndex
cModelBase::parent( const QModelIndex & iParent ) const
{
    if( !iParent.isValid() )
        return  QModelIndex();

    if( iParent.isValid() && iParent.model() != this )
        return  iParent.model()->parent( iParent );

    cDataItem* theNode = ExtractDataItemFromIndex( iParent );
    cDataItem* theParent = theNode->Parent();
    if( theParent == mRootItem )
    {
        auto  parentAsModel = dynamic_cast< cModelBase* >( QObject::parent() );
        if( parentAsModel )
        {
            cDataItemModel* parentModelNode = parentAsModel->_FindDataItemModelFromModel( this );
            if( parentModelNode && parentModelNode->Exposed() )
                return  parentAsModel->DataItemToModelIndex( parentModelNode );
        }

        return  QModelIndex();
    }

    return  createIndex( theNode->IndexInParent(), 0, theParent );
}


int
cModelBase::rowCount( const QModelIndex & iIndex ) const
{
    if( iIndex.isValid() && iIndex.model() != this )
        return  iIndex.model()->rowCount( iIndex );

    cDataItem* data = ExtractDataItemFromIndex( iIndex );
    return  data->ChildrenCount();

    return  0;
}


int
cModelBase::columnCount( const QModelIndex & iIndex ) const
{
    if( iIndex.isValid() && iIndex.model() != this )
        return  iIndex.model()->columnCount( iIndex );

    cDataItem* data = ExtractDataItemFromIndex( iIndex );
    return  data->DataCount();

    return  0;
}


QVariant
cModelBase::data( const QModelIndex & iIndex, int iRole ) const
{
    if( !iIndex.isValid() )
        QVariant();

    if( iIndex.isValid() && iIndex.model() != this )
        return  iIndex.model()->data( iIndex, iRole );

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

    if( iIndex.isValid() && iIndex.model() != this )
    {
        auto themodel = const_cast< QAbstractItemModel* >( iIndex.model() );
        return  themodel->setData( iIndex, iData, iRole );
    }

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

    if( iIndex.isValid() && iIndex.model() != this )
        return  iIndex.model()->flags( iIndex );

    return  tSuperClass::flags( iIndex ) | Qt::ItemIsEditable;
}


cDataItemModel *
cModelBase::AddModelNode( QAbstractItemModel * iModel, cDataItem * iParent )
{
    auto newModelNode = new cDataItemModel( iModel, iParent );
    newModelNode->Exposed( true );
    iModel->setParent( this );

    connect( iModel, &QAbstractItemModel::dataChanged, this, &cModelBase::ForceFullRefresh );

    return  newModelNode;
}


cDataItem*
cModelBase::AddDataNode( cDataItem * iParent )
{
    return  new cDataItem( iParent );
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


QModelIndex
cModelBase::DataItemToModelIndex( cDataItem * iDataItem ) const
{
    return  createIndex( iDataItem->IndexInParent(), 0, iDataItem );
}


QAbstractItemModel*
cModelBase::ExtractModelFromIndex( const QModelIndex & iIndex ) const
{
    return  ExtractModelFromIndex( iIndex.row() );
}


QAbstractItemModel*
cModelBase::ExtractModelFromIndex( int iIndex ) const
{
    auto modelNode = dynamic_cast< cDataItemModel* >( mRootItem->ChildAtIndex( iIndex ) );
    if( modelNode )
        return  modelNode->mModel;

    return  0;
}


void
cModelBase::ForceFullRefresh()
{
    dataChanged( QModelIndex(), QModelIndex() );
}


cDataItemModel*
cModelBase::_FindDataItemModelFromModel( const cModelBase * iModel )
{
    for( int i = 0; i < mRootItem->ChildrenCount(); ++i )
    {
        auto modelItemNode = dynamic_cast< cDataItemModel* >( mRootItem->ChildAtIndex( i ) );
        if( modelItemNode && modelItemNode->mModel == iModel )
            return  modelItemNode;
    }

    return  0;
}

