#include "cDataItemModelCombattant.h"



cDataItemModelCombattant::~cDataItemModelCombattant()
{
}


cDataItemModelCombattant::cDataItemModelCombattant( cCombattantModel* iModel, cDataItem* iParent ) :
    tSuperClass( iModel, iParent )
{
    AddData( iModel->data( iModel->index( 0, 0, QModelIndex() ) ) );
    AddData( "" );
}


std::string
cDataItemModelCombattant::Type() const
{
    return  "CombattantModel";
}


QVariant
cDataItemModelCombattant::GetDataAtIndex( int iIndex )
{
    return  mModel->data( mModel->index( 0, 0, QModelIndex() ) );
}


bool
cDataItemModelCombattant::SetData( int iIndex, const QVariant & value )
{
    if( iIndex == 0 )
        mModel->setData( mModel->index( 0, 0, QModelIndex() ), value );

    return  tSuperClass::SetData( iIndex, value );
}
