#pragma once

#include "cDataItem.h"

class cCombattant;

class cDataItemCombattant :
    public cDataItem
{
public:
    typedef  cDataItem tSuperClass;

public:
    ~cDataItemCombattant();
    cDataItemCombattant( cCombattant* iCombattant, cModelBase* iModel, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;


private:
    cCombattant* mCombattant;
};

