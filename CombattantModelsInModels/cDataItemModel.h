#pragma once

#include "cDataItem.h"

#include <QAbstractItemModel>

class cDataItemModel :
    public cDataItem
{
public:
    typedef  cDataItem tSuperClass;

public:
    ~cDataItemModel();
    cDataItemModel( QAbstractItemModel* iModel, cDataItem* iParent = 0 );

public:
    virtual  cDataItem*         Parent() override;
    virtual  const cDataItem*   Parent() const override;
    virtual  int                IndexInParent() const override;

    virtual  std::string        Type()                                          const   override;
    virtual  QVariant           GetDataAtIndex( int iIndex )                            override;
    virtual  bool               SetData( int iIndex, const QVariant & value )           override;

    virtual  int                DataCount() const override;
    virtual  int                ChildrenCount() const override;

    virtual  cDataItem*         ChildAtIndex( int iIndex ) override;
    virtual  const cDataItem*   ChildAtIndex( int iIndex ) const override;

public:
    bool  Exposed() const;
    void  Exposed( bool iExposed );

public: // dirty quickcoding
    QAbstractItemModel* mModel      = 0;
    bool                mExposed    = false;
};

