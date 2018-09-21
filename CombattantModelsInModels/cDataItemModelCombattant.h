#pragma once

#include "cDataItemModel.h"

#include "combattantmodel.h"

class cDataItemModelCombattant :
    public cDataItemModel
{
public:
    typedef  cDataItemModel tSuperClass;

public:
    virtual  ~cDataItemModelCombattant();
    cDataItemModelCombattant( cCombattantModel* iModel, cDataItem* iParent = 0 );

public:
    std::string     Type()                                          const   override;
    QVariant        GetDataAtIndex( int iIndex )                            override;
    bool            SetData( int iIndex, const QVariant & value )           override;
};

