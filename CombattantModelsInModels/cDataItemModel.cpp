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
    return  mModel->data( mModel->index( 0, 0, QModelIndex() ) );
}


bool
cDataItemModel::SetData( int iIndex, const QVariant & value )
{
    if( iIndex == 0 )
        mModel->setData( mModel->index( 0, 0, QModelIndex() ), value );

    return  tSuperClass::SetData( iIndex, value );
}
