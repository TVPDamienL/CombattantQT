#include "cDataItemModel.h"


cDataItemModel::~cDataItemModel()
{
}


cDataItemModel::cDataItemModel( QAbstractItemModel* iModel, cDataItem* iParent ) :
    tSuperClass( iParent ),
    mModel( iModel )
{
}


cDataItem *
cDataItemModel::Parent()
{
    return  tSuperClass::Parent();
}


const cDataItem *
cDataItemModel::Parent() const
{
    return  tSuperClass::Parent();
}


int
cDataItemModel::IndexInParent() const
{
    return  tSuperClass::IndexInParent();
}


std::string
cDataItemModel::Type() const
{
    return  "BasicModel";
}


QVariant
cDataItemModel::GetDataAtIndex( int iIndex )
{
    return  mModel->data( mModel->index( 0, iIndex, QModelIndex() ) );
}


bool
cDataItemModel::SetData( int iIndex, const QVariant & value )
{
    return  mModel->setData( mModel->index( 0, iIndex, QModelIndex() ), value );
}


int
cDataItemModel::DataCount() const
{
    return  mExposed ? mModel->columnCount( QModelIndex() ) : 0;
}


int
cDataItemModel::ChildrenCount() const
{
    return  mExposed ? mModel->rowCount( QModelIndex() ) : 0;
}


cDataItem*
cDataItemModel::ChildAtIndex( int iIndex )
{
    if( !mExposed )
        return  0;

    QModelIndex index = mModel->index( iIndex, 0, QModelIndex() );
    cDataItem* item = (cDataItem*)(index.internalPointer());

    return  item;
}


const cDataItem*
cDataItemModel::ChildAtIndex( int iIndex ) const
{
    if( !mExposed )
        return  0;

    QModelIndex index = mModel->index( iIndex, 0, QModelIndex() );
    const cDataItem* item = (const cDataItem*)(index.internalPointer());

    return  item;
}


bool
cDataItemModel::Exposed() const
{
    return  mExposed;
}


void
cDataItemModel::Exposed( bool iExposed )
{
    mExposed = iExposed;
}
