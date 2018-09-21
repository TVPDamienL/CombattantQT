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
