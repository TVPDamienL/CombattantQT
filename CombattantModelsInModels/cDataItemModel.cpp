#include "cDataItemModel.h"

#include "cModelBase.h"



cDataItemModel::~cDataItemModel()
{
}


cDataItemModel::cDataItemModel( cModelBase* iModel, cModelBase* iOwnerModel, cDataItem* iParent ) :
    tSuperClass( iOwnerModel, iParent ),
    mModel( iModel )
{
}


cDataItem *
cDataItemModel::Parent()
{
    // Transition is done on a model's rootitem
    return  tSuperClass::Parent(); // A model node is children from a standard node
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






cDataItemModelRoot::~cDataItemModelRoot()
{
}

cDataItemModelRoot::cDataItemModelRoot( cModelBase * iModel, cDataItem * iParent ) :
    cDataItem( iModel, iParent )
{
}


std::string
cDataItemModelRoot::Type() const
{
    return  "NodeRootModel";
}


cDataItem*
cDataItemModelRoot::Parent()
{
    if( mParentModel )
        return  mParentModel->FindDataItemModelFromModel( mOwnerModel );

    return  0;
}

const cDataItem * cDataItemModelRoot::Parent() const
{
    if( mParentModel )
        return  mParentModel->FindDataItemModelFromModel( mOwnerModel );

    return  0;
}


void
cDataItemModelRoot::ParentModel( cModelBase * iModel )
{
    mParentModel = iModel;
}
