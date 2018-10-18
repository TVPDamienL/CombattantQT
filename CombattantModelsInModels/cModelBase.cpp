#include "cModelBase.h"

#include "cDataItemModel.h"



/*   MEMO

Le problème avec le fait que le model principal renvoie vers le sous model :
if( iIndex.isValid() && iIndex.model() != this )
    return  iIndex.model()->data( iIndex, iRole );


est que lorsqu'on cherche à l'afficher dans un treeView, les branches des sous modeles vont avoir height = 0 car modelPrincipal != modelIndex.model();
Il faut donc éviter, si on veut réutiliser les treeView, d'avoir le sous model qui créer les index





*/




cModelBase::~cModelBase()
{
    delete  mRootItem;
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

    // Crashtest
    childNode->DataCount();

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
    else if( theParent->Type() == "NodeRootModel" )
        theParent = theParent->Parent();

    if( theParent == nullptr )
        int bp = 9;

    return  createIndex( theParent->IndexInParent(), 0, theParent );
}


int
cModelBase::rowCount( const QModelIndex & iIndex ) const
{
    cDataItem* data = ExtractDataItemFromIndex( iIndex );
    return  data->ChildrenCount();

    return  0;
}


int
cModelBase::columnCount( const QModelIndex & iIndex ) const
{
    cDataItem* data = ExtractDataItemFromIndex( iIndex );
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
            //if( iIndex.column() == 0 )
            //    return  data->GetIcon();
            //break;
        }
        default :
            return  QVariant();
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


cDataItemModel*
cModelBase::AddModelNode( cModelBase * iModel, cDataItem * iParent )
{
    auto newModelNode = new cDataItemModel( iModel, this, iParent );
    newModelNode->Exposed( true );

    iModel->setParent( this );
    iModel->mRootItem->ParentModel( this );

    connect( iModel, &QAbstractItemModel::dataChanged, this, &cModelBase::ForceFullRefresh );

    return  newModelNode;
}


void
cModelBase::AddDataNode( cDataItem* iNode )
{
    iNode->ConnectToDataChanged( [ this ] ( cDataItem* iItem ) {

        QModelIndex topLeft = _GetIndexFromNodeAtColumn( iItem, 0 );
        QModelIndex bottomRigt = _GetIndexFromNodeAtColumn( iItem, iItem->DataCount() - 1 );
        emit  dataChanged( topLeft, bottomRigt );

    } );
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
cModelBase::DataItemToModelIndex( cDataItem* iDataItem ) const
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
cModelBase::ForceFullRefresh( const QModelIndex& Left, const QModelIndex& Right, const  QVector< int >& iRoles )
{
    auto item = ExtractDataItemFromIndex( Left );
    if( item )
    {
        auto itemModel = FindDataItemModelFromModel( item->OwnerModel() );
        QModelIndex index = DataItemToModelIndex( itemModel );
        QModelIndex indexC1 = index.siblingAtColumn( 1 );
        emit  dataChanged( index, index.siblingAtColumn( 1 ) );
    }
}


QModelIndex
cModelBase::RootIndex() const
{
    auto  parentAsModel = dynamic_cast< cModelBase* >( QObject::parent() );
    if( parentAsModel )
        return  index( 0, 0, QModelIndex() ).parent();
    else
        return  QModelIndex();
}


cDataItemModel*
cModelBase::FindDataItemModelFromModel( const cModelBase * iModel )
{
    for( int i = 0; i < mRootItem->ChildrenCount(); ++i )
    {
        auto modelItemNode = dynamic_cast< cDataItemModel* >( mRootItem->ChildAtIndex( i ) );
        if( modelItemNode && modelItemNode->mModel == iModel )
            return  modelItemNode;
    }

    return  0;
}


QModelIndex
cModelBase::_GetIndexFromNodeAtColumn( cDataItem* iItem, int iColumn )
{
    return  createIndex( iItem->IndexInParent(), iColumn, iItem );
}

