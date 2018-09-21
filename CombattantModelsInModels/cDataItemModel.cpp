#include "cDataItemModel.h"


cDataItemModel::~cDataItemModel()
{
}


cDataItemModel::cDataItemModel( QAbstractItemModel* iModel, cDataItem* iParent ) :
    tSuperClass( iParent ),
    mModel( iModel )
{
}


std::string cDataItemModel::Type() const
{
    return  "BasicModel";
}

