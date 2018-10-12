#pragma once

#include "cDataItem.h"

class cCombattant;

class cDataItemCombattantBase :
    public cDataItem
{
public:
    typedef  cDataItem tSuperClass;

public:
    ~cDataItemCombattantBase();
    cDataItemCombattantBase( cCombattant* iCombattant, cDataItem* iParent = 0 );

    int             DataCount() const override;
    cCombattant*    Combattant();

protected:
    cCombattant* mCombattant;
};

// ==========

class cDataItemCombattantBaseNode :
    public cDataItemCombattantBase
{
public:
    typedef  cDataItemCombattantBase tSuperClass;

public:
    ~cDataItemCombattantBaseNode();
    cDataItemCombattantBaseNode( cCombattant* iCombattant, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;
};

// ==========

class cDataItemCombattantName :
    public cDataItemCombattantBase
{
public:
    typedef  cDataItemCombattantBase tSuperClass;

public:
    ~cDataItemCombattantName();
    cDataItemCombattantName( cCombattant* iCombattant, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;
};

// ==========


class cDataItemCombattantShield :
    public cDataItemCombattantBase
{
public:
    typedef  cDataItemCombattantBase tSuperClass;

public:
    ~cDataItemCombattantShield();
    cDataItemCombattantShield( cCombattant* iCombattant, cDataItem* iParent = 0 );

public:
    virtual  QVariant   GetDataAtIndex( int iIndex ) override;
    virtual  bool       SetData( int iIndex, const QVariant &value ) override;
};





