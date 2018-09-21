#include "cDataItemModel.h"


cDataItemModel::~cDataItemModel()
{
}


cDataItemModel::cDataItemModel( QAbstractItemModel* iModel, cDataItem* iParent ) :
    tSuperClass( iParent ),
    mModel( iModel )
{
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
    // This ?
    return  mModel->setData( mModel->index( 0, iIndex, QModelIndex() ), value );
}
